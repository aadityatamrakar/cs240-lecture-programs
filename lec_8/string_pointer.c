// C program to print string using Pointers
#include <stdio.h>

int main()
{
    char str[10] = "CS240";

    // Pointer variable which stores
    // the starting address of
    // the character array str
    char *ptr = str;

    // While loop will run till
    // the character value is not
    // equal to null character
    for (int i = 0; i < 10; i++)
    {
        printf("%d = %c\n", i, *ptr);

        // moving pointer to the next character.
        // ptr++;
    }
    printf("\n");

    return 0;
}
