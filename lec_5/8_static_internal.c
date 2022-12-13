#include <stdio.h>

int counter()
{
    static int num = 0;
    return num++;
}

int main(void)
{
    for (int i = 0; i < 5; i++)
        counter();
    printf("%d\n", counter());
}