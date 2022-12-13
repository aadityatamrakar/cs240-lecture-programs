#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n, i;

    scanf("%d", &n);
    
    ptr = (int *)malloc(n * sizeof(int));

    int sum = 0;
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &ptr[i]);
        sum += ptr[i];
    }

    printf("%.2f\n", (float)sum / n);

    free(ptr);
    
    return 0;
}
