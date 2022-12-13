#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sum(int a, int b)
{
    return a + b;
}

int main(void)
{
    printf("hello\n");

    // exit() performs following operations.
    // * Flushes unwritten buffered data.
    // * Closes all open files.
    // * Removes temporary files.
    // * Returns an integer exit status to the operating system

    // exit(EXIT_SUCCESS);
    // exit(EXIT_FAILURE);

    // abort() does not perform any of the operations that exit() performs.
    // abort();

    // assert() is a macro that evaluates an expression and if the expression is false, it prints an error message and aborts the program.
    assert(sum(1, 2) == 3);

    return 0;
}
