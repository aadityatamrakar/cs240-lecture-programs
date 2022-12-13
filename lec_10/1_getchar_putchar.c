#include <stdio.h>

int main()
{
    char c[50];
    int i = 0;
    printf("Enter a value :");
    do
    {
        c[i++] = getchar();
    } while (c[i - 1] != '\n');
    c[i++] = '\0';

    printf("\nYou entered:%s\n", c);
    // putchar(c);

    return 0;
}