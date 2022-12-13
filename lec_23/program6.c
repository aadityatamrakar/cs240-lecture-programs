/*C program to read array elements and print with addresses.*/
#include <stdio.h>

int main()
{
    int arr[5]; // declare integer array
    int *pa;     // declare an integer pointer
    int i;

    pa = &arr[0]; // assign base address of array

    printf("Enter array elements:\n");
    for (i = 0; i < 5; i++)
    {
        printf("Enter element %02d: ", i + 1);
        scanf("%d", pa + i); // reading through pointer
    }

    printf("\nEntered array elements are:");
    printf("\nAddress\t\tValue\n");
    for (i = 0; i < 5; i++)
    {
        printf("%p\t%03d\n", (pa + i), *(pa + i));
    }

    return 0;
}
