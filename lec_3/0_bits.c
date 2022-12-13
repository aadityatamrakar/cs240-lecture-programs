/* Project: lec3
 * Name   : Aaditya Tamrakar
 * Date   : 09/13/2022
 */
#include <stdio.h>
#include <float.h>
#include <limits.h>

void bin_char(unsigned char n)
{
    // formatted output %11d means 11 spaces, and d means decimal
    // printf function format: https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm
    printf("%11d\t:\t", (signed char)n);
    unsigned i, j = 0;
    for (i = 1 << 7; i > 0; i = i / 2)
    {
        (n & i) ? printf("1") : printf("0");
    }
    printf("\n");
}

void bin(unsigned n)
{
    printf("%11d\t:\t", n);
    unsigned i, j = 0;
    // 1 is right shifted by 31 times
    for (i = 1 << 31; i > 0; i = i / 2)
    {
        (n & i) ? printf("1") : printf("0");
        if ((j + 1) % 8 == 0)
            printf(" ");
        j++;
    }
    printf("\n");
}

int main(void)
{

    bin(INT_MIN);
    bin_char(CHAR_MIN);
    
    bin(INT_MAX);
    bin_char(CHAR_MAX);

    return 0;
}

// To Run: gcc 0_bits.c -o 0_bits && ./0_bits && rm 0_bits