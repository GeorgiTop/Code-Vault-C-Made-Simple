#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main( int argc, char const *argv[] )
{
    int pid = fork();
    if ( pid == -1 )
    {
        return 1;
    }

    if ( pid == 0 )
    {
        while ( 1 )
        {
            printf( "Some output\n" );
            usleep( 100000 );
        }
    }
    else
    {
        kill( pid, SIGSTOP );
        int t = 1;
        do
        {
            printf("Input number of seconds for execution: ");
            scanf("%d", &t);
            if (t > 0)
            {
                kill(pid, SIGCONT);
                sleep(t);
                kill( pid, SIGSTOP );
            }

        } while ( t > 0 );

        kill( pid, SIGKILL );
        wait( NULL );
    }

    return 0;
}
