/*
A signal between processes will be executed and handeled
no matter what the process that recieves the signal does.
There are a lot of signals in linux !
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
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
        while (1)
        {
            printf("Some tekst goes here\n");
            // usleep is found unistd.h and sleeps the process for n microseconds ( 1 / 1 000 000 )
            usleep(100000); // (100 000 = 1/10 second)

        }
        
    }
    else 
    {
        // sleep - sleeps the process for n seconds
        sleep(1);
        // kill sends signal to a process, and that process deals with it
        kill(pid, SIGKILL);  // "kill yourself" sent to the child process 
        wait(NULL);
    }
    return 0;
}
