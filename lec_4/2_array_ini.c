/*
 * Author : Haoyu Wang
 * Description:
 *
 *
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3};
    int b[5] = {1, 2, 3};
    int c[5] = {[1] = -1, [4] = -2};
    // after c99; designated initializer

    printf("b[0] %d\n", b[0]);
    printf("b[4] %d\n", b[4]);
    printf("c[4] %d\n", c[4]);

    printf("the length of a is %lu\n", sizeof(a) / sizeof(int));

    return 0;
}