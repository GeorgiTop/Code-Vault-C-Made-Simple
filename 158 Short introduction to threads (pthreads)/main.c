#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *routine();

int main( int argc, char const *argv[] )
{
    // prep thread struct
    pthread_t t1, t2;
    // create thread in our struct with no additional parametars, "process" - our func and parameters for it
    if ( pthread_create( &t1, NULL, &routine, NULL ) != 0 )
    {
        return 1;
    }
    if ( pthread_create( &t2, NULL, &routine, NULL ) != 0 )
    {
        return 2;
    }
    // wait but for threads
    if ( pthread_join( t1, NULL ) != 0 )
    {
        return 3;
    }
    if ( pthread_join( t2, NULL ) != 0 )
    {
        return 4;
    }
    return 0;
}

void *routine()
{
    printf( "Test from threads\n" );
    sleep( 3 );
    printf( "Ending thread\n" );
}
