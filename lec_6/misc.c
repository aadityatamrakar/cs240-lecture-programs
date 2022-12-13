#include <stdio.h>

int main()
{
    int a = 4;
    short b;
    double c;
    int *ptr;

    /* example of sizeof operator */
    printf("Line 1 - Size of variable a = %lu\n", sizeof(a));
    printf("Line 2 - Size of variable b = %lu\n", sizeof(b));
    printf("Line 3 - Size of variable c = %lu\n", sizeof(c));

    /* example of & and * operators */
    ptr = &a; /* 'ptr' now contains the address of 'a'*/
    printf("value of a is  %d\n", a);
    printf("*ptr is %d.\n", *ptr);

    /* example of ternary operator */
    a = 10;
    
    b = (a == 1) ? 20 : 30;
    
    // if (a == 1)
    //     b = 20;
    // else
    //     b = 30;
    
    printf("Value of b is %d\n", b);

    b = (a == 10) ? 20 : 30;
    printf("Value of b is %d\n", b);

    return 0;
}