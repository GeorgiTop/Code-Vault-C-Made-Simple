#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

#define THREAD_COUNT 6

pthread_mutex_t mutexFuel;
pthread_cond_t  condFuel;
int             fuel = 0;

void *fuel_filling( void *arg )
{
    printf( "Filling fuel\n" );
    int i;
    for ( i = 0; i < 5; i++ )
    {
        pthread_mutex_lock( &mutexFuel );
        fuel += 30;
        printf( "Filled fuel... %d\n", fuel );
        pthread_mutex_unlock( &mutexFuel );
        // pthread_cond_signal( &condFuel);
        pthread_cond_broadcast( &condFuel);
        sleep( 1 );
    }
}

void *car( void *arg )
{
    // printf( "Here to get fuel\n" );
    pthread_mutex_lock( &mutexFuel );
    while ( fuel < 40 )
    {
        printf( "No fuel. Waiting...\n" );
        pthread_cond_wait( &condFuel, &mutexFuel);
        // unlocks the mutexFuel
        // waits for signal from condFuel
        // locks the mutexFuel
        // continue the while cycle
    }
    fuel -= 40;
    printf( "Got fuel. Now left: %d\n", fuel );
    pthread_mutex_unlock( &mutexFuel );
}

int main( int argc, char const *argv[] )
{
    pthread_t th[THREAD_COUNT];
    pthread_cond_init( &condFuel, NULL );
    pthread_mutex_init( &mutexFuel, NULL );
    int i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( i == THREAD_COUNT - 2 || i == THREAD_COUNT -1 )
        {
            if ( pthread_create( &th[i], NULL, &fuel_filling, NULL ) != 0 )
            {
                perror( "Failed to create fuel thread" );
            }
        }
        else
        {
            if ( pthread_create( &th[i], NULL, &car, NULL ) != 0 )
            {
                perror( "Failed to create car thread" );
            }
        }
    }

    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_join( th[i], NULL ) != 0 )
        {
            perror( "Failed to join thread" );
        }
    }

    pthread_mutex_destroy( &mutexFuel );
    pthread_cond_destroy( &condFuel );
    return 0;
}
