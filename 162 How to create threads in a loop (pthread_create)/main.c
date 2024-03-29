#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 8

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
    int i;
    for ( i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        // read mails
        // increment
        //write mails
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t th[THREADS];
    pthread_mutex_init(&mutex, NULL);

    int i;
    for ( i = 0; i < THREADS; i++)
    {
        if ( pthread_create( &th[i], NULL, &routine, NULL) != 0 )
        {
            perror( "Failed to create thread");
            return i;
        }
        printf("Thread %d has started\n", i);
    }

    for ( i = 0; i < THREADS; i++)
    {
        if ( pthread_join( th[i], NULL ) != 0)
        {
            perror("Thread %d failed execution", i);
            return 2;
        }
        printf("Thread %d has finished execution\n", i);
    }
    
    printf("Number of mails: %d\n", mails);
    pthread_mutex_destroy(&mutex);
    return 0;
}
