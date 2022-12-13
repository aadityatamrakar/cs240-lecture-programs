/*
 * Author : Aaditya Tamrakar
 * Description: A program to demo the use of extern variable
 * in C.
 */

#include <stdio.h>

extern int count;

void write_extern(void)
{
	printf("count is %d\n", count);
}