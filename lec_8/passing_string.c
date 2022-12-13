// C program to illustrate how to
// pass string to functions
#include <stdio.h>

void printStr(char str[])
{
    printf("String is : %s\n", str);
}

int main()
{
    // declare and initialize string
    char str[] = "CS240";

    // print string by passing string
    // to a different function
    printStr(str);

    return 0;
}
