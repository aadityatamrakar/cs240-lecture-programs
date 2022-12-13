// https://www.geeksforgeeks.org/implicit-return-type-int-c-language/
#include <stdio.h>

// The important thing to note is, there is no return type for power2(), the program still compiles and runs fine in most of the C compilers. In C, if we do not specify a return type, compiler assumes an implicit return type as int. However, C99 standard doesn’t allow return type to be omitted even if return type is int. This was allowed in older C standard C89.

int power2(int x)
{
    return x * x;
}

int main(void)
{
    printf("%d\n", power2(10));
    return 0;
}
