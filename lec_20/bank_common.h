#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), bind(), and connect() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

#define MAXPENDING 5    /* Maximum outstanding connection requests */
#define RCVBUFSIZE 256   /* Size of receive buffer */

#include <stdio.h>  /* for perror() */
#include <stdlib.h> /* for exit() */

void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}

typedef enum bank_op
{
    CREATE_ACCOUNT,
    DEPOSIT,
    WITHDRAW,
    GET_BALANCE,
    EXIT_BANK
} Operations;

typedef struct bank_requests
{
    int command;
    int accountId;
    int amount;
} Request;

struct account
{
    int balance;
    int id;
    char name[20];
};
