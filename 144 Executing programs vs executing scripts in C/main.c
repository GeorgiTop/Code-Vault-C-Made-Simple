#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, char const *argv[] )
{
    int pid = fork();
    if ( pid == -1 )
    {
        printf( "Did not create child process!\n" );
        return 1;
    }
    if ( pid == 0 )
    {  // Child process
        // this will start a program with the given parameters
        int err = execlp( "ping", "ping", "-c", "3", "google.com", NULL );
        // this will not act like script in a terminal, but will give the arguments to the program we want to start
        // int err = execlp( "ping", "ping", "-c", "3", "google.com", "|", "grep", "\"round\"", NULL );
        if ( err == -1 )
        {
            printf( "Could not find program to execute!\n" );
            return 2;
        }
    }
    else
    {  // Parent process
        int wait_status = 0;
        wait( &wait_status );
        if ( WIFEXITED(wait_status) )
        {
            int status_code = WEXITSTATUS(wait_status);
            if ( status_code == 0 )
            {
                printf( "Sucsess!\n" );
            }
            else
            {
                printf( "Failure with status code %d\n", status_code );
            }
        }
    }
    return 0;
}
