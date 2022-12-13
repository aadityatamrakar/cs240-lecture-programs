#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid = fork(); // fork a child process

    printf("[pid: %d]\n[getpid(): %d][getppid(): %d] \n", pid, getpid(), getppid());

    if (pid == 0) // child process
    {
        char *args[] = {"ps", "-a", NULL};
        execvp("ps", args);

        // args contains the command line arguments
        // for the new process
        // execv replaces the current process with the new process
        // execv returns only if there is an error

        printf("This line will not be printed\n");
    }
    else // parent process
    {
        wait(NULL); // wait for child to finish
        printf("This line will be printed\n");
    }
    return 0;
}
