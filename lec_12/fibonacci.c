#include <stdio.h>

int fibonacci(int);

int main()
{
    int n = 5;
    printf("fibonacci(%d) = %d\n", n, fibonacci(n));
}

// fibonacci using iteration
// int fibonacci(int n)
// {
//     int f1 = 0, f2 = 1, f3;
//     if (n == 0)
//         return f1;
//     else if (n == 1)
//         return f2;
//     else
//     {
//         for (int i = 2; i <= n; i++)
//         {
//             f3 = f1 + f2;
//             f1 = f2;
//             f2 = f3;
//         }
//         return f3;
//     }
// }

// fibonacci using recursion
int fibonacci(int n)
{
    printf("fibonacci(%d)\n", n);
    if (n == 0 || n == 1)
    {
        return 1; // base cases
    }
    else
    {
        printf("fibonacci(%d) + fibonacci(%d)\n", n - 1, n - 2);
        return fibonacci(n - 1) + fibonacci(n - 2); // recursive step
    }
}