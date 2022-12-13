/*
 * Author : Haoyu Wang
 * Description:
 *
 *
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int a = 1, arr[3] = {1, 2, 3};

	// int a[] = {1, 2, 3};
	// int b[10] = {1, 2, 3};
	// int c[5] = {[1] = -1, [4] = -2};

	printf("&a: %p\n", &a);
	printf("a: %d\n", a);
	printf("arr: %p\n", arr);
	printf("&arr: %p\n", &arr);

	// printf("%p, %p\n", &arr, &a);

	// print sizeof a,b,c
	// printf("%d%d%c\n", c[4], a[0], a[1]);
	return 0;
}
