#include <stdio.h>

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int n = 5;
    printf("fact(%d) = %d\n", n, fact(n));
    n = 6;
    printf("fact(%d) = %d\n", n, fact(n));
}
