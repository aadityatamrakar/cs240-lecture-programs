/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>

#define LOWERCASE 1
#define UPPERCASE 2

/**
 * @name: print_alphabets
 * @brief  This function prints the binary representation of a char
 * @param  n: number of char to be printed
 * @param  letter_case: lower/upper case
 *
 */
void print_alphabets(unsigned char n, int letter_case)
{
  unsigned char i;
  for (i = 0; i < n; i++)
  {
    switch (letter_case)
    {
    case LOWERCASE:
      printf("%c", 'a' + i);
      break;
    case UPPERCASE:
      printf("%c", 'A' + i);
      break;
    default:
      printf("Invalid letter case");
      break;
    }
  }
  printf("\n");
}

int main(void)
{
  // ascii code for 'a' is 97
  // ascii code for 'A' is 65
  char c1 = 65;
  unsigned c2 = 66;

  printf("%d: %c\n", c1, c1);
  printf("%d: %c\n", c2, c2);

  printf("10 alphabets in lower case: \t");
  print_alphabets(10, LOWERCASE);
  printf("All alphabets in upper case: \t");
  print_alphabets(26, UPPERCASE);

  return 0;
}

// To Run: gcc 1_char.c -o 1_char && ./1_char && rm 1_char