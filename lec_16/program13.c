// https://www.geeksforgeeks.org/void-pointer-c-cpp/
#include <stdio.h>

int main()
{
    int a = 10;
    // A void pointer is a pointer that has no associated data type with it. A void pointer can hold address of any type and can be typecasted to any type.
    void *ptr = &a;
    printf("Value of a = %d\n", a);
    printf("Address of a = %p\n", &a);
    printf("Value of ptr = %p\n", ptr);
    printf("Address of ptr = %p\n", &ptr);
    printf("Value of `a` using ptr = %d\n", *(int *)ptr);
    return 0;
}
