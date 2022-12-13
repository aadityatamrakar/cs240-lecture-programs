// passing array to threads

#include <stdio.h>   /* standard I/O routines                 */
#include <pthread.h> /* pthread functions and data structures */
#include <stdlib.h>  /* exit() and other standard utilities   */

/* function to be executed by the new thread */
void *PrintHello(void *data)
{
    // pthread_detach(pthread_self());
    int *my_data = (int *)data; /* data received by thread */
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Hello from new thread - got %d\n", my_data[i]);
    }
    pthread_exit(NULL); /* terminate the thread */
}

/* like any C program, program's execution begins in main */
int main(int argc, char *argv[])
{
    int rc;              /* return value                           */
    pthread_t thread_id; /* thread's ID (just an integer)          */
    int t[10];           /* data passed to the new thread          */
    int i;
    for (i = 0; i < 10; i++)
    {
        t[i] = i;
    }

    /* create a new thread that will execute 'PrintHello' */
    rc = pthread_create(&thread_id, NULL, PrintHello, (void *)t);
    if (rc) /* could not create thread */
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    printf("\nCreated new thread (%u) ... \n", thread_id);

    pthread_exit(NULL); /* terminate the thread */
}
