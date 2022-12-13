// https://www.includehelp.com/c-programs/c-pointer-program-to-change-the-value-of-constant-integer-using-pointers.aspx
/*C program to change the value of constant integer using pointers.*/

#include <stdio.h>

/*
Since, we cannot change the value of a constant but using pointer we
can change it, in this program we are doing the same. Here, we have
an integer constant and changing its value using pointer.
*/

int main()
{
    const int a = 10; // declare and assign constant integer
    int *p;           // declare integer pointer
    p = &a;           // assign address into pointer p

    printf("Before changing - value of a: %d", a);

    // assign value using pointer
    *p = 20;

    printf("\nAfter  changing - value of a: %d", a);
    printf("\nWauuuu... value has changed.");

    return 0;
}
