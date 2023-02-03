// https://youtu.be/l6zkaJFjUbM
// Manage shared memory access
// Checking for if the buffer is full
// Checking for if the buffer is empty

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_COUNT 4

sem_t semEmpty;
sem_t semFull;

pthread_mutex_t mutexBarrier;

int buffer[10];
int count = 0;

void *producer( void *args )
{
    while ( 1 )
    {
        // Produce
        int x = rand() % 100;
        sleep(1);
        // Add to the buffer
        sem_wait( &semEmpty );
        pthread_mutex_lock( &mutexBarrier );
        buffer[count] = x;
        count++;
        pthread_mutex_unlock( &mutexBarrier );
        sem_post( &semFull );
    }
}

void *consumer( void *args )
{
    while ( 1 )
    {
        // Remove from the buffer
        int y = -1;
        sem_wait( &semFull );
        pthread_mutex_lock( &mutexBarrier );
        y = buffer[count - 1];
        count--;
        pthread_mutex_unlock( &mutexBarrier );
        sem_post( &semEmpty );

        // Consume
        sleep( 1 );
        printf( "Got number %d\n", y );
    }
}

int main( int argc, char const *argv[] )
{
    srand( time( NULL ) );
    pthread_t th[THREAD_COUNT];
    pthread_mutex_init( &mutexBarrier, NULL );
    sem_init( &semEmpty, 0, 10 );
    sem_init( &semFull, 0, 0 );

    int i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( i > 0 )
        {
            if ( pthread_create( &th[i], NULL, &producer, NULL ) != 0 )
            {
                perror( "Failed to create thread" );
            }
        }
        if ( pthread_create( &th[i], NULL, &consumer, NULL ) != 0 )
        {
            perror( "Failed to create thread" );
        }
    }
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_join( th[i], NULL ) != 0 )
        {
            perror( "Failed to join thread" );
        }
    }
    sem_destroy( &semFull );
    sem_destroy( &semEmpty );
    pthread_mutex_destroy( &mutexBarrier );
    return 0;
}
