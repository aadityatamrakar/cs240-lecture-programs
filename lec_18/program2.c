// threads demo

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int main(int argc, char *argv[])
{
    pthread_t thread_id;
    /**
     * pthread_create() creates a new thread within the calling process.
     * The new thread starts execution by invoking thread_function().
     * The thread terminates when thread_function() returns.
     * The thread ID of the new thread is returned in thread_id.
     *
     * pthread_create( thread_id, attr, thread_function, arg )
     * thread_id: pointer to a pthread_t variable that is set by this function to the ID value for the new thread.
     * attr: pointer to a pthread_attr_t structure whose contents are used at thread creation time to determine attributes for the new thread; this argument is optional and should be NULL if the default thread attributes are to be used.
     * thread_function: pointer to a function that is to be executed by the new thread.
     * arg: pointer to a variable that is passed as the sole argument of thread_function.
     *
     */
    int ret = pthread_create(&thread_id, NULL, thread_function, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
        return 1;
    }
    
    pthread_join(thread_id, NULL);
    printf("Thread created with id %ld\n", thread_id);
    return 0;
}

void *thread_function(void *arg)
{
    printf("Hello from thread\n");
    return NULL;
}
