#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define THREAD_COUNT 8

pthread_mutex_t mutexFuel;
int             gFuel = 50;

void *routine( void *args )
{
    pthread_mutex_lock( &mutexFuel );
    // pthread_mutex_lock( &mutexFuel );
    gFuel += 50;
    printf( "incremented Fuel to: %d\n", gFuel);
    pthread_mutex_unlock( &mutexFuel );
    // pthread_mutex_unlock( &mutexFuel );
}

int main( int argc, char const *argv[] )
{
    pthread_t            th[THREAD_COUNT];
    pthread_mutexattr_t recursiveMutexAttr;
    pthread_mutexattr_init( &recursiveMutexAttr );
    pthread_mutexattr_settype( &recursiveMutexAttr, PTHREAD_MUTEX_RECURSIVE );
    pthread_mutex_init( &mutexFuel, &recursiveMutexAttr );
    // Thread Creation
    int i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_create( &th[i], NULL, &routine, NULL ) != 0 )
        {
            perror( "Failed to create thread\n" );
        }
    }
    // Thread Join
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_join( th[i], NULL ) != 0 )
        {
            perror( "Failed to join thread\n" );
        }
    }
    printf( "Fuel: %d\n", gFuel );
    pthread_mutexattr_destroy( &recursiveMutexAttr );
    pthread_mutex_destroy( &mutexFuel );
    return 0;
}
