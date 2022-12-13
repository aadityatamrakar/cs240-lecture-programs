/*
 * Author : Aaditya Tamrakar
 * Description: A program to demo the use of extern variable
 * in C.
 */

#include <stdio.h>

int count;
extern void write_extern();

int main(void)
{
	count = 5;
	write_extern();

	return 0;
}

// source: https://www.tutorialspoint.com/cprogramming/c_storage_classes.htm