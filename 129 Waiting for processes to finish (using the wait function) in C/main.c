/*
Print 10 digits
5 from forked(child) process next 5 from the main process
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>  // linux lib

int main( int argc, char const *argv[] )
{

    int id = fork();  // main id will be some radnom number, the child will end up with id 0
    int n;
    if ( id == 0 )
    {  // this is the child process
        n = 1;
    }
    else
    {  // this is the main process
        n = 6;
    }

    if ( id != 0 )
    {  // if we are in the main process
        wait(NULL);  // for the child to finish its execution, then continue with the main process
    }

    // each process will do this
    int i;
    for ( i = n; i < n + 5; i++ )
    {  
        printf( "%d ", i );
        // clear buffer to avoid bulking of output
        fflush( stdout );
    }

    if ( id != 0 )
    {  // if we are in the main process
        printf( "\n" );
    }

    return 0;
}
