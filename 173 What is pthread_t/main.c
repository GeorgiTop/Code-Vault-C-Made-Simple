// This is showcase we should never use pthread_t as a given as it is not stricly defined as Unsinged Long

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <sys/syscall.h>

#define THREAD_COUNT 2

void *routine( void *args )
{
    pthread_t th = pthread_self();
    printf( "%lu\n", th );
    printf( "%d\n", ( pid_t ) syscall( SYS_gettid ) );  // Linux speciffic
}

int main( int argc, char const *argv[] )
{
    pthread_t th[THREAD_COUNT];
    int       i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_create( &th[i], NULL, &routine, NULL ) != 0 )
        {
            perror( "Failed to create thread\n" );
        }
        printf( "%lu\n", th[i] );
    }
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_join( th[i], NULL ) != 0 )
        {
            perror( "Failed to join thread\n" );
        }
    }

    return 0;
}
