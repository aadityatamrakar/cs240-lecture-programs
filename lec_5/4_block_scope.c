/*
 * Author : Aaditya Tamrakar
 * Description: A program to demo block scope in C.
 */

#include <stdio.h>

void increment(int c)
{
	++c;
	printf("c: %p\n", c);
}

void increment_array(int arr[])
{
	++arr[0];
	printf("Arr: %p\n", arr);
}

int main()
{
	int a = 1, b[] = {1};
	
	increment(a); // call by value
	
	int b2[1];
	memcpy(b2, b, sizeof(b));

	increment_array(b2); // call by reference
	
	// printing memory address of a and b
	printf("a: %p\n", a);
	printf("b: %p\n", b);
	

	printf("a: %d, ", a);
	printf("b[0]: %d\n", b[0]);

	return 0;
}