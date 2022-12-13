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
	int a[] = {1, 2, 3}, b[3], *p;
	// b = a;
	p = a;
	// for (int i=0;i<3;i++)
	// 	b[i] = a[i];

	memcpy(b, a, sizeof(a));

	for (int i = 0; i < 3; i++)
		printf("%d\t", b[i]);
	printf("\n");

	int c = 1, d = 0;
	// memcpy(c,d,sizeof(c));
	memcpy(&c, &d, sizeof(c));

	printf("%d\n", c);

	return 0;
}