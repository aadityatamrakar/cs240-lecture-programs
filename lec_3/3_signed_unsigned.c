/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>

int main(void)
{

  unsigned int a = 1000; // binary 1111101000
  signed int b = -1;  // binary 11111111111111111111111111111111

  if (a > b)
    printf("a is more than b");
  else
    printf("a is less or equal than b");

  return 0;
}

// To Run: gcc 3_signed_unsigned.c -o 3_signed_unsigned && ./3_signed_unsigned && rm 3_signed_unsigned