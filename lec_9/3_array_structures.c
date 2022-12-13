#include <stdio.h>
#include <stdlib.h>

struct Car
{
    int year;
    char *make;
    char *model;
};

void printCar(struct Car car)
{
    printf("Year: %d\tMake: %s\tModel: %s\n", car.year, car.make, car.model);
}

int main()
{
    struct Car cars[] = {
        {2019, "Toyota", "Camry"},
        {2018, "Honda", "Civic"},
        {2017, "Ford", "Fusion"},
        {2016, "Chevy", "Cruze"},
        {2015, "Nissan", "Altima"}
    };

    for (int i = 0; i < 5; i++)
        printCar(cars[i]);

    return 0;
}
