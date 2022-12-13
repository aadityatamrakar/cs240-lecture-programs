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
    if (argc != 2)
    {
        printf("Error: Invalid number of arguments passed to the program\n");
        return 1;
    }
    
    // Declare variables
    char ch;

    // Get input from command line and store in ch as a char
    sscanf(argv[1], "%c", &ch);

    // TODO: Print the character and its ASCII value
    printf("ASCII value of character %c is: %d\n", ch, ch);
    return 0;
}
