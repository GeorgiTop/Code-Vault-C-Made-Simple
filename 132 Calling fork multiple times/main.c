#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main( int argc, char const *argv[] )
{
    int id1 = fork();  // main process = x; child0 process = 0 , child1 = x, child2 = 0
    int id2 = fork();  // main = z,         child0 = y,          child1 = 0, child2 = 0
    if ( id1 == 0 )
    {
        if ( id2 == 0 )
        {
            printf( "We are process y\n" );
        }
        else
        {
            printf( "We are process x\n" );
        }
    }
    else
    {
        if ( id2 == 0 )
        {
            printf( "We are process z\n" );
        }
        else
        {
            printf( "We are the parent process!\n" );
        }
    }
    // for the main process to wait for all forks to finish exec
    while ( wait( NULL ) != -1 || errno != ECHILD )
    {
        printf( "Waited for a child to finish\n" );
    }
    return 0;
}
