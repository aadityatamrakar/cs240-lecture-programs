// create a program a recursively get the count of coins needed to make change
// for a given amount of money

#include <stdio.h>

int get_change(int amount);

int main(void)
{
    int amount = 0;
    printf("Enter the amount of change you need: ");
    scanf("%d", &amount);
    printf("You need %d coins to make change for %d cents.\n", get_change(amount), amount);
}

// Parts of a Recursive Algorithm
// All recursive algorithms must have the following:
// Base Case (i.e., when to stop)
// Work toward Base Case
// Recursive Call (i.e., call ourselves)

// The "work toward base case" is where we make the problem simpler (e.g., divide list into two parts, each smaller than the original). The recursive call, is where we use the same algorithm to solve a simpler version of the problem. The base case is the solution to the "simplest" possible problem (For example, the base case in the problem 'find the largest number in a list' would be if the list had only one number... and by definition if there is only one number, it is the largest).
// Link: https://www.cs.utah.edu/~germain/PPS/Topics/recursion.html

int get_change(int amount)
{
    // base case
    if (amount == 0)
        return 0;
    else if (amount >= 5)
        return 1 + get_change(amount - 5);
    else if (amount >= 3)
        return 1 + get_change(amount - 3);
    else if (amount >= 2) 
        return 1 + get_change(amount - 2);
    else
        return 1 + get_change(amount - 1);
}
