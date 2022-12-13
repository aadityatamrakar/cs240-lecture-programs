#include "bank_common.h"
#include "bank_operations.h"

#define PORT 8282 // Port number

int accountId;
int HandleClient(int clntSocket);
void SendResponse(int clntSocket, char *response);

int main(int argc, char *argv[])
{
    int servSock;                    // Socket descriptor for server
    int clntSock;                    // Socket descriptor for client
    struct sockaddr_in echoServAddr; // Local address
    struct sockaddr_in echoClntAddr; // Client address
    unsigned int clntLen;            // Length of client address data structure

    // Create socket for incoming connections
    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    // Construct local address structure
    memset(&echoServAddr, 0, sizeof(echoServAddr));   // Zero out structure
    echoServAddr.sin_family = AF_INET;                // Internet address family
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface
    echoServAddr.sin_port = htons(PORT);              // Local port

    // Bind to the local address
    if (bind(servSock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("bind() failed");

    // Mark the socket so it will listen for incoming connections
    if (listen(servSock, MAXPENDING) < 0)
        DieWithError("listen() failed");

    // creating accounts for testing
    create_account(1, "Alice", 2000);
    create_account(2, "Bob", 2000);
    create_account(3, "Charlie", 2000);

    for (;;) // Run forever
    {
        // Set the size of the in-out parameter
        clntLen = sizeof(echoClntAddr);

        // Wait for a client to connect
        if ((clntSock = accept(servSock, (struct sockaddr *)&echoClntAddr,
                               &clntLen)) < 0)
            DieWithError("accept() failed");

        // clntSock is connected to a client!
        // inet_ntoa converts the IP address to a string
        printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));

        while (1)
        {
            if (HandleClient(clntSock) == -1)
            {
                break;
            }
        }
    }
    // NOT REACHED
}

int HandleClient(int clntSocket)
{
    char response[RCVBUFSIZE];   // Buffer for response string
    char echoBuffer[RCVBUFSIZE]; // Buffer for echo string
    int recvMsgSize;             // Size of received message

    // Receive message from client
    if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
        return -1;

    Request request = parse_command(echoBuffer);
    int i;
    switch (request.command)
    {
    case DEPOSIT:
        deposit(request.accountId, request.amount);
        sprintf(response, "Deposited %d to account %d", request.amount, request.accountId);
        SendResponse(clntSocket, response);
        break;
    case WITHDRAW:
        withdraw(request.accountId, request.amount);
        sprintf(response, "Withdrew %d from account %d", request.amount, request.accountId);
        SendResponse(clntSocket, response);
        break;
    case GET_BALANCE:
        sprintf(response, "Balance: %d", balance(request.accountId));
        SendResponse(clntSocket, response);
        break;
    case EXIT_BANK:
        sprintf(response, "Exitting... ID: %d", request.accountId);
        SendResponse(clntSocket, response);
        close(clntSocket); // Close client socket
        break;
    default:
        break;
    }

    return 0;
}

void SendResponse(int clntSocket, char *response)
{
    if (send(clntSocket, response, strlen(response), 0) != strlen(response))
        DieWithError("send() failed");
}
