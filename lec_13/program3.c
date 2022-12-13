// count all possible ways to make change for a given amount of money
// using the fewest number of coins + memoization

#include <stdio.h>

int get_change(int amount, int memo[]);

int main(void)
{
    int amount = 0;
    printf("Enter the amount of change you need: ");
    scanf("%d", &amount);
    int memo[amount + 1];
    for (int i = 0; i < amount + 1; i++)
        memo[i] = -1;
    printf("There are %d ways to make change for %d cents.\n", get_change(amount, memo), amount);
}

int get_change(int amount, int memo[])
{
    // base case
    if (amount == 0)
        return 1;
    else if (amount < 0)
        return 0;
    else if (memo[amount] != -1)
        return memo[amount];
    else
    {
        // recursive case
        memo[amount] = get_change(amount - 5, memo) + get_change(amount - 3, memo) + get_change(amount - 2, memo) + get_change(amount - 1, memo);
        return memo[amount];
    }
}