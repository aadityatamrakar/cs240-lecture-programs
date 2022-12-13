// https://www.tutorialspoint.com/cprogramming/c_preprocessors.htm

#include <stdio.h>

#if !defined(MESSAGE)
#define MESSAGE "You wish!"
#endif

int main(void)
{
    printf("Here is the message: %s\n", MESSAGE);
    return 0;
}