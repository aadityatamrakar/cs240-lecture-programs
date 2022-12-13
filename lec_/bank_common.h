#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), bind(), and connect() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

#define MAXPENDING 5   /* Maximum outstanding connection requests */
#define RCVBUFSIZE 256 /* Size of receive buffer */

#include <stdio.h>  /* for perror() */
#include <stdlib.h> /* for exit() */

void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}

// Enumeration (or enum) is a user defined data type.
// It is mainly used to assign names to integral constants,
// the names make a program easy to read and maintain.
typedef enum bank_op
{
    CREATE_ACCOUNT,
    DEPOSIT,
    WITHDRAW,
    GET_BALANCE,
    EXIT_BANK
} Operations;

// Client request data structure
typedef struct bank_request
{
    int command;   // 0: create account, 1: deposit, 2: withdraw, 3: get balance, 4: exit
    int accountId; // account id
    int amount;    // for deposit and withdraw
} Request;

// Account structure
typedef struct bank_account
{
    int balance;   // Account balance
    int id;        // Account id
    char name[20]; // Account name
} Account;

FILE *accounts_file()
{
    FILE *fptr;
    if ((fptr = fopen("accounts.bin", "ab+")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    return fptr;
}
