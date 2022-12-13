/* Project: lec3
 * Name   : Haoyu Wang
 * Date   : 01/03/2020
 */
#include <stdio.h>
#include <float.h>


int main(void)
{

    printf("Storage size for float : %lu \n", sizeof(float));
    printf("   FLT_RADIX  : %13d\n",   FLT_RADIX);
    printf("  FLT_ROUNDS  : %13d\n",  FLT_ROUNDS);

    printf("     FLT_DIG  : %13d\n",     FLT_DIG);
    printf(" FLT_EPSILON  : %13g\n", FLT_EPSILON);


    printf("FLT_MANT_DIG  : %13d\n",FLT_MANT_DIG);

    printf("     FLT_MAX  : %13g\n",     FLT_MAX);
    printf("     FLT_MIN  : %13g\n",     FLT_MIN);

    printf(" FLT_MAX_EXP  : %13d\n", FLT_MAX_EXP);
    printf(" FLT_MIN_EXP  : %13d\n", FLT_MIN_EXP);



    printf(" FLT_EPSILON  : %13g\n", FLT_EPSILON);
    printf("%1.30f\n", 0.1f);

    printf(" DBL_EPSILON  : %13g\n", DBL_EPSILON);
    printf("%1.56f\n", 0.1);

  return 0;
}

// To Run: gcc 4_floats_params.c -o 4_floats_params && ./4_floats_params && rm 4_floats_params