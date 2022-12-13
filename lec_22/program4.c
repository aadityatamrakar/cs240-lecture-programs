// https://www.programiz.com/c-programming/examples/hcf-gcd

#include <stdio.h>
int main()
{
    int n1, n2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);

    while (n1 != n2)
    {
        if (n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    printf("GCD = %d\n", n1);

    return 0;
}

/*
In this method, smaller integer is subtracted from the larger integer,
and the result is assigned to the variable holding larger integer. 
This process is continued until n1 and n2 are equal.
*/