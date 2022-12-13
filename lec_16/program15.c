// https://www.geeksforgeeks.org/what-is-the-best-way-in-c-to-convert-a-number-to-a-string/
#include <stdio.h>
int main()
{
    char result[50];
    float num = 23.34;
    sprintf(result, "%.2f", num);
    printf("The string for the num is %s\n", result);
    getchar();
    return 0;
}