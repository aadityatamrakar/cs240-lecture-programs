#include "bank_common.h"

#define PORT 8282 // Port number

int main(int argc, char *argv[])
{
    int client_socket;                 // Socket descriptor
    struct sockaddr_in server_address; // Server address
    char *servIP;                      // Server IP address
    char request[RCVBUFSIZE];          // Buffer for client request
    char response[RCVBUFSIZE];         // Buffer for server response
    int respLength = 0;                // Bytes read in single recv()

    if ((argc < 3) || (argc > 4)) // Test for correct number of arguments
    {
        fprintf(stderr, "Usage: %s <Server IP> <AccountId>\n", argv[0]);
        exit(1);
    }

    servIP = argv[1];               // First argument: server IP address
    int account_id = atoi(argv[2]); // Second argument: account id
    printf("Account ID: %d\n", account_id);

    // Create a reliable, stream socket using TCP
    if ((client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    // Construct the server address structure
    memset(&server_address, 0, sizeof(server_address)); // Zero out structure
    server_address.sin_family = AF_INET;                // Internet address family
    server_address.sin_addr.s_addr = inet_addr(servIP); // Server IP address
    server_address.sin_port = htons(PORT);              // Server port

    // Establish the connection to the echo server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        DieWithError("connect() failed");

    // declaring variables for user input
    int choice;
    int amount;

    // print available options
    printf("Select an option:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Balance\n");
    printf("4. Quit\n");

    // loop until user selects option 4 (Quit)
    while (1)
    {
        printf(">> ");
        scanf("%d", &choice);

        // On choice 1 (Deposit) or 2 (Withdraw) ask for amount
        if (choice == DEPOSIT || choice == WITHDRAW)
        {
            printf(">> amount: ");
            scanf("%d", &amount);
            // create request string with choice, account id and amount
            // Comma (,) is used as a delimiter
            // to separate the choice, account id and amount
            sprintf(request, "%d,%d,%d", choice, account_id, amount);
        }
        else
        {
            // create request string with choice and account id
            // since choice 3 (Balance) and 4 (Quit) do not require amount
            sprintf(request, "%d,%d,%d", choice, account_id, 0);
        }

        // send function returns the number of bytes sent to the server
        if (send(client_socket, request, strlen(request), 0) != strlen(request))
        {
            DieWithError("send() sent a different number of bytes than expected");
        }

        // recv function returns the number of bytes received from the server
        if ((respLength = recv(client_socket, response, RCVBUFSIZE - 1, 0)) < 0)
        {
            DieWithError("recv() failed");
        }

        // if choice is 4 (Quit) break the loop
        if (choice == EXIT_BANK)
        {
            break;
        }

        response[respLength] = '\0'; // Terminate the string
        printf("<< %s\n", response); // Print the server response
    }

    close(client_socket);
    exit(0);
}
