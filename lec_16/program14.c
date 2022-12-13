// https://www.geeksforgeeks.org/difference-between-p-p-and-p/
#include <stdio.h>
int main(void)
{
    int arr[] = {10, 20};
    int *p = arr;
    // ++*p; // arr[0] = 11, precedence of * is higher than ++, so *p is incremented first
    // *p++; // 20, precedence of ++ is higher than *, so p is incremented first
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr[0], arr[1], *p);
    return 0;
}
