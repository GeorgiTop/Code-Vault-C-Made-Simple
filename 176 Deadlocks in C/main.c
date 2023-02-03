#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define THREAD_COUNT 8

pthread_mutex_t mutexFuel;
int             gFuel = 50;
pthread_mutex_t mutexWatter;
int             gWatter = 10;

void *routine( void *args )
{
    // if ( rand() == 0 )
    // {
        pthread_mutex_lock( &mutexFuel );
        sleep(1);
        pthread_mutex_lock( &mutexWatter );
    // }
    // else
    // {
    //     pthread_mutex_lock( &mutexWatter );
    //     sleep(1);
    //     pthread_mutex_lock( &mutexFuel );
    // }
    gFuel += 50;
    gFuel = gWatter;
    printf( "incremented Fuel to: %d and set Watter to%d\n", gFuel, gWatter );
    pthread_mutex_unlock( &mutexFuel );
    pthread_mutex_unlock( &mutexWatter );
}

int main( int argc, char const *argv[] )
{
    pthread_mutex_init( &mutexFuel, NULL );
    pthread_mutex_init( &mutexWatter, NULL );
    pthread_t th[THREAD_COUNT];
    int       i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_create( &th[i], NULL, &routine, NULL ) != 0 )
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
    printf( "Fuel: %d\n", gFuel );
    pthread_mutex_destroy( &mutexFuel );
    pthread_mutex_destroy( &mutexWatter );
    return 0;
}
