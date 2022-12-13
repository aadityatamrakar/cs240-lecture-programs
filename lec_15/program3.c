// https://learn.microsoft.com/en-us/cpp/preprocessor/stringizing-operator-hash?view=msvc-170
// stringizer.c

#include <stdio.h>
#define stringer(x) printf(#x "\n")

int main()
{
    stringer(In quotes in the printf function call);
    // printf("In quotes in the printf function call");

    stringer("In quotes when printed to the screen");
    stringer("This: \"  prints an escaped double quote");
}