#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main( int argc, char const *argv[] )
{
    int x = 2;
    // child
    int pid = fork();
    if ( pid == -1 )
    {
        return 1;
    }
    if ( pid == 0)
    {
        x++;
    }
    sleep( 1 );
    // printf( "Hello from processes\n" );
    printf( "Hello from process id %d with x = %d\n", getpid(), x );
    if ( pid != 0 )
    {
        wait( NULL );
    }
    return 0;
}
