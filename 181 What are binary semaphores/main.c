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

int *pi_fuel;

void *routine( void *args )
{
    // sem_wait( &semFuel  );
    // pthread_mutex_lock( &mutexFuel );
    *pi_fuel += 50;
    printf( "Current value is %d\n", *pi_fuel );
    // pthread_mutex_unlock( &mutexFuel );
    sem_post( &semFuel );
}

int main( int argc, char const *argv[] )
{
    pthread_t th[THREAD_COUNT];
    pi_fuel  = malloc( sizeof( int ) );
    *pi_fuel = 50;
    // sem_init( &semFuel, 0, 1 );
    sem_init( &semFuel, 0, 0 );

    // pthread_mutex_init( &mutexFuel, NULL );

    int i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_create( &th[i], NULL, &routine, NULL ) != 0 )
        {
            perror( "Failed to create thread" );
        }
    }

    // Only the main thread execute the routine
    sem_wait( &semFuel );
    printf( "Deallocating fuel\n" );
    free( pi_fuel );
    // For all threads to compute the fuel comet upper 3 lines
    // Uncoment the routine comented lines (without the mutex or leve only the mutex)

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
