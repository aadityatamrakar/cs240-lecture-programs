#include <stdio.h>

int main()
{
    char c;
    FILE *fp = fopen("test.txt", "r");

    // file modes are r, w, a, r+, w+, a+
    // r: read
    // w: write
    // a: append
    // r+: read and write
    // w+: write and read
    // a+: append and read

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    fclose(fp);

    return 0;
}