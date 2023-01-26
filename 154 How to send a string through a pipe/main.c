// 2 processes
// Child process reads input from the user and sends it to the parent
// Parent and print the result

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main( int argc, char const *argv[] )
{
    int fd[2];
    if ( pipe( fd ) == -1 )
    {
        return 1;
    }

    int pid = fork();
    if ( pid < 0 )
    {
        return 2;
    }

    if ( pid == 0 )
    {
        // Child
        close( fd[0] );
        char str[200];
        printf( "Input text: " );
        fgets( str, 200, stdin );
        // adding the null terminator to the input
        str[strlen( str ) - 1] = '\0';
        size_t strSize         = strlen( str ) + 1;
        if ( write( fd[1], &strSize, sizeof( size_t ) ) < 0 )
        {
            return 3;
        }

        if ( write( fd[1], str, strSize ) < 0 )
        {
            return 4;
        }
        close( fd[1] );
    }
    else
    {
        close( fd[1] );
        char   str[200];
        size_t strSize = 0;
        if ( read( fd[0], &strSize, sizeof( size_t ) ) < 0 )
        {
            return 5;
        }
        if ( read( fd[0], &str, sizeof(char) * strSize ) < 0 )
        {
            return 6;
        }
        printf( "Recieved: %s\n", str );
        close( fd[0] );
        wait(NULL);
    }

    return 0;
}
