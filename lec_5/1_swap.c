/*
 * Author : Aaditya Tamrakar
 * Description: A program to demo call by value and 
 * call by reference in C.
 * 
 * Call by value: The value of the actual parameter is copied
 * to the formal parameter. The changes made to the formal
 * parameter are not reflected in the actual parameter.
 * 
 * Call by reference: The address of the actual parameter is
 * copied to the formal parameter. The changes made to the
 * formal parameter are reflected in the actual parameter.
 * 
 */

#include <stdio.h>
#include <ctype.h>

// void swap(int a, int b);

void swap(int a, int b)
{
	printf("values swap(): a=%d\tb=%d\n", a, b);
	// swap the values of a and b here using a temporary variable
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("values swap(): a=%d\tb=%d\n", a, b);
}

void increment(int a[], int len)
{
	// increment each element of the array by 1
	for (int i = 0; i < len; i++)
		a[i] += 1;
}

int main(int argc, char *argv[])
{

	int a = 0, b = 1;
	swap(a, b); // call by value
	printf("Values main(): a=%d\tb=%d\n", a, b);

	int c[] = {1, 2, 3};
	increment(c, sizeof(c) / sizeof(int)); // call by reference

	// print the array
	printf("Incremented array:\n");
	for (int i = 0; i < 3; i++)
		printf("%d\n", c[i]);

	return 0;
}