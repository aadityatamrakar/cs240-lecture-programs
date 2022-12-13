// https://www.geeksforgeeks.org/function-pointer-in-c/
#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a)
{
    printf("Value of a is %d\n", a);
}

int main()
{
    // fun_ptr is a pointer to function fun()
    void (*fun_ptr)(int) = &fun;

    // print address of fun_ptr
    printf("Address of fun_ptr is %p\n", &fun_ptr);
    printf("Address of fun is %p\n", fun_ptr);
    printf("Address of fun is %p\n", &fun);

    /* The above line is equivalent of following two
    void (*fun_ptr)(int);
    fun_ptr = &fun;
    */

    // Invoking fun() using fun_ptr
    (*fun_ptr)(10);
    fun_ptr(10);

    return 0;
}
