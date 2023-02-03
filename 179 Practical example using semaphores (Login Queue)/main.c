#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>

#define THREAD_COUNT 8

sem_t semaphore;  // usualy more meaningfull name
int giWaiting = 0;

void *routine( void *args )
{
    printf( "(%d) Waiting in the login Queue\n", *( int * ) args );
    sem_wait( &semaphore );
    sleep( 1 );
    printf( "(%d) Logged in\n", *( int * ) args );
    sleep(rand() % 5 + 1 );
    printf( "(%d) Logged out\n", *( int * ) args );
    sem_post( &semaphore );
    free( args );
}

int main( int argc, char const *argv[] )
{
    pthread_t th[THREAD_COUNT];

    sem_init( &semaphore, 0, 2 );
    // second - param indicates multiple Processes,
    // third  - initial semaphore value

    int i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        int *a = malloc( sizeof( int ) );
        *a     = i;
        if ( pthread_create( &th[i], NULL, &routine, a ) != 0 )
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

    sem_destroy( &semaphore );

    return 0;
}
