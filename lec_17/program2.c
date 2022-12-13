// exec example

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cs240.h"

int main(int argc, char *argv[])
{

    // sum(1, 2);

    // char *args[] = {"ping", "google.com", "-c", "3", NULL};
    // execvp("ping", args);
    // printf("Line executed\n");
    int result = system("ping google.com -c 3");

    // what is errno in C?
    // 1. errno is a global variable
    // 2. errno is an integer
    // 3. errno corresponds to an error code
    // 4. error.h library contains the error codes and their corresponding error messages

    printf("This line will not be printed\n");
    return 0;
}

