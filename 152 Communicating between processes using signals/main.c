#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int x = 0;

void handle_sigusr1( int sig )
{
    if ( x == 0 )
    {
        printf( "\n(HINT) Rember that multiplication is repetitive addition. \n" );
    }
}

int main( int argc, char const *argv[] )
{
    int pid = fork();
    if ( pid == -1 )
    {
        return 1;
    }
    if ( pid == 0 )
    {  // Child
        sleep( 5 );
        kill( getppid(), SIGUSR1 );
    }
    else
    {  // Parent
        struct sigaction sa;
        sa.sa_handler = &handle_sigusr1;
        sa.sa_flags   = SA_RESTART;
        sigaction( SIGUSR1, &sa, NULL );

        printf( "What is the result of 3 * 5: " );
        scanf( "%d", &x );
        if ( x == 15 )
        {
            printf( "Correct!\n" );
        }
        else
        {
            printf( "Wrong!\n" );
        }
        wait( NULL );
    }

    return 0;
}
