#include <stdio.h>

int main()
{
    char str[100];

    printf("Enter a value: ");
    fgets(str, 100, stdin);
    // gets(str); // Deprecated

    printf("\nYou entered: ");
    puts(str);

    return 0;
}