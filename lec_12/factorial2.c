#include <stdio.h>

int fact(int n, int memo[])
{
    if (memo[n])
        return memo[n];
    else
        memo[n] = n * fact(n - 1, memo);

    return memo[n];
}

int main()
{
    int memo[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n = 5;
    printf("fact(%d) = %d\n", n, fact(n, memo));
    n = 6;
    printf("fact(%d) = %d\n", n, fact(n, memo));
}

// https://pythontutor.com/