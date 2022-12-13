#include <stdio.h>

void sort_numbers_ascending(int numbers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (numbers[i] > numbers[j])
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; ++i)
        printf("%d\n", numbers[i]);
}

int main()
{
    int i, count;
    scanf("%d", &count);

    int numbers[count];
    for (i = 0; i < count; ++i)
        scanf("%d", &numbers[i]);

    sort_numbers_ascending(numbers, count);

    return 0;
}