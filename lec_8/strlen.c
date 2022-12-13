// C program to illustrate strings

#include <stdio.h>
#include <string.h>

int main()
{
    // declare and initialize string
    char str[] = "CS240";

    // print string
    printf("%s\n", str);

    int length_len = strlen(str);
    int length_size = sizeof(str);

    // displaying the length of string
    printf("Length of string str is %d\n", length_len);
    printf("Size of string str is %d\n", length_size);

    return 0;
}
