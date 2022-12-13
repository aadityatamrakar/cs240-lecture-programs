// printing sum of numbers from 1 to 10 using thread

#include <stdio.h>   /* standard I/O routines                 */
#include <pthread.h> /* pthread functions and data structures */
#include <stdlib.h>  /* exit() and other standard utilities   */

struct thread_data
{
    int thread_id;
    int sum;
    int numbers[10];
};

void *add(void *data)
{
    struct thread_data *my_data = (struct thread_data *)data; /* data received by thread */
    int i;
    for (i = 0; i < 10; i++)
    {
        my_data->sum += my_data->numbers[i];
    }
    pthread_exit(NULL); /* terminate the thread */
}

int main(int argc, char *argv[])
{
    int rc;
    pthread_t thread_id;
    struct thread_data t;
    
    // initialize the data structure to be passed to the thread
    int i;
    for (i = 0; i < 10; i++)
    {
        t.numbers[i] = i + 1;
    }
    t.sum = 0;

    // create a new thread that will execute 'add'
    rc = pthread_create(&thread_id, NULL, add, (void *)&t);
    if (rc)
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    printf("\nCreated new thread (%u) ... \n", thread_id);
    // wait for the thread to finish
    pthread_join(thread_id, NULL);
    printf("Sum of numbers from 1 to 10: %d\n", t.sum);
    // terminate the thread
    pthread_exit(NULL);
}
