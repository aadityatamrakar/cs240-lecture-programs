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
    if (argc != 4)
    {
        printf("Error: Invalid number of arguments passed to the program\n");
        return 1;
    }

    // Declare variables
    char operation;
    int num1, num2, result;

    // Get input from command line and store in num as a int
    sscanf(argv[1], "%d", &num1);
    sscanf(argv[2], "%c", &operation);
    sscanf(argv[3], "%d", &num2);

    // operation: +, -
    if (operation == '+')
        result = num1 + num2;
    else if (operation == '-')
        result = num1 - num2;
    else
        printf("Invalid operation");

    printf("Result: %d\n", result);
}
