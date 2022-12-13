// https://www.includehelp.com/c-programs/c-pointer-program-to-count-vowels-and-consonants-in-a-string-using-pointer.aspx
/*C program to count vowels and consonants in a string using pointer.*/
#include <stdio.h>

/*
we are reading a string and assigning its base address to the
character pointer, and to check characters are vowels or consonants,
we will check and count each character one by one by increasing the
pointer.
*/

int main()
{
    char str[100];
    char *ptr;
    int cntV, cntC;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // assign address of str to ptr
    ptr = str;

    cntV = cntC = 0;
    while (*ptr != '\0')
    {
        if (*ptr == 'A' || *ptr == 'E' || *ptr == 'I' || 
        *ptr == 'O' || *ptr == 'U' || *ptr == 'a' || *ptr == 'e' ||
        *ptr == 'i' || *ptr == 'o' || *ptr == 'u')
            cntV++;
        else
            cntC++;
        // increase the pointer, to point next character
        ptr++;
    }

    printf("Total number of VOWELS: %d, CONSONANT: %d\n", cntV, cntC);
    return 0;
}
