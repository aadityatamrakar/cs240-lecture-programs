// C program to demonstrate declaration of
// pointer variables.
#include <stdio.h>
int main()
{
    int x = 10;

    // 1) Since there is * in declaration, ptr
    // becomes a pointer variable (a variable
    // that stores address of another variable)
    // 2) And since there is int before *, ptr is
    // pointer to an integer type variable
    int *ptr;

    // & operator before x is used to get address
    // of x. The address of x is assigned to ptr.
    ptr = &x;

    printf("Address of ptr is %p\n", &ptr);
    printf("Value of ptr is %p\n", ptr);
    printf("Value at ptr is %d\n", *ptr);
    
    printf("Address of x is %p\n", &x);
    printf("Value of x is %d\n", x);

    printf("Value at ptr is %d\n", ++(*ptr));
    printf("Value at ptr is %p\n", ++ptr);

    printf("Value of x is %d\n", x);

    return 0;
}
