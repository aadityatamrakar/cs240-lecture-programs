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

	int a = 3;

	// while(a == 9)
	// 	printf("a is 0\n");

	switch (a)
	{
		case 0:
			printf("a is 0\n");
			break;
		case 1:
			printf("a is 1\n");
			break;
		case 2:
			printf("a is 2\n");
			break;
		default:
			printf("default block\n");
	}

	int b = a == 1 ? 1 : 0;

	if(a == 0)
		printf("a is 0\n");
	else if(a == 1)
		printf("a is 1\n");
	else
		printf("a is not 0 or 1\n");

	return 0;
}