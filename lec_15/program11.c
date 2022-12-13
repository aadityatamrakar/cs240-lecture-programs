// C program to check and rectify
// divide by zero condition
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void function(int);

int main(int argc, char *argv[])
{

    int x;
    if (argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    x = atoi(argv[1]);
    function(x);
    return 0;
}

void function(int x)
{
    float fx;

    if (x == 0)
    {
        printf("Division by Zero is not allowed\n");
        fprintf(stderr, "Division by zero! Exiting...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        fx = 10 / x;
        printf("f(x) is: %.2f\n", fx);
    }
}
