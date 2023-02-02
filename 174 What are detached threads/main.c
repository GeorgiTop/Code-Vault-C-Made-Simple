

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define THREAD_COUNT 2

void *routine( void *args )
{
    sleep( 1 );
    printf( "Finished execution\n" );
}

int main( int argc, char const *argv[] )
{
    pthread_t      th[THREAD_COUNT];
    pthread_attr_t detachedThread;
    // There might be a case where the thread might finish its execution right between 
    // and pthread_create / pthread_detach => 
    //   - ther resources could heve been freed automaticaly if detached
    //   - can't be joined later 
    pthread_attr_init( &detachedThread );
    pthread_attr_setdetachstate( &detachedThread, PTHREAD_CREATE_DETACHED );

    // thereare lots of states to set - check them out;

    int i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_create( &th[i], &detachedThread, &routine, NULL ) != 0 )
        {
            perror( "Failed to create thread\n" );
        }
        // pthread_detach( th[i] );
    }

    // for( i=0; i<THREAD_COUNT; i++)
    // {
    //     if (pthread_join(th[i], NULL) != 0)
    //     {
    //         perror("Failed to join thread\n");
    //     }
    // }
    pthread_attr_destroy( &detachedThread );
    pthread_exit( 0 );
    // return 0;
}
