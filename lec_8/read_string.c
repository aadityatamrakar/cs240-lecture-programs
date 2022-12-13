// C program to read string from user
#include <stdio.h>

int main()
{
    // declaring string
    char str[50];
    char str2[50];

    printf("Input String: ");

    // reading string
    scanf("%s %s", str, str2);

    // print string
    printf("String: %s\n", str);
    printf("String2: %s\n", str2);

    return 0;
}
