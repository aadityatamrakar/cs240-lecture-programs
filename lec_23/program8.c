/*C program to print size of different types of pointer variables.*/
#include <stdio.h>

int main()
{
    printf("\nsize of char pointer: %lu", sizeof(char *));
    printf("\nsize of int pointer: %lu", sizeof(int *));
    printf("\nsize of float pointer: %lu", sizeof(float *));
    printf("\nsize of long int pointer: %lu", sizeof(long int *));
    printf("\nsize of double pointer: %lu\n", sizeof(double *));
    return 0;
}

/*
Any type of pointer variable takes the same memory bytes in the
memory, because they are used to store the memory addresses on other
type of variables.

Let’s take an example - 
There are two pointers 
1) integer pointer and 
2) char pointer, 

integer pointer will take 4 bytes (in case of, 32 bits compiler) and
will store the address of integer variables only. char pointer will
also take 4 bytes but it will store the address of only char variable.
*/