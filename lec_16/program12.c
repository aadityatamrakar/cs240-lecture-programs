// A simple C program to show function pointers as parameter
#include <stdio.h>
#include <stdlib.h>

// Two simple functions
void add(int a, int b) { printf("Add(%d, %d) = %d\n", a, b, a + b); }
void sub(int a, int b) { printf("Sub(%d, %d) = %d\n", a, b, a - b); }
void mul(int a, int b) { printf("Mul(%d, %d) = %d\n", a, b, a * b); }

void run(char *a, char *b, void (*calc)())
{
    // convert string to int
    int x = atoi(a);
    int y = atoi(b);

    calc(x, y);
}

int main()
{
    char a[] = "10";
    char b[] = "5";

    run(a, b, add);
    run(a, b, sub);
    run(a, b, mul);

    return 0;
}
