// https://www.programiz.com/c-programming/c-file-input-output

#include <stdio.h>
#include <stdlib.h>

struct threeNum
{
    int n1, n2, n3;
};

int main()
{
    /**
     * Binary files are mostly the .bin files in your computer.
     *
     * Instead of storing data in plain text,
     * they store it in the binary form (0's and 1's).
     *
     * They can hold a higher amount of data,
     * are not readable easily,
     * and provides better security than text files.
     */

    
    int n;
    struct threeNum num;
    FILE *fptr;
    if ((fptr = fopen("test.bin", "wb")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    num.n1 = 1;
    num.n2 = 2;
    num.n3 = 3;

    // size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(&num, sizeof(struct threeNum), 1, fptr);
    // ptr − pointer to the array of elements to be written.
    // size − bytes of each element to be written.
    // nmemb − number of elements, each one with a size of size bytes.
    // stream − pointer to a FILE object that specifies an output stream.

    fclose(fptr);

    struct threeNum num2;
    // opening file again in read mode
    if ((fptr = fopen("test.bin", "rb")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    fread(&num2, sizeof(struct threeNum), 1, fptr);
    printf("n1: %d\tn2: %d\tn3: %d\n", num2.n1, num2.n2, num2.n3);

    fclose(fptr);

    return 0;
}
