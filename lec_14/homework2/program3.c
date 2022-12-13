#include <stdio.h>
int main()
{
    char str1[50], str2[50], str3[100];
    int i = 0, j = 0;

    // TODO: scanf str1 and str2
    scanf("%s", str1);
    scanf("%s", str2);

    // TODO: concatenate str1 and str2 into str3
    // without using strcat()

    while (str1[i] != '\0')
    {
        str3[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0')
    {
        str3[i] = str2[j];
        i++;
        j++;
    }
    str3[i] = '\0';

    printf("%s\n", str3);
    // output: word1word2

    return 0;
}