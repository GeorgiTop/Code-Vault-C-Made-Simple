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

sem_t           semFuel;
pthread_mutex_t mutexFuel;

int fuel = 50;

void *routine1( void *args )
{
    while ( 1 )
    {  
        sem_wait( &semFuel );
        // pthread_mutex_lock( &mutexFuel );
        fuel += 50;
        printf( "Current value is %d\n", fuel );
    }
}

void *routine2( void *args )
{
    while ( 1 )
    {
        sem_post( &semFuel );
        // pthread_mutex_unlock( &mutexFuel );  // Undefined behaviour => will break at some point
        usleep( 5000 );
    }
}

int main( int argc, char const *argv[] )
{
    pthread_t th[THREAD_COUNT];
    // fuel  = malloc( sizeof( int ) );
    // *fuel = 50;
    sem_init( &semFuel, 0, 1 );
    // sem_init( &semFuel, 0, 0 );

    pthread_mutex_init( &mutexFuel, NULL );

    int i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( i % 2 == 0 )
        {
            if ( pthread_create( &th[i], NULL, &routine1, NULL ) != 0 )
            {
                perror( "Failed to create thread" );
            }
        }
        else
        {
            if ( pthread_create( &th[i], NULL, &routine2, NULL ) != 0 )
            {
                perror( "Failed to create thread" );
            }
        }
    }

    // sem_wait( &semFuel );
    // printf( "Deallocating fuel\n" );
    // free( fuel );

    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_join( th[i], NULL ) != 0 )
        {
            perror( "Failed to join thread" );
        }
    }
    sem_destroy( &semFuel );
    pthread_mutex_destroy( &mutexFuel );
    return 0;
}
