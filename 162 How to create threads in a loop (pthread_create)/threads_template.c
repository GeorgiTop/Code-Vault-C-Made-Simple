#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define THREAD_COUNT 10

void *routine(void *args)
{

}

int main(int argc, char const *argv[])
{
    pthread_t th[THREAD_COUNT]
    int i;
    for( i=0; i<THREAD_COUNT; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread\n");
        }
    }
    for( i=0; i<THREAD_COUNT; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread\n");
        }
    }

    return 0;
}
