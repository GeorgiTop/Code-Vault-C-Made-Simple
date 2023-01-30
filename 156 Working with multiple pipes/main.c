/*
 * TODO
 * - agregate this program to create "user" defined times processes
 * - agregate them in a loop
 * - add userdefined number (optional)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, char const *argv[] )
{
    // parent to child 1
    // child 1 to child 2
    // child 2 to parent
    int fd[3][2];
    int i = 0;
    for ( i = 0; i < 3; i++ )
    {
        if ( pipe( fd[i] ) < 0 )
        {
            // close other open pipes ?!
            return 1;
        }
    }
    // child 1
    int pid1 = fork();
    if ( pid1 < 0 )
    {
        return 2;
    }
    if ( pid1 == 0 )
    {
        // clean up unused pipe ends
        close( fd[0][1] );
        close( fd[1][0] );
        close( fd[2][0] );
        close( fd[2][1] );
        // work variables
        int x = 0;
        // read from parent
        if ( read( fd[0][0], &x, sizeof( int ) ) < 0 )
        {
            return 3;
        }
        // actual work/
        x += 5;
        // send data trough pipe
        if ( write( fd[1][1], &x, sizeof( int ) ) < 0 )
        {
            return 4;
        }

        close( fd[0][0] );
        close( fd[1][1] );
        return 0;
    }
    // child 2
    int pid2 = fork();
    if ( pid2 < 0 )
    {
        return 5;
    }
    if ( pid2 == 0 )
    {
        close( fd[0][0] );
        close( fd[0][1] );
        close( fd[1][1] );
        close( fd[2][0] );
        int x = 0;
        if ( read( fd[1][0], &x, sizeof( int ) ) < 0 )
        {
            return 6;
        }
        x += 5;
        if ( write( fd[2][1], &x, sizeof( int ) ) < 0 )
        {
            return 7;
        }
        close( fd[1][0] );
        close( fd[2][1] );
        return 0;
    }
    // main
    close( fd[0][0] );
    close( fd[1][0] );
    close( fd[1][1] );
    close( fd[2][1] );

    int x = 0;
    printf( "Input number: " );
    scanf( "%d", &x );
    if ( write( fd[0][1], &x, sizeof( int ) ) < 0 )
    {
        return 8;
    }
    int result = 0;
    if ( read( fd[2][0], &result, sizeof( int ) ) < 0 )
    {
        return 9;
    }

    printf( "Total is: %d\n", result );

    close( fd[0][1] );
    close( fd[2][0] );
    waitpid( pid1, NULL, 0 );
    waitpid( pid2, NULL, 0 );
    return 0;
}
