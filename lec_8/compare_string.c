#include <stdio.h>
#include <string.h>

int main()
{
    char str1[13];
    char str2[13];

    strcpy(str1, "CS240");
    strcpy(str2, "CS240");

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    // strcoll - compare two strings
    // int strcoll(const char *str1, const char *str2)
    int ret = strcoll(str1, str2);

    if (ret > 0)
        printf("str1 is greater than str2, %d\n", ret);
    else if (ret < 0)
        printf("str1 is lesser than str2, %d\n", ret);
    else
        printf("str1 is equal to str2, %d\n", ret);
    
    // strcmp - compare two strings
    // int strcmp(const char *str1, const char *str2)
    int res = strcmp(str1, str2);

    if (res == 0)
        printf("Strings are equal");
    else
        printf("Strings are unequal");

    printf("\nValue returned by strcmp() is: %d\n", res);

    return (0);
}

// https://www.geeksforgeeks.org/strcoll-in-cc/
