#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonebook
{
    char name[20];
    char number[10];
};

FILE *phonebook_file()
{
    FILE *fptr;
    if ((fptr = fopen("phonebook.bin", "ab+")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    return fptr;
}

void add_contact(FILE *fptr)
{
    struct phonebook contact;
    printf("Enter name: ");
    scanf("%s", contact.name);
    printf("Enter number: ");
    scanf("%s", contact.number);
    fwrite(&contact, sizeof(struct phonebook), 1, fptr);
    printf("Contact added successfully\n");
}

void search_contact(FILE *fptr)
{
    struct phonebook contact;
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    rewind(fptr);
    while (fread(&contact, sizeof(struct phonebook), 1, fptr) == 1)
    {
        if (strcmp(contact.name, name) == 0)
        {
            printf("Number: %s\n", contact.number);
            return;
        }
    }
    printf("Contact not found.\n");
}

void list_contacts(FILE *fptr)
{
    struct phonebook contact;
    rewind(fptr);
    printf("Lisiting contacts:\n");
    while (fread(&contact, sizeof(struct phonebook), 1, fptr) == 1)
    {
        printf("Name: %s\tNumber: %s\n", contact.name, contact.number);
    }
}

int main()
{
    // open the phonebook file
    FILE *fptr = phonebook_file();

    // do {} while(1);
    // while(1) {}
    for(;;)
    {
        int choice;
        printf("---------MENU---------\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. List contacts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("----------------------\n");
        switch (choice)
        {
        case 1:
            add_contact(fptr);
            break;
        case 2:
            search_contact(fptr);
            break;
        case 3:
            list_contacts(fptr);
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