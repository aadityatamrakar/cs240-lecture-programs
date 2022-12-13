// getenv demo

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *env_var = getenv("USER");
    printf("USER = %s\n", env_var);
    return 0;
}

