/*
 * Author : Aaditya Tamrakar
 * Description: A program to demo the use of register variable
 * in C.
 */

#include <stdio.h>

int main()
{
	register int count = 5;
	while (count--)
		printf("count is %d\n", count);

	return 0;
}
