#include <stdio.h>

int main()
{
    int sum = 17, count = 5;

    double mean = (double) sum / count;

    int mean2 = mean;

    printf("Value of mean : %.2f\n", mean);
    printf("Value of mean2 : %d\n", mean2);
    return 0;
}
