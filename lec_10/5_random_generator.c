#include <stdio.h>
#include <stdlib.h>

int random_number(int min, int max)
{
    // rand() returns a random number between 0 and RAND_MAX
    // RAND_MAX is defined in stdlib.h
    return rand() % (max - min + 1) + min;
}

int main()
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        j = random_number(10, 20);
        printf("%d ", j);
    }
    printf("\n");

    return 0;
}