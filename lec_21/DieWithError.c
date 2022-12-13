// http://cs.ecs.baylor.edu/~donahoo/practical/CSockets/textcode.html
#include <stdio.h>  /* for perror() */
#include <stdlib.h> /* for exit() */

void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}
