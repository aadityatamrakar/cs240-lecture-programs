/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>
#include <float.h>
void bin(unsigned n);

int main(void)
{

    // 1.0f is a float literal
    // 1.0 is a double

    printf(" FLT_EPSILON  : %d\n", 1.0f + FLT_EPSILON == 1.0f);
    printf(" DBL_EPSILON  : %d\n", 1.0 + DBL_EPSILON == 1.0);

    printf(" FLT_EPSILON  : %d\n", 1.0f + FLT_EPSILON / 2.0f == 1.0f);
    printf(" DBL_EPSILON  : %d\n", 1.0 + DBL_EPSILON / 2.0 == 1.0);

    float a[] = {127.125, 0.25, 0.5, 0.75, 1.0, 2.0, 2.5, 4.0, 8.0, 16.0, 3.0};
    for (int i = 0; i < 8; i++)
    {

        unsigned int *b = (unsigned int *)a + i;
        printf("%3.6f  : ", a[i]);
        bin(*b);

        // printf("%3.18f  : %x\n", a[i], *b);
    }

    printf("0.1 is not 0.1 in computer:  %1.30f\n", 0.1f);

    return 0;
}

void bin(unsigned n)
{
    unsigned i, j = 0;
    for (i = 1 << 31; i > 0; i = i / 2)
    {
        (n & i) ? printf("1") : printf("0");
        if (j == 0 || j == 8)
            printf(" ");
        j++;
    }
    printf("\n");
}

// To Run: gcc 5_floats_epsilon.c -o 5_floats_epsilon && ./5_floats_epsilon && rm 5_floats_epsilon