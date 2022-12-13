/**
 *
 * Server
 * 1. Create a TCP socket
 * 2. Bind socket to a port
 * 3. Set socket to listen
 * 4. Repeatedly:
 *     a. Accept new connection
 *     b. create a new thread to handle the connection
 * 
 */

#include "bank_common.h"
#include "bank_operations.h"
#include <pthread.h> /* for threads */

#define PORT 8282 // Port number

int accountId;
int HandleClient(int client_socket);
void SendResponse(int client_socket, char *response);

void *ThreadMain(void *arg); /* Main program of a thread */

/* Structure of arguments to pass to client thread */
struct ThreadArgs
{
    int client_socket; /* Socket descriptor for client */
};

void sigintHandler(int sig_num)
{
    exit(0);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, sigintHandler);

    int server_socket;                 // Socket descriptor for server
    int client_socket;                 // Socket descriptor for client
    struct sockaddr_in server_address; // Local address
    struct sockaddr_in client_address; // Client address
    unsigned int clntLen;              // Length of client address data structure

    pthread_t threadID;            /* Thread ID from pthread_create() */
    struct ThreadArgs *threadArgs; /* Pointer to argument structure for thread */

    // Create socket for incoming connections
    if ((server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        //
        DieWithError("socket() failed");
    }

    // Construct local address structure
    memset(&server_address, 0, sizeof(server_address)); // Zero out structure
    server_address.sin_family = AF_INET;                // Internet address family
    server_address.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface
    server_address.sin_port = htons(PORT);              // Local port

    // htons converts the port number to network byte order
    // htonl converts the IP address to network byte order

    // Bind to the local address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        DieWithError("bind() failed");

    // Mark the socket so it will listen for incoming connections
    if (listen(server_socket, MAXPENDING) < 0)
        DieWithError("listen() failed");

    // creating accounts for testing
    create_account(1, "Alice", 2000);
    create_account(2, "Bob", 2000);
    create_account(3, "Charlie", 2000);

    for (;;) // Run forever
    {
        // Set the size of the in-out parameter
        clntLen = sizeof(client_address);

        // Wait for a client to connect
        // accept function pause the program until a client connects
        // accept function returns a new socket descriptor for the client
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &clntLen)) < 0)
            DieWithError("accept() failed");

        // client_socket is connected to a client!
        // inet_ntoa converts the IP address to a string
        printf("Handling client %s\n", inet_ntoa(client_address.sin_addr));

        /* Create separate memory for client argument */
        if ((threadArgs = (struct ThreadArgs *)malloc(sizeof(struct ThreadArgs))) == NULL)
            DieWithError("malloc() failed");
        threadArgs->client_socket = client_socket;

        /* Create client thread */
        if (pthread_create(&threadID, NULL, ThreadMain, (void *)threadArgs) != 0)
            DieWithError("pthread_create() failed");
        printf("with thread %ld\n", (long int)threadID);
    }

    // NOT REACHED
}

void *ThreadMain(void *threadArgs)
{
    int client_socket; /* Socket descriptor for client connection */

    /* Guarantees that thread resources are deallocated upon return */
    pthread_detach(pthread_self());

    /* Extract socket file descriptor from argument */
    client_socket = ((struct ThreadArgs *)threadArgs)->client_socket;

    free(threadArgs); /* Deallocate memory for argument */

    while (1)
    {
        int result = HandleClient(client_socket);
        if (result == -1)
            break;
    }

    return (NULL);
}

int HandleClient(int client_socket)
{
    char response[RCVBUFSIZE];       // Buffer for response string
    char client_request[RCVBUFSIZE]; // Buffer for request string
    int recvMsgSize;                 // Size of received message

    // Receive message from client
    // if recv() returns 0, the client has disconnected
    if ((recvMsgSize = recv(client_socket, client_request, RCVBUFSIZE, 0)) < 0)
    {
        // if recv() fails, return -1
        // to indicate that the client has disconnected
        return -1;
    }

    // client_request is a string, so we need to convert to request data structure first
    // then we can use the request data to perform the corresponding operation
    Request request = parse_command(client_request);
    switch (request.command)
    {
    case DEPOSIT:
        // deposit money to the account
        deposit(request.accountId, request.amount);
        // generate response string to send back to the client
        sprintf(response, "Updated balance: %d", balance(request.accountId));
        break;
    case WITHDRAW:
        // withdraw money from the account
        withdraw(request.accountId, request.amount);
        sprintf(response, "Updated balance: %d", balance(request.accountId));
        break;
    case GET_BALANCE:
        sprintf(response, "Account Balance: %d", balance(request.accountId));
        break;
    case EXIT_BANK:
        sprintf(response, "Exitting... ID: %d", request.accountId);
        close(client_socket); // Close client socket
        break;
    default:
        sprintf(response, "Invalid Choise...");
        break;
    }

    // Send function is used to send data to the client
    // send() returns the number of bytes sent
    if (send(client_socket, response, strlen(response), 0) != strlen(response))
    {
        // if send() fails, return -1
        // to indicate that the client has disconnected
        return -1;
    }

    return 0;
}
