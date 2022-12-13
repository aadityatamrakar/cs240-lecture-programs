#include <stdio.h>

// structure definition
struct Car
{
    int year;
    char make[50];
    char model[50];
};

int main()
{
    // Declare a variable of type struct address
    struct Car c1;

    // Get input from user and store in the variable
    printf("Enter year: ");
    scanf("%d", &c1.year);
    printf("Enter make: ");
    scanf("%s", c1.make);
    printf("Enter model: ");
    scanf("%s", c1.model);

    // printf
    printf("Sizeof c1: %lu\n", sizeof(c1));
    printf("Sizeof c1.make: %lu\n", sizeof(c1.make));
    printf("Sizeof c1.year: %lu\n", sizeof(c1.year));
    printf("Sizeof c1.model: %lu\n", sizeof(c1.model));

    // print values
    printf("Year: %d\tMake: %s\tModel: %s\n", c1.year, c1.make, c1.model);
    
    return 0;
}