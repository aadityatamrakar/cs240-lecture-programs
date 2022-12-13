#include "bank_common.h"

int main()
{
    FILE *fptr = accounts_file();

    for (;;)
    {
        int choice;
        printf("---------MENU---------\n");
        printf("1. Add account\n");
        printf("2. Search account\n");
        printf("3. List accounts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("----------------------\n");
        switch (choice)
        {
        case 1:
            add_account(fptr);
            break;
        case 2:
            search_account(fptr);
            break;
        case 3:
            list_accounts(fptr);
            break;
        case 4:
            fclose(fptr);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}