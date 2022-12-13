// running 5 threads to count the prime numbers between 1 and 200000

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

void *PrimeGenerator(void *data)
{
    int *my_data = (int *)data;
    int i, j, flag;

    int count = 0;
    for (i = my_data[0]; i <= my_data[1]; i++)
    {
        flag = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            count++;
        }
    }

    printf("Prime numbers between %d and %d: %d\n", my_data[0], my_data[1], count);
    // pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int rc;
    pthread_t thread_id[] = {0, 0, 0, 0, 0};
    int t[2][2];
    int i;

    for (i = 0; i < 5; i++)
    {
        t[i][0] = 1 + i * 40000;
        t[i][1] = (i + 1) * 40000;

        rc = pthread_create(&thread_id[i], NULL, PrimeGenerator, (void *)t[i]);
        if (rc)
        {
            printf("\n ERROR: return code from pthread_create is %d \n", rc);
            exit(1);
        }
        printf("Created new thread (%u) ... \n", thread_id[i]);
    }

    // wait for all threads to finish
    for (i = 0; i < 5; i++)
    {
        pthread_join(thread_id[i], NULL);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", cpu_time_used);
    pthread_exit(NULL);
}
