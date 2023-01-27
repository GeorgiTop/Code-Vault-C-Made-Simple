#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

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

        int file = open( "pingResults.txt", O_WRONLY | O_CREAT, 0777 );
        if ( file == -1 )
        {
            return 2;
        }
        // printf( "The fd to pingResults: %d\n", file );
        int file2 = dup2( file, STDOUT_FILENO );
        // printf( "The duplicated fd %d\n", file2 );
        close( file );

        // int err = execlp( "pingr", "pingr", "-c", "3", "google.com", NULL );
        // int err = execlp( "ping", "ping", "-c", "3", "google.con", NULL );
        int err = execlp( "ping", "ping", "-c", "3", "google.com", NULL );
        if ( err == -1 )
        {
            printf( "Could not find program to execute!\n" );
            return 3;
        }
    }
    else
    {  // Parent process
        int wait_status = 0;
        wait( &wait_status );
        if ( WIFEXITED( wait_status ) )
        {
            int status_code = WEXITSTATUS( wait_status );
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
