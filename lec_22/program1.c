// https://www.programiz.com/c-programming/examples/reverse-number

#include <stdio.h>

int main()
{

    int n, reverse = 0, remainder;

    printf("Enter an integer: ");
    scanf("%d", &n);

    while (n != 0)
    {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }

    printf("Reversed number = %d", reverse);

    return 0;
}

/*
Output:
Enter an integer: 2345
Reversed number = 5432


This program takes integer input from the user. Then the while loop is used until n != 0 is false (0).

In each iteration of the loop, the remainder when n is divided by 10 is calculated and the value of n is reduced by 10 times.

Inside the loop, the reversed number is computed using:

reverse = reverse * 10 + remainder;
Let us see how the while loop works when n = 2345.

n           n != 0          remainder      reverse
2345        true            5              0 * 10 + 5 = 5
234         true            4              5 * 10 + 4 = 54
23          true            3              54 * 10 + 3 = 543
2           true            2              543 * 10 + 2 = 5432
0           false           -              Loop terminates.

Finally, the reverse variable (which contains the reversed number) is printed on the screen.


*/
