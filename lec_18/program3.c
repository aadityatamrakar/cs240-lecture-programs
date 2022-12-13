// http://www.csc.villanova.edu/~mdamian/threads/posixthreads.html
// passing data to threads
#include <stdio.h>   /* standard I/O routines                 */
#include <pthread.h> /* pthread functions and data structures */
#include <stdlib.h>  /* exit() and other standard utilities   */

/* function to be executed by the new thread */
void *PrintHello(void *data)
{
    int my_data = (int)data; /* data received by thread */

    // pthread_detach: Detach a thread from the calling thread.
    // The thread will continue to run, but its resources will be
    // automatically released when it terminates.
    
    // pthread_self: Return the thread ID of the calling thread.
    // The thread ID is a value of type pthread_t.

    pthread_detach(pthread_self());
    printf("Hello from new thread - got %d\n", my_data);
    pthread_exit(NULL); /* terminate the thread */
}

/* like any C program, program's execution begins in main */
int main(int argc, char *argv[])
{
    int rc;              /* return value                           */
    pthread_t thread_id; /* thread's ID (just an integer)          */
    unsigned int t = 11;          /* data passed to the new thread          */

    /* create a new thread that will execute 'PrintHello' */
    rc = pthread_create(&thread_id, NULL, PrintHello, (void *)t);
    if (rc) /* could not create thread */
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    printf("\nCreated new thread (%u) ... \n", thread_id);

    // pthread_join is used to wait for the thread to finish
    // arguments: thread_id, return value of the thread
    pthread_join(thread_id, NULL);

    pthread_exit(NULL); /* terminate the thread */
}
