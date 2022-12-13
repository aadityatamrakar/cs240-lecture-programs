#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(int argc, char *argv[])
{
    // Question 1
    // Which function is used to get process id?
    // getpid() or getppid() or getid() or getprocessid()
    
    printf("The current process %d \n", getpid());
    printf("The parent process is %d \n", getppid());
    printf("The owner of this process has uid %d \n", getuid());

    while (1)
    {
        // waiting
    }

    return 0;
}
