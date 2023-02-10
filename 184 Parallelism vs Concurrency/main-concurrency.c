#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 2

int             mails = 0;
pthread_mutex_t mutex;

void *routine( void *args )
{
    int i;
    for ( i = 0; i < 10; i++ )
    {
        pthread_mutex_lock( &mutex );
        mails++;
        // read mails
        // increment
        // write mails
        printf( "Processing mail #%d\n", mails );
        sleep(1);
        pthread_mutex_unlock( &mutex );
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
    pthread_mutex_destroy( &mutex );
    return 0;
}
