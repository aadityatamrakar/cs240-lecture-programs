#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

void print_sum(int a, int b) {
    printf("%d + %d = %d\n", a, b, sum(a, b));
}
