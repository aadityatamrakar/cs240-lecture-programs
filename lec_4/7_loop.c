#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3}, i, j, temp;
    for (
        i = 0, j = sizeof(a) / sizeof(int) - 1;
        i < j;
        i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        printf("%d %d %d\n", i, a[i], a[j]);
    }

    i = 0;
    while (i < sizeof(a) / sizeof(int))
    {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");

    i = 0;
    do
    {
        printf("%d ", a[i]);
        i++;
    } while (i < sizeof(a) / sizeof(int));
    printf("\n");

    ;

    int b = 0;
    for (;;)
    {
        printf("infinite loop\n");
        b++;
        if (b == 2)
            break;
    }

    for (int c = 0; c < 2; c++)
    {
        printf("1 infinite loop\n");
    }

    // 3, 2, 1
}