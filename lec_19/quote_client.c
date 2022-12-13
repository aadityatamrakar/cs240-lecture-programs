/*
 *           client.c : get a quotation from server
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
#include <errno.h>
#include <unistd.h>

#define QUOTE_SERVER_PORT "4356"
#define MAX_MESSAGE_SIZE 256
#define QUOTATION_PLEASE 1
#define YOUR_QUOTATION_PLEASE 2
#define QUIT 0

typedef enum
{
    false,
    true
} bool;

int get_option();
void error(char *msg);

struct message
{
    long message_id;
    char buffer[MAX_MESSAGE_SIZE];
};

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: client hostname\n");
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *result;
    int s;
    if ((s = getaddrinfo(argv[1], QUOTE_SERVER_PORT, &hints, &result)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    /* Scan through the list of address structures returned by
       getaddrinfo. Stop when the the socket and connect calls are successful. */

    int sock_fd;
    socklen_t length;
    struct addrinfo *rptr;
    for (rptr = result; rptr != NULL; rptr = rptr->ai_next)
    {
        sock_fd = socket(rptr->ai_family, rptr->ai_socktype,
                         rptr->ai_protocol);
        if (sock_fd == -1)
            continue;

        if (connect(sock_fd, rptr->ai_addr, rptr->ai_addrlen) == -1)
        {
            if (close(sock_fd) == -1)
                error("close");
            continue;
        }

        break;
    }

    if (rptr == NULL)
    { // Not successful with any address
        fprintf(stderr, "Not able to connect\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    int option;
    struct message message;

    while (1)
    {
        option = get_option();
        // send request to server
        message.message_id = htonl(option);
        if (send(sock_fd, &message, sizeof(long), MSG_NOSIGNAL) == -1)
            error("send");

        if (option == QUIT)
            break;

        // receive response from server
        if (recv(sock_fd, &message, sizeof(struct message), 0) == -1)
            error("recv");

        // display
        if (ntohl(message.message_id) == YOUR_QUOTATION_PLEASE)
            printf("\n%s\n\n", message.buffer);
    }

    exit(EXIT_SUCCESS);
}

int get_option()
{
    int option;

    while (1)
    {
        printf("Get a Quote\n\n");
        printf("\tNew Quote\t1\n");
        printf("\tQuit\t\t0\n\n");
        printf("Your option: ");
        scanf("%d", &option);
        if (option == 0 || option == 1)
            return option;
        else
            printf("Illegal option, try again\n\n");
    }
}

void error(char *msg)
{
    perror(msg);
    exit(1);
}