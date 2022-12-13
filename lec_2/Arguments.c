/**
 * Project: Lec2
 * Name   : Aaditya Tamrakar
 * Date   : 09/08/2022
 * File   : Arguments.c
 * Notes  : prints total argments, program name and first argument
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("The total arguments is %d\n", argc);
    printf("The program name is %s\n", argv[0]);
    printf("The first argument is %s\n", argv[1]);

    int a = 0;
    if (sscanf(argv[1], "%d", &a) != 1)
    {
        fprintf(stderr, "error - not an integer");
    }

    printf("%d\n", a + 5);
    
    return 0;
}
