// Print all possible strings of length k that can be formed from a set of n characters

#include <stdio.h>
#include <stdlib.h>

void print_strings(char *set, int n, int k, char *str, int i);

int main(void)
{
    char set[] = {'a', 'b', 'c'};
    int n = 3;
    int k = 2;
    char *str = malloc(k * sizeof(char));
    print_strings(set, n, k, str, 0);
}

void print_strings(char *set, int n, int k, char *str, int i)
{
    // base case
    if (i == k)
    {
        for (int j = 0; j < k; j++)
            printf("%c", str[j]);
        printf("\n");
        return;
    }

    // recursive case
    for (int j = 0; j < n; j++)
    {
        str[i] = set[j];
        print_strings(set, n, k, str, i + 1);
    }
}
