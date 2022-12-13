#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[] = "CS240",
         str2[] = " - ",
         str3[] = "Programming in C";

    printf("sizeof str1 = %lu\n", sizeof(str1));
    printf("sizeof str2 = %lu\n", sizeof(str2));
    printf("sizeof str3 = %lu\n", sizeof(str3));

    char str4[sizeof(str1) + sizeof(str2) + sizeof(str3)];

    // concatenates str1 and str2
    // the resultant string is stored in str1.
    // char *strcat(char *dest, const char *src)
    // dest − This is pointer to the destination array, which should contain a C string, and should be large enough to contain the concatenated resulting string.
    // src − This is the string to be appended. This should not overlap the destination.
    strcat(str4, str1);
    strcat(str4, str2);
    strcat(str4, str3);
    
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("str3 = %s\n", str3);
    printf("str4 = %s\n", str4);

    return 0;
}