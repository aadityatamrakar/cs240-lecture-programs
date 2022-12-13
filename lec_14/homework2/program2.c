#include <stdio.h>

int largest_element(int numbers[], int num)
{
    int largest = numbers[0];
    for (int i = 1; i < num; i++)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
    }
    return largest;
}

int main()
{
    int count;
    // TODO: read count
    scanf("%d", &count);

    int numbers[count];
    
    // TODO: read numbers
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("%d\n", largest_element(numbers, count));

    return 0;
}