// https://www.programiz.com/c-programming/c-unions

#include <stdio.h>

union unionJob
{
    char name[32];
    float salary;
    int workerNo;
};

struct structJob
{
    char name[32];
    float salary;
    int workerNo;
} sJob;

int main()
{
    union unionJob uJob;
    struct structJob sJob;

    printf("size of union = %lu bytes\n", sizeof(uJob));
    printf("size of structure = %lu bytes\n", sizeof(sJob));

    uJob.salary = 18.5;
    uJob.workerNo = 100;

    printf("uJob salary: %.1f\nuJob workerNo: %d\n", uJob.salary, uJob.workerNo);

    sJob.salary = 18.5;
    sJob.workerNo = 100;

    printf("sJob salary: %.1f\nsJob workerNo: %d\n", sJob.salary, sJob.workerNo);

    return 0;
}