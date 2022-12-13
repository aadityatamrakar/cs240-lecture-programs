#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonebook
{
    char name[20];
    char number[10];
};

int main()
{
    // number of entries in the phonebook
    int n;
    // printf("Enter the number of entries in the phonebook: ");
    scanf("%d", &n);

    // create a phonebook
    struct phonebook *pb = (struct phonebook *)malloc(n * sizeof(struct phonebook));
    for (int i = 0; i < n; i++)
    {
        // printf("Enter the name and number of the %dth entry: ", i + 1);
        scanf("%s %s", pb[i].name, pb[i].number);
    }

    // number of queries
    int q;
    // printf("Enter the number of queries: ");
    scanf("%d", &q);

    // search for the queries
    char query[50];
    for (int i = 0; i < q; i++)
    {
        // query name
        // printf("Enter the name to search: ");
        scanf("%s", query);
        int found = 0;
        for (int j = 0; j < n; j++)
        {
            // match name
            if (strcmp(query, pb[j].name) == 0)
            {
                // print phone number
                printf("%s=%s", pb[j].name, pb[j].number);
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("Not found");
        }
        printf("\n");
    }
    return 0;
}