// https://en.wikipedia.org/wiki/C\_preprocessor

#include <stdio.h>

#ifdef __unix__
#include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef __unix__
    sleep(1);
#elif defined _WIN32
    Sleep(1000);
#endif

    printf("Hello World!\n");
    return 0;
}
