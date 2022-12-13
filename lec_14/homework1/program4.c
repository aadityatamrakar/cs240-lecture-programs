/**
 * Project: HW01
 * Name   :
 * Date   :
 * File   :
 * Notes  :
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    // validate input
    if (argc != 2)
    {
        printf("Error: Invalid number of arguments passed to the program\n");
        return 1;
    }

    // Declare variables
    int num;

    // Get input from command line and store in num as a int
    sscanf(argv[1], "%d", &num);

    if (num > 0)
        printf("%d is a positive number\n", num);
    else if (num < 0)
        printf("%d is a negative number\n", num);
    else
        printf("0 is neither positive nor negative\n");
}
