#include <stdio.h>

struct student
{
    char name[30];
    unsigned int isActive : 1;
};

int main()
{
    // 2 bit field
    struct student s1 = {"John", 1};

    printf("Name: %s\tisActive: %d\n", s1.name, s1.isActive);
    return 0;
}