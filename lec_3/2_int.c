/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
  // printf("%f\n", 314);
  // printf("%f\n", 314e);

  // int w = 0xff;

  printf("%lu\n", sizeof(int));
  printf("This if for signed:\n");

  printf("    INT_MAX : %11d\n", INT_MAX);
  printf("1 + INT_MAX : %11d\n", INT_MAX + 1);
  printf("    INT_MIN : %11d\n", INT_MIN);
  printf("INT_MIN - 1 : %11d\n", INT_MIN - 1);

  printf("This if for unsigned:\n");

  printf("    INT_MAX : %11u\n", UINT_MAX);
  printf("1 + INT_MAX : %11u\n", UINT_MAX + 1);
  printf("    INT_MIN : %11u\n", 0);
  printf("INT_MIN - 1 : %11u\n", -1);

  return 0;
}

// To Run: gcc 2_int.c -o 2_int && ./2_int && rm 2_int