// this programs will run program 1 to 4 in a loop
// using the system call fork() and exec() to run the programs

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

#define compile_program(n) my_system("gcc program" #n ".c -o program" #n)
#define run_program(n) my_system("./program" #n)

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

    printf("program2 [compile=%d][run=%d]\n", compile_program(2), run_program(2));
    printf("program3 [compile=%d][run=%d]\n", compile_program(3), run_program(3));
    printf("program4 [compile=%d][run=%d]\n", compile_program(4), run_program(4));

    return 0;
}
