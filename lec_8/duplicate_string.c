#include <stdio.h>
#include <string.h>

int main()
{
    char source[] = "abc";

    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char *target = strdup(source);
    // char *target = strndup(source, 2); // copies first 2 characters

    printf("VAL: source string = %s, target string = %s\n", source, target);

    printf("ADDR: source string = %p, target string = %p\n", source, target);
    source[1] = 'a';
    target[1] = 'c';
    printf("VAL: source string = %s, target string = %s\n", source, target);

    return 0;
}
