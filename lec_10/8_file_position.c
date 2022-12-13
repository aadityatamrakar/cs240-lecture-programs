// https://www.geeksforgeeks.org/ftell-c-example/
// C program to demonstrate use of ftell()
#include <stdio.h>

int main()
{
    // Opening file in read mode
    FILE *fp = fopen("test.txt", "r");

    // Reading first string
    // char string[20];
    // fscanf(fp, "%s", string);

    // Printing position of file pointer
    // printf("%s\n", string);
    // printf("Position: %ld\n", ftell(fp));

    /**
     * SEEK_SET is a macro defined in stdio.h
     * SEEK_SET is used to set the file pointer to the
     * beginning of the file.
     * More:  
     * SEEK_CUR: current position of the file pointer 
     * SEEK_END: end of the file  
    */

    fseek(fp, 5, SEEK_SET);
    printf("Characters after position 5: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%c", fgetc(fp));
    }
    printf("\n");
    
    rewind(fp);
    printf("Characters after rewind : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%c", fgetc(fp));
    }
    printf("\n");

    // Closing file 
    fclose(fp);
    return 0;
}
