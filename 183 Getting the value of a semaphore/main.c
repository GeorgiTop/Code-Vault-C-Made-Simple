#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>

#define THREAD_COUNT 4

sem_t sem;

void *routine( void *args )
{
    int index = *(int*)args;
    int semVal;
    sem_wait( &sem );
    sem_getvalue( &sem, &semVal );
    printf("(%d) Current semaphore value is %d\n", index, semVal );
    sem_post( &sem );
    free(args);
}

int main( int argc, char const *argv[] )
{
    pthread_t th[THREAD_COUNT];
    sem_init( &sem, 0, 2 );
    int       i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if ( pthread_create( &th[i], NULL, &routine, a ) != 0 )
        {
            perror( "Failed to create thread\n" );
        }
    }
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_join( th[i], NULL ) != 0 )
        {
            perror( "Failed to join thread\n" );
        }
    }

    sem_destroy( &sem );
    return 0;
}
