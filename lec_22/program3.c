// https://www.programiz.com/c-programming/examples/lcm
#include <stdio.h>

int main()
{

    int n1, n2, i, gcd, lcm;

    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);

    // loop to find the GCD
    for (i = 1; i <= n1 && i <= n2; ++i)
    {

        // check if i is a factor of both integers
        if (n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }

    lcm = (n1 * n2) / gcd;

    printf("The LCM of two numbers %d and %d is %d.\n", n1, n2, lcm);
    return 0;
}

/*
The LCM of two integers n1 and n2 is the smallest positive integer that is perfectly divisible by both n1 and n2 (without a remainder). For example, the LCM of 72 and 120 is 360.
*/