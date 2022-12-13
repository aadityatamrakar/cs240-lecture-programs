// https://learn.microsoft.com/en-us/cpp/preprocessor/token-pasting-operator-hash-hash?view=msvc-170
// preprocessor_token_pasting.c

#include <stdio.h>
#define paster(n) printf("token" #n " = %d\n", token##n)

int main()
{
    int token7 = 7;
    
    paster(7);
    // printf("token7 = %d", token7);
}