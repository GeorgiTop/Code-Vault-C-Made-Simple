#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void *routine()
{
    x += 8;
    sleep( 2 );
    printf( "Value of x: %d\n", x );
    // printf( "Hello from threads\n" );
    // printf( "Hello from thread %d\n", getpid() );
}

void *routine2 ()
{
    sleep( 2 );
    printf( "Value of x: %d\n", x );
}

int main( int argc, char const *argv[] )
{
    pthread_t t1, t2;
    // create thread in our struct with no additional parametars, "process" - our func and parameters for it
    if ( pthread_create( &t1, NULL, &routine, NULL ) != 0 )
    {
        return 1;
    }
    if ( pthread_create( &t2, NULL, &routine2, NULL ) != 0 )
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
