#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool arr[2] = {true, false};
    printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);

    if (arr[0])
        printf("arr[0] is true\n");
    else
        printf("arr[0] is false\n");

    return 0;
}
