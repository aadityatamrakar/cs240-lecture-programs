// https://www.programiz.com/c-programming/c-preprocessor-macros

#include <stdio.h>

int main()
{
    // common predefined macros
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);
    // stdc = 1 if the compiler complies with the ISO C standard.
    printf("ANSI: %d\n", __STDC__);
    
    return 0;
}