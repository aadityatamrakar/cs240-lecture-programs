// https://www.geeksforgeeks.org/callbacks-in-c/
// A simple C program to demonstrate callback
#include <stdio.h>

// A callback is any executable code that is passed as an argument to other code, which is expected to call back (execute) the argument at a given time. In simple language, If a reference of a function is passed to another function as an argument to call it, then it will be called as a Callback function.

void A()
{
    printf("I am function A\n");
}

// callback function
void B(void (*ptr)())
{
    (*ptr)(); // callback to A
}

int main()
{
    void (*ptr)() = &A;

    // calling function B and passing
    // address of the function A as argument
    B(ptr);

    return 0;
}
