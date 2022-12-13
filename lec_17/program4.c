// https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_chapter/libc_26.html#SEC571

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#if defined(_WIN32) || defined(_WIN64)
#define SHELL "cmd.exe"
#define SHELL_ARG "/c"
#include <windows.h>
#else
#define SHELL "/bin/sh"
#define SHELL_ARG "-c"
#include <unistd.h>
#endif

int my_system(const char *command)
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        /* This is the child process.  Execute the shell command. */
        execl(SHELL, SHELL, SHELL_ARG, command, NULL);
        _exit(EXIT_FAILURE);
    }
    else if (pid < 0)
        /* The fork failed.  Report failure.  */
        status = -1;
    else
        /* This is the parent process.  Wait for the child to complete.  */
        if (waitpid(pid, &status, 0) != pid)
            status = -1;
    return status;
}

int main(int argc, char *argv[])
{
    printf("[PID: %d][Parent PID: %d] \n", getpid(), getppid());

    int status = my_system("ps -al");
    printf("status = %d\n", status);
    return 0;
}
