#include <stdio.h>

int main()
{
    int var;
    int *ptr;
    int **pptr;

    var = 3000;

    /* take the address of var */
    ptr = &var;

    /* take the address of ptr using address of operator & */
    pptr = &ptr;

    /* take the value using pptr */
    printf("Value of var = %d\n", var);
    printf("Value at *ptr = %d\n", *ptr);
    printf("Value at **pptr = %d\n", **pptr);
    
    printf("Address of var = %x\n", var);
    printf("Address of *ptr = %x\n", *ptr);
    printf("Address of **pptr = %x\n", **pptr);
    
    return 0;
}