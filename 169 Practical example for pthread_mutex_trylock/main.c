#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>

#define THREAD_COUNT 10
#define STOVE_COUNT  4

// chefs = threads
// stove = share data (+mutex)
pthread_mutex_t stoveMutex[STOVE_COUNT];
int             stoveFuel[STOVE_COUNT] = { 100, 100, 100, 100 };

void *routine( void *args )
{
    int i;
    for ( i = 0; i < STOVE_COUNT; i++ )
    {
        if ( pthread_mutex_trylock( &stoveMutex[i] ) == 0 )
        {
            int fuelNeeded = ( rand() % 20 );
            if ( stoveFuel[i] - fuelNeeded < 0 )
            {
                printf( "No more fuel... going home\n" );
            }
            else
            {
                stoveFuel[i] -= fuelNeeded;
                usleep( 500000 );
                printf( "Fuel left in stove %d: %d\n", i+1, stoveFuel[i] );
            }
            pthread_mutex_unlock( &stoveMutex[i] );
            break;
        }
        else
        {
            if (i == 3)
            {
                printf("No stove Available yet, waiting...\n");
                usleep(600000);
                i = 0;
            }
        }

    }
}

int main( int argc, char const *argv[] )
{
    srand( time( NULL ) );
    pthread_t th[THREAD_COUNT];

    int i;

    for ( i = 0; i < STOVE_COUNT; i++ )
    {
        pthread_mutex_init( &stoveMutex[i], NULL );
    }
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
    for ( i = 0; i < STOVE_COUNT; i++ )
    {
        pthread_mutex_destroy( &stoveMutex[i] );
    }

    return 0;
}
