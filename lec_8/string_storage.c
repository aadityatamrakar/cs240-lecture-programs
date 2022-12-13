// https://www.geeksforgeeks.org/storage-for-strings-in-c/

#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------*/
int main()
{
    char str[] = "C-240"; /* Stored in stack segment like other auto variables */
    *(str + 1) = 'S'; 
    // str[1] = 'S';
    printf("%s\n", str);
    return 0;
}


/*----------------------------------------------------*/
// int main()
// {
//     int size = 4;

//     /* Stored in heap segment like other dynamically allocated things */
//     char *str = (char *)malloc(sizeof(char) * size);
//     *(str + 0) = 'A';
//     *(str + 1) = ' ';
//     *(str + 2) = 'C';
//     *(str + 3) = '\0';
//     *(str + 1) = 'B';
//     printf("%s\n", str);
//     return 0;
// }


/*----------------------------------------------------*/


/*----------------------------------------------------*/
// char *getString()
// {
//     char *str = "ABC"; /* Stored in read only part of shared segment */
//     // *(str + 1) = ' ';
//     return str;
// }

/*----------------------------------------------------*/
// char *getString()
// {
//     int size = 4;
//     char *str = (char *)malloc(sizeof(char) * size); /*Stored in heap segment*/
//     *(str + 0) = 'A';
//     *(str + 1) = 'B';
//     *(str + 2) = 'C';
//     *(str + 3) = '\0';
//     return str;
// }
// int main()
// {
//     printf("%s\n", getString());
//     return 0;
// }

/*----------------------------------------------------*/
// char *getString()
// {
//     static char str[] = "ABC"; /* Stored in stack segment */

//     /* Problem: string may not be present after getString() returns */
//     return str;
// }

// int main()
// {
//     printf("%s\n", getString());
//     return 0;
// }
