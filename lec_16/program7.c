// https://www.programiz.com/c-programming/c-enumeration
#include <stdio.h>

// In C programming, an enumeration type (also called enum) is a data type that consists of integral constants. To define enums, the enum keyword is used.
enum boolean
{
    false,
    true
};

int main()
{
    enum boolean a = false;
    printf("a = %d\n", a);

    enum boolean b = true;
    printf("b = %d\n", b);

    if(b == true) {
        printf("b is true\n");
    }
    return 0;
}