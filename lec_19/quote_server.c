/*
 *           quote_server.c: gives a quotation to clients
 *                           after receiving a message
 *
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
#include <syslog.h>
#include <unistd.h>

#define QUOTE_SERVER_PORT "4356"
#define BACKLOG 10
#define MAX_MESSAGE_SIZE 256
#define QUOTATION_PLEASE 1
#define YOUR_QUOTATION_PLEASE 2
#define QUIT 0

#define MAX_CLIENTS 200

typedef enum
{
    false,
    true
} bool;

void error(char *msg);
void *handle_client(void *arg);

// struct for passing data to client handling thread
struct client_info
{
    bool is_a_client;
    pthread_t tid;
    int accepted_sock_id;
    struct sockaddr_storage client;
};

struct client_info clients[MAX_CLIENTS];

struct message
{
    long message_id;
    char buffer[MAX_MESSAGE_SIZE];
};

static char *quote[] = {
    "A meeting is an event at which minutes are kept and hours are lost.",
    "The best time to plant a tree was twenty years ago. The second best time is now.",
    "When all efforts fail, read the instructions.",
    "An expert is the one who predicts that the job will take the longest and cost the most.",
    "An expert is one who knows more and more about less and less until he knows absolutely everything about nothing.",
    "They said I was gullible and I believed them.",
    "Confidence is the feeling you have before you fully understand the situation.",
    "With word processing, any idea can be right justified, even those which can not be justified on any other ground.",
    "Ever since we had the stress management program, the production has been slipping and no one is bothered.",
    "Self deprecating humor can be disastrous if people miss the humor in it.",
    "To a quick question, give a slow answer."};

const int num_quotes = sizeof(quote) / sizeof(char *);

pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char **argv)
{
    const char *const ident = "quote_server";
    pthread_attr_t thread_attr;

    for (int i = 0; i < MAX_CLIENTS; i++)
        clients[i].is_a_client = false;

    openlog(ident, LOG_CONS | LOG_PID | LOG_PERROR, LOG_USER);
    syslog(LOG_USER | LOG_INFO, "%s", "Hello world!");

    if (pthread_attr_init(&thread_attr) != 0)
        error("pthread_attr_init");
    if (pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED) != 0)
        error("pthread_attr_setdetachstate");

    time_t now;

    if ((now = time(NULL)) == ((time_t)-1))
        error("time");

    unsigned int seed = now % 47;

    srand(seed);

    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;     /* allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM; /* Stream socket */
    hints.ai_flags = AI_PASSIVE;     /* for wildcard IP address */

    struct addrinfo *result;
    int s;
    if ((s = getaddrinfo(NULL, QUOTE_SERVER_PORT, &hints, &result)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    /* Scan through the list of address structures returned by
       getaddrinfo. Stop when the the socket and bind calls are successful. */

    int sock_fd, optval = 1;
    socklen_t length;
    struct addrinfo *rptr;
    for (rptr = result; rptr != NULL; rptr = rptr->ai_next)
    {
        sock_fd = socket(rptr->ai_family, rptr->ai_socktype,
                         rptr->ai_protocol);
        if (sock_fd == -1)
            continue;

        if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1)
            error("setsockopt");

        if (bind(sock_fd, rptr->ai_addr, rptr->ai_addrlen) == 0) // Success
            break;

        if (close(sock_fd) == -1)
            error("close");
    }

    if (rptr == NULL)
    { // Not successful with any address
        fprintf(stderr, "Not able to bind\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    // Mark socket for accepting incoming connections using accept
    if (listen(sock_fd, BACKLOG) == -1)
        error("listen");

    socklen_t addrlen;
    int i, r;

    while (1)
    {
        addrlen = sizeof(struct sockaddr_storage);

        // find an empty slot for client

        // lock mutex
        if ((r = pthread_mutex_lock(&client_mutex)) != 0)
        {
            fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
            exit(1);
        }

        for (i = 0; i < MAX_CLIENTS; i++)
        {
            if (!clients[i].is_a_client)
                clients[i].is_a_client = true;
            break;
        }

        // Unlock mutex
        if ((r = pthread_mutex_unlock(&client_mutex)) != 0)
        {
            fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
            exit(1);
        }

        if (i == MAX_CLIENTS)
        {
            fprintf(stderr, "Can't handle more than %d clients. Quitting\n", MAX_CLIENTS);
            exit(EXIT_FAILURE);
        }

        if ((clients[i].accepted_sock_id = accept(sock_fd, (struct sockaddr *)&clients[i].client, &addrlen)) == -1)
        {
            if (errno == EINTR)
            {

                // lock mutex
                if ((r = pthread_mutex_lock(&client_mutex)) != 0)
                {
                    fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
                    exit(1);
                }

                clients[i].is_a_client = false;

                // Unlock mutex
                if ((r = pthread_mutex_unlock(&client_mutex)) != 0)
                {
                    fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
                    exit(1);
                }

                continue;
            }
            else
            {
                error("accept");
            }
        }

        if ((r = pthread_create(&clients[i].tid, NULL, handle_client, (void *)&i)) != 0)
        {
            fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
            exit(1);
        }
    }
    syslog(LOG_USER | LOG_INFO, "%s", "Bye.");
    closelog();

    exit(EXIT_SUCCESS);
}

void *handle_client(void *arg)
{
    struct client_info this_client;
    char str[INET6_ADDRSTRLEN];
    struct message send_message, recv_message;
    bool over = false;
    struct sockaddr_in *ptr;
    struct sockaddr_in6 *ptr1;
    int r, i;

    i = *((int *)arg);

    // lock mutex
    if ((r = pthread_mutex_lock(&client_mutex)) != 0)
    {
        fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
        exit(1);
    }

    this_client = clients[i];

    // Unlock mutex
    if ((r = pthread_mutex_unlock(&client_mutex)) != 0)
    {
        fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
        exit(1);
    }

    // print IP address of the client

    if ((this_client.client).ss_family == AF_INET)
    {
        ptr = (struct sockaddr_in *)&(this_client.client);
        inet_ntop(AF_INET, &(ptr->sin_addr), str, sizeof(str));
    }
    else if ((this_client.client).ss_family == AF_INET6)
    {
        ptr1 = (struct sockaddr_in6 *)&(this_client.client);
        inet_ntop(AF_INET6, &(ptr1->sin6_addr), str, sizeof(str));
    }
    else
    {
        ptr = NULL;
        fprintf(stderr, "Address family is neither AF_INET nor AF_INET6\n");
    }

    if (ptr)
        syslog(LOG_USER | LOG_INFO, "%s %s", "Connection from client", str);

    // Handle client messages
    while (!over)
    {
        // receive message
        if (recv(this_client.accepted_sock_id, &recv_message, sizeof(struct message), 0) <= 0)
        {
            over = true;

            // lock mutex
            if ((r = pthread_mutex_lock(&client_mutex)) != 0)
            {
                fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
                exit(1);
            }

            clients[i].is_a_client = false;

            // Unlock mutex
            if ((r = pthread_mutex_unlock(&client_mutex)) != 0)
            {
                fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
                exit(1);
            }

            break;
        }

        // process
        switch (ntohl(recv_message.message_id))
        {
        case QUOTATION_PLEASE: // choose a quote
            send_message.message_id = htonl(YOUR_QUOTATION_PLEASE);
            int i = rand() % num_quotes;
            strcpy(send_message.buffer, quote[i]);
            size_t msg_len = sizeof(long) + strlen(quote[i]) + 1;
            if (send(this_client.accepted_sock_id, &send_message, msg_len, 0) == -1)
                error("send");
            break;
        case QUIT:
            over = true;

            // lock mutex
            if ((r = pthread_mutex_lock(&client_mutex)) != 0)
            {
                fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
                exit(1);
            }

            clients[i].is_a_client = false;

            // Unlock mutex
            if ((r = pthread_mutex_unlock(&client_mutex)) != 0)
            {
                fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
                exit(1);
            }

            continue;
        }
    }

    return (NULL);
}

void error(char *msg)
{
    perror(msg);
    exit(1);
}