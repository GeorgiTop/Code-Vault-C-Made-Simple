#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 4

pthread_mutex_t mutex;

void *routine( void *arg )
{
    // pthread_mutex_lock(&mutex);
    if ( pthread_mutex_trylock( &mutex ) == 0 )
    {
        printf( "Got lock\n" );
        sleep( 1 );
        pthread_mutex_unlock( &mutex );
    }
    else 
    {
        printf("Didn't get lock\n");
    }
}

int main( int argc, char const *argv[] )
{
    pthread_t th[THREAD_COUNT];
    pthread_mutex_init( &mutex, NULL );
    int i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_create( &th[i], NULL, &routine, NULL ) != 0 )
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

    pthread_mutex_destroy( &mutex );
    return 0;
}
