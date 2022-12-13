// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     float num, root;
//     printf("Enter a number: ");
//     scanf("%f", &num);

//     // Computes the square root of num and stores in root.
//     root = sqrt(num);

//     printf("Square root of %.2f = %.2f\n", num, root);
//     return 0;
// }

#include <stdio.h>
void increment(int a)
{
    ++a;
}

void increment_array(int a[])
{
    ++a[0];
}

int main()
{
    int a = 1, b[] = {1};
    increment(a);
    increment_array(b);
    printf("a: %d, ", a);
    printf("b[0]: %d\n", b[0]);
    return 0;
}