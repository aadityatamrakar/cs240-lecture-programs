#include <stdio.h>

char a();

int main(void)
{
    // Note that a() is not declared
    printf("%c\n", a());
    return 0;
}

// function definition
char a()
{
    return 'a';
}
