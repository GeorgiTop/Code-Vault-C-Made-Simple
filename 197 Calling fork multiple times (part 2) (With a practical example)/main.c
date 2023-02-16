// TODO: for homework https://youtu.be/VzCawLzITh0?t=1418

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROCESS_COUNT 8

int main( int argc, char const *argv[] )
{
    int pipes[PROCESS_COUNT + 1][2];
    int pids[PROCESS_COUNT];
    int i;
    // create pipes
    for ( i = 0; i < PROCESS_COUNT + 1; i++ )
    {
        if ( pipe( pipes[i] ) == -1 )
        {
            printf( "Error with creating pipe\n" );
            return 1;
        }
    }

    // create procesess
    for ( i = 0; i < PROCESS_COUNT; i++ )
    {
        pids[i] = fork();
        if ( pids[i] == -1 )
        {
            printf( "Error with creating process\n" );
            return 2;
        }

        // child process job
        if ( pids[i] == 0 )
        {
            // closing unneeded pipes
            int j;
            for ( j = 0; j < PROCESS_COUNT + 1; j++ )
            {
                // Close the read end
                if ( j != i )
                {
                    close( pipes[j][0] );
                }
                // Close the write end
                if ( i + 1 != j )
                {
                    close( pipes[j][1] );
                }
            }

            // get work info
            int x;
            if ( read( pipes[i][0], &x, sizeof( int ) ) == -1 )
            {
                printf( "Error at reading\n" );
                return 3;
            }

            // do the work
            printf( "(%d) got %d\n", i, x );
            x++;

            // share the work result
            if ( write( pipes[i + 1][1], &x, sizeof( int ) ) == -1 )
            {
                printf( "Error at writing\n" );
                return 4;
            }
            // close the I/O pipe of the process
            printf( "(%d) Sent %d\n", i, x );
            close( pipes[i][0] );
            close( pipes[i + 1][1] );

            // break; // child process will Live after the berak.
            return 0;  // child process will end before the end of the for loop
        }
    }

    // if all children processes have returned
    // only main process works

    // closing unneeded pipes
    int j;
    for ( j = 0; j < PROCESS_COUNT + 1; j++ )
    {
        // Close the read ends
        if ( j != PROCESS_COUNT )
        {
            close( pipes[j][0] );
        }
        // Close the write ends
        if ( j != 0 )
        {
            close( pipes[j][1] );
        }
    }

    int y = 5;
    printf( "Main process sent %d\n", y );

    // main sends work to child
    if ( write( pipes[0][1], &y, sizeof( int ) ) == -1 )
    {
        printf( "Error at writing\n" );
        return 4;
    }
    // read result form last child's work
    if ( read( pipes[PROCESS_COUNT][0], &y, sizeof( int ) ) == -1 )
    {
        {
            printf( "Error at reading\n" );
            return 3;
        }
    }

    // Other final work for main process
    printf( "The final result is %d\n", y );
    // Close main I/O pipe ends
    close( pipes[0][1] );
    close( pipes[PROCESS_COUNT][0] );

    // wait for all child processes to end execution
    for ( i = 0; i < PROCESS_COUNT; i++ )
    {
        wait( NULL );
    }
    return 0;
}
