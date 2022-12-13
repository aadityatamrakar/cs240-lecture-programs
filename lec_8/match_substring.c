// C program to illustrate strspn() function
#include <stdio.h>
#include <string.h>

int main()
{
    // strspn(s1, s2) returns the length of the initial segment of s1 which consists entirely of characters in s2
    int len = strspn("abcdef", "zabc");
    printf("Length of initial segment matching : %d\n", len);
    return (0);
}

// https://www.geeksforgeeks.org/strspn-function-c/
