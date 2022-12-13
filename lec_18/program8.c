// return a value from thread

#include <pthread.h>
#include <stdio.h>

void *myThread(void *data)
{
    int *my_data = (int *)data;
    printf("Thread ID: %u\n", pthread_self());
    printf("Data: %d\n", *my_data);

    // returning a null pointer from a thread
    pthread_exit((void *)my_data);
}

int main()
{
    pthread_t tid;
    void *status = 0;
    int data = 100;

    pthread_create(&tid, NULL, myThread, &data);
    pthread_join(tid, &status);

    // status is a pointer to the data returned by the thread
    // typecast it to the correct type before using it
    printf("Status: %d\n", *(int *)status);

    return 0;
}