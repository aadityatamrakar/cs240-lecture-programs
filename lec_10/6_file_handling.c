// https://www.geeksforgeeks.org/basics-file-handling-c/
// C program to Open a File,
// Write in it, And Close the File

#include <stdio.h>
#include <string.h>

int read_file(char *filename)
{
    char c;
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file %s", filename);
        return 1;
    }
    
    // Read contents from file
    // c = fgetc(fptr);
    // while (c != EOF)
    // {
    //     printf("%c", c);
    //     c = fgetc(fptr);
    // }

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
    // Declare the file pointer
    FILE *filePointer;

    // Get the data to be written in file
    char dataToBeWritten[50] = "new test data";

    // Open the existing file test.txt using fopen()
    // in write mode using "w" attribute
    filePointer = fopen("test.txt", "w");

    // Check if this filePointer is null
    // which maybe if the file does not exist
    if (filePointer == NULL)
    {
        printf("test.txt file failed to open.");
    }
    else
    {
        printf("The file is now opened.\n");

        // Write the dataToBeWritten into the file
        if (strlen(dataToBeWritten) > 0)
        {

            // writing in the file using fputs()
            // fputs(dataToBeWritten, filePointer);
            // fputs("\n", filePointer);

            // writing in the file using fprintf()
            fprintf(filePointer, "%s\n", dataToBeWritten);

            printf("Data successfully written in file test.txt\n");
        }

        // Closing the file using fclose()
        fclose(filePointer);

        printf("The file is now closed.\n");

        // Open the file again in read mode
        read_file("test.txt");
    }
    return 0;
}
