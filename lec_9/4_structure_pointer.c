#include <stdio.h>
#include <stdlib.h>

struct Car
{
    int year;
    char *make;
    char *model;
};

void printCar(struct Car *car)
{
    printf("Year: %d\tMake: %s\tModel: %s\n", car->year, car->make, car->model);
}

int main()
{
    // createCar returns a struct Car
    struct Car car = {2019, "Toyota", "Camry"};

    struct Car *car_ptr = &car;
    
    printCar(car_ptr);

    return 0;
}