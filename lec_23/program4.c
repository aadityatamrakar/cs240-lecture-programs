// https://www.includehelp.com/c-programs/c-pointer-program-to-print-a-string-using-pointer.aspx
/*C program to print a string using pointer.*/

/**
Here, we have two variables, str is a string variable and ptr is a
character pointer, that will point to the string variable str.

First of all, we are reading string in str and then assigning the
base address of str to the character pointer ptr by using ptr=str or
it can also be done by using ptr = &str[0].

And, finally we are printing the string character by character until
NULL not found. Characters are printing by the pointer *ptr.

Consider the program
*/

#include <stdio.h>
int main()
{
    char str[100];
    char *ptr;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // assign address of str to ptr
    ptr = str;

    printf("Entered string is: ");
    while (*ptr != '\0')
    {
        // if (*ptr == ' ')
        // {
        //     printf("\n");
        //     ptr++;
        // }
        // else
        // {
            printf("%c", *ptr++);
        // }
    }

    return 0;
}
