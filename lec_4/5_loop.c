/*
* Author : Haoyu Wang
* Description:

	// Comma operation:
	// Pairs of expressions separated by a comma , are evaluated left-to-right
	// Value of comma expression is the value of the rightmostcomma-separated expression
*
*/

#include <stdio.h>

int main(int argc, char *argv[])
{

	printf("%d\n", (1, 2));
	char *s, *s1;
	printf("%s\n", (s = "Hey!", s1 = "Ha!"));

	int a[] = {1, 2, 3}, i, j, temp;
	for (i = 0, j = sizeof(a) / sizeof(int) - 1;
		 i < j; i++, j--)
	{

		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	for (i = 0; i < sizeof(a) / sizeof(int); i++)
		printf("%d\t", a[i]);
	putchar('\n');

	return 0;
}