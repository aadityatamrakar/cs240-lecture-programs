/*
 * Author : Haoyu Wang
 * Description:
 *
 */

#include <stdio.h>

// char ascii(int c) {
// 	return c;
// }

// main() {
// 	printf("%c\n", ascii(65));
// }

int main(int argc, char *argv[])
{
	for (int j = 0, i=0; j < 2; j++) {
		printf("A");
		if(i == 1) continue;
		for ( ; ; ) {
			printf("B");
			if (i == 0) {
				i++;
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{

		if (i > 5)
			continue;
		printf("%d\t", i);
	}
	printf("%c", ascii_value(65));
	printf("\n");

	return 0;
}