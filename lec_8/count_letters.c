// C program to demonstrate working of isalpha() and
// isdigit().
#include <ctype.h>
#include <stdio.h>
// #include <stdlib.h>

int main()
{
    char str[] = "abc123";

    int alphabet = 0, number = 0, i;
    for (i = 0; str[i] != '\0'; i++)
    {

        // check for alphabets
        if (isalpha(str[i]) != 0)
            alphabet++;

        // check for decimal digits
        else if (isdigit(str[i]) != 0)
            number++;
    }

    printf("Alphabetic_letters = %d, Decimal_digits = %d\n", alphabet, number);

    return 0;
}
