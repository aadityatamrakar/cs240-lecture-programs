#include "bank_common.h"

#define PORT 8282 // Port number

int main(int argc, char *argv[])
{
    int sock;                        /* Socket descriptor */
    struct sockaddr_in echoServAddr; /* Echo server address */
    unsigned short echoServPort;     /* Echo server port */
    char *servIP;                    /* Server IP address (dotted quad) */
    char *echoString;                /* String to send to echo server */
    char echoBuffer[RCVBUFSIZE];     /* Buffer for echo string */
    unsigned int echoStringLen;      /* Length of string to echo */
    int bytesRcvd, totalBytesRcvd;   /* Bytes read in single recv()
                                        and total bytes read */

    if ((argc < 3) || (argc > 4)) /* Test for correct number of arguments */
    {
        fprintf(stderr, "Usage: %s <Server IP> <AccountId>\n",
                argv[0]);
        exit(1);
    }

    servIP = argv[1];     /* First arg: server IP address (dotted quad) */
    echoString = argv[2]; /* Second arg: string to echo */
    int account_id = atoi(echoString);

    printf("Account ID: %d\n", account_id);

    /* Create a reliable, stream socket using TCP */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    /* Construct the server address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));   /* Zero out structure */
    echoServAddr.sin_family = AF_INET;                /* Internet address family */
    echoServAddr.sin_addr.s_addr = inet_addr(servIP); /* Server IP address */
    echoServAddr.sin_port = htons(PORT);              /* Server port */

    /* Establish the connection to the echo server */
    if (connect(sock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("connect() failed");

    echoStringLen = strlen(echoString); /* Determine input length */

    int choice;
    int amount;
    char buffer[100];
    char *token;

    printf("Select an option:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Balance\n");
    printf("4. Quit\n");

    while (1)
    {
        
        printf(">> ");
        scanf("%d", &choice);

        if (choice == DEPOSIT || choice == WITHDRAW)
        {
            printf(">> amount: ");
            scanf("%d", &amount);
            sprintf(buffer, "%d %d %d ", choice, account_id, amount);
        }
        else
        {
            sprintf(buffer, "%d %d %d ", choice, account_id, 0);
        }

        if (send(sock, buffer, strlen(buffer), 0) != strlen(buffer))
            DieWithError("send() sent a different number of bytes than expected");

        /* Receive the same string back from the server */
        totalBytesRcvd = 0;
        printf("<< "); /* Setup to print the echoed string */
        while (totalBytesRcvd < echoStringLen)
        {
            /* Receive up to the buffer size (minus 1 to leave space for
               a null terminator) bytes from the sender */
            if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0)
                DieWithError("recv() failed or connection closed prematurely");
            totalBytesRcvd += bytesRcvd;  /* Keep tally of total bytes */
            echoBuffer[bytesRcvd] = '\0'; /* Terminate the string! */
            printf("%s", echoBuffer);     /* Print the echo buffer */
        }

        printf("\n"); /* Print a final linefeed */

        if (choice == EXIT_BANK)
        {
            break;
        }
    }

    close(sock);
    exit(0);
}
