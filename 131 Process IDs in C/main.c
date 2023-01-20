#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>  // linux lib

int main( int argc, char const *argv[] )
{
    int id = fork();
    if ( id == 0 )
    {  // we are in the child process
        sleep( 1 );
    }  // the parent will/might be done => a new parent ID will be assigned to the child (problems might occure)
    printf( "Current ID: %d, parentID: %d\n", getpid(), getppid() );

    // to avoid the child process becomming a zombe (memmory leak prone)
    // wait for the child process to finish
    int res = wait( NULL );
    if ( res == -1 )
    {
        printf( "No children to wait for\n" );
    }
    else
    {
        printf("%d finished execution\n", res);
    }

    return 0;
}
