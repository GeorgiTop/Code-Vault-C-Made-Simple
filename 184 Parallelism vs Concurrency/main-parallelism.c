#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 2

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void *routine(void *args)
{
    int index = *(int*)args;
    int sum = 0;
    sleep(1);
    for (size_t i = 0; i < 5; i++)
    {
        sum += primes[index+i];
    }
    printf("Local sum: %d\n", sum);
    *(int*)args = sum;
    return args;    
}

int main(int argc, char const *argv[])
{
    pthread_t th[THREAD_COUNT];
    int i;
    for( i=0; i<THREAD_COUNT; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &routine, a) != 0)
        {
            perror("Failed to create thread\n");
        }
    }
    int globalSum = 0;
    for( i=0; i<THREAD_COUNT; i++)
    {
        int* r;
        if (pthread_join(th[i], (void**) &r) != 0)
        {
            perror("Failed to join thread\n");
        }
        globalSum += *r;
        free(r);
    }
    printf("Global sum: %d\n", globalSum);
    return 0;
}
