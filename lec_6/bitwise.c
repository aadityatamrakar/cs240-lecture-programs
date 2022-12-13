#include <stdio.h>

int main()
{
    unsigned int a = 60; /* 60 = 0011 1100 */
    unsigned int b = 13; /* 13 = 0000 1101 */
    int c = 0;

    // & AND operator
    c = a & b; /* 12 = 0000 1100 */
    printf("Line 1 - Value of c is %d\n", c);
    /**
     * calculation: 0011 1100
     *            & 0000 1101
     *            = 0000 1100
     */

    // | OR operator
    c = a | b; /* 61 = 0011 1101 */
    printf("Line 2 - Value of c is %d\n", c);
    /**
     * calculation: 0 0 1 1 1 1 0 0
     *            | 0 0 0 0 1 1 0 1
     *            = 0 0 1 1 1 1 0 1
     */

    // ^ XOR operator
    c = a ^ b; /* 49 = 0011 0001 */
    printf("Line 3 - Value of c is %d\n", c);
    /**
     * calculation: 0011 1100
     *            ^ 0000 1101
     *            = 0011 0001
     */

    // ~ NOT operator
    c = ~a; /*-61 = 1100 0011 */
    printf("Line 4 - Value of c is %d\n", c);
    /**
     * calculation: ~ 0011 1100
     *              = 1100 0011
     */

    // << Left shift operator
    // c = a << 2; /* 240 = 1111 0000 */
    // a = 2; // reset a
    // c = a << 2; /* 8 = 0000 1000 */
    printf("Line 5 - Value of c is %d\n", c);
    /**
     * calculation: 0011 1100 << 2
     *                 0011 1100 00
     *              = 1111 0000
     */

    // >> Right shift operator
    c = a >> 2; /* 15 = 0000 1111 */
    printf("Line 6 - Value of c is %d\n", c);
    /**
     * calculation: 0011 1100 >> 2
     *              = 0000 1111
     */

    return 0;
}