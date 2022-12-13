/*
* Author : Haoyu Wang
* Description:
*	The break statement causes an immediate exit from the switch .
	Because cases serve just as labels, after the code for one case
	is done, execution falls through to the next unless you take explicit action to escape.
*
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	for (int i = 0; i < 10; i++)
	{
		switch (i)
		{
		case 8:
			printf("%d\n", i);
		case 9:
			printf("%d\n", i);
			break;
		case 0:
		case 1:
			printf("%d\n", i);
			break;

		default:
			printf("Oh!\n");
		}
	}

	return 0;
}