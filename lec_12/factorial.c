#include <stdio.h>

int factorial_i(int);
int factorial_r(int);

int main()
{
    int n;
    printf("Enter the number = ");
    scanf("%d", &n);
    printf("factorial_i(%d) = %d\n", n, factorial_i(n));
    printf("factorial_r(%d) = %d\n", n, factorial_r(n));
}

int factorial_i(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int factorial_r(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial_r(n - 1);
}
