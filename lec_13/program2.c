// count all possible ways to make change for a given amount of money
// using the fewest number of coins

#include <stdio.h>

int get_change(int amount);

int main(void)
{
    int amount = 0;
    printf("Enter the amount of change you need: ");
    scanf("%d", &amount);
    printf("There are %d ways to make change for %d cents.\n", get_change(amount), amount);
}

int get_change(int amount)
{
    // base case
    if (amount == 0)
        return 1;
    else if (amount < 0)
        return 0;
    else // recursive case
        return get_change(amount - 5) + get_change(amount - 3) + get_change(amount - 2) + get_change(amount - 1);
}
