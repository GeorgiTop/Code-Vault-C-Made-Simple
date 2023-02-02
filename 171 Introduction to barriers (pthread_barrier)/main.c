#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define THREAD_COUNT 5

pthread_barrier_t barrier;

void *routine( void *args )
{
    while ( 1 )
    {
        printf( "waiting at the barrier...\n" );
        sleep(1);
        pthread_barrier_wait( &barrier );
        printf( "We passed the barrier\n" );
        sleep(1);
    }
}

int main( int argc, char const *argv[] )
{
    pthread_t th[THREAD_COUNT];
    pthread_barrier_init( &barrier, NULL, 3 );
    int i;
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

    pthread_barrier_destroy( &barrier );
    return 0;
}
