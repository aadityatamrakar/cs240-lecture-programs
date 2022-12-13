#include <stdio.h>

struct Car
{
    int year;
    char *make;
    char *model;
};

struct Car createCar()
{
    struct Car car;
    car.year = 2019;
    car.make = "Toyota";
    car.model = "Camry";
    return car;
}

void printCar(struct Car car)
{
    printf("Year: %d\tMake: %s\tModel: %s\n", car.year, car.make, car.model);
}

int main()
{
    // createCar returns a struct Car
    struct Car car = createCar();

    // pass struct to function
    printCar(car);

    return 0;
}