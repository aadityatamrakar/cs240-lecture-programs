// passing struct to threads
#include <stdio.h>   /* standard I/O routines                 */
#include <pthread.h> /* pthread functions and data structures */
#include <stdlib.h>  /* exit() and other standard utilities   */

struct thread_data
{
    int thread_id;
    char *message;
};

/* function to be executed by the new thread */
void *PrintHello(void *data)
{
    struct thread_data *my_data = (struct thread_data *)data; /* data received by thread */

    // pthread_detach(pthread_self());
    printf("Hello from new thread - got %d\n", my_data->thread_id);
    printf("Message is %s\n", my_data->message);
    pthread_exit(NULL); /* terminate the thread */
}

/* like any C program, program's execution begins in main */
int main(int argc, char *argv[])
{
    int rc;              /* return value                           */
    pthread_t thread_id; /* thread's ID (just an integer)          */
    struct thread_data t;          /* data passed to the new thread          */
    
    t.thread_id = 11;
    t.message = "Hello World";

    /* create a new thread that will execute 'PrintHello' */
    rc = pthread_create(&thread_id, NULL, PrintHello, (void *)&t);
    if (rc) /* could not create thread */
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    printf("\nCreated new thread (%u) ... \n", thread_id);
    pthread_join(thread_id, NULL);
    // pthread_exit(NULL); /* terminate the thread */
}
