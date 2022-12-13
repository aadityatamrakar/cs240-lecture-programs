/*
 * Author : Aaditya Tamrakar
 * Description: A program to demo getchar() and putchar() in C.
 * 
 */

#include <stdio.h>

int main()
{
	char c;

	printf("Enter character: ");
	c = getchar();

	printf("Character entered: ");
	putchar(c);

	printf("\n");

	return (0);
}