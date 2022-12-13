// C code to demonstrate the working of strpbrk
#include <stdio.h>
#include <string.h>

// Driver function
int main()
{
	// Declaring three strings
	char s1[] = "abcd";
	char s2[] = "efg";
	char s3[] = "cb";
	char *r1, *r2, *r3;

	// strchr: returns a pointer to the first occurrence of the character
	// in the string
	// strchr(s1, 'a') returns a pointer to the first occurrence of 'a'
	// in s1
	r1 = strchr(s1, 'b');
	if (r1 != 0)
		printf("First matching character: %c\n", *r1);
	else
		printf("Character not found");

	// strpbrk: returns a pointer to the first occurrence of any of the
	// characters that are part of s3 in s1
	// Checks for matching character/
	// no match found
	r2 = strpbrk(s1, s3);
	if (r2 != 0)
		printf("First matching character: %c\n", *r2);
	else
		printf("Character not found");

	// Checks for matching character
	// first match found at "e"
	r3 = strpbrk(s2, s3);
	if (r3 != 0)
		printf("\nFirst matching character: %c\n", *r3);
	else
		printf("Character not found\n");

	return (0);
}

// https://www.geeksforgeeks.org/strpbrk-in-c/