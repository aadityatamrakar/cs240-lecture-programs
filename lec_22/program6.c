// https://www.programiz.com/c-programming/examples/remove-characters-string

#include <stdio.h>
int main()
{
    char line[150];

    printf("Enter a string: ");
    fgets(line, sizeof(line), stdin); // take input

    for (int i = 0, j; line[i] != '\0'; ++i)
    {

        // enter the loop if the character is not an alphabet
        // and not the null character
        while (!(line[i] >= 'a' && line[i] <= 'z') && !(line[i] >= 'A' && line[i] <= 'Z') && !(line[i] == ' ') && !(line[i] == '\0'))
        {
            for (j = i; line[j] != '\0'; ++j)
            {

                // if jth element of line is not an alphabet,
                // assign the value of (j+1)th element to the jth element
                line[j] = line[j + 1];
            }
            line[j] = '\0';
        }
    }
    printf("Output String: ");
    puts(line);
    return 0;
}

/*

This program takes a string input from the user and stores in the line variable. Then, a for loop is used to iterate over characters of the string.

If the character in a string is not an alphabet, it is removed from the string and the position of the remaining characters are shifted to the left by 1 position.
*/