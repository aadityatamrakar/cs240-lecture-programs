#include <stdio.h>

typedef struct Date
{
    int month;
    int day;
    int year;
} date;

typedef struct User
{
    char name[30];
    date dob; // date of birth
} user;

int main()
{
    user u1 = {"John", 4, 10, 1990};

    printf("Name: %s\n", u1.name);
    printf("DOB: %d/%d/%d\n", u1.dob.month, u1.dob.day, u1.dob.year);
    return 0;
}