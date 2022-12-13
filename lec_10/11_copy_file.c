// https://www.geeksforgeeks.org/basics-file-handling-c/
// C program to Open a File,
// Write in it, And Close the File

#include <stdio.h>
#include <string.h>

int read_file(char *filename)
{
    FILE *fptr;
    char c;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file %s", filename);
        return 1;
    }
    
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }

    // read the file line by line
    char str[60];
    while (fgets(str, 60, fptr) != NULL)
    {
        printf("%s", str);
    }

    // Close file
    fclose(fptr);
    return 0;
}

int main()
{

    FILE *fptr;
    char filename[15];
    char c;
    printf("Enter the filename to be opened : ");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file %s", filename);
        return 1;
    }

    // copy contents from file to another file
    char filename2[15];
    printf("Enter the filename to be copied to : ");
    scanf("%s", filename2);
    FILE *fptr2;
    fptr2 = fopen(filename2, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s", filename2);
        return 1;
    }
    c = fgetc(fptr);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr);
    }
    
    // Close file
    fclose(fptr);
    fclose(fptr2);
    
    return 0;
}
