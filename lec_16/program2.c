
#include <stdio.h>

// https://gcc.gnu.org/onlinedocs/gcc/Variable-Attributes.html
/* Apply the constructor attribute to myStartupFun() so that it
    is executed before main() */
void myStartupFunction(void) __attribute__((constructor));

/* Apply the destructor attribute to myCleanupFun() so that it
is executed after main() */
void myCleanupFunction(void) __attribute__((destructor));

/* implementation of myStartupFun */
void myStartupFunction(void)
{
    printf("startup code before main()\n");
}

/* implementation of myCleanupFun */
void myCleanupFunction(void)
{
    printf("cleanup code after main()\n");
}

int main(void)
{
    printf("hello\n");
    return 0;
}
