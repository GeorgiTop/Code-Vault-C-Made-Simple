#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, char const *argv[] )
{
    int pid = fork();
    if (pid ==-1)
    {  
        printf("Did not create child process!\n");
        return 1;
    }
    if( pid == 0)
    {   // Child process
        // The exec func will take over the whole child and no other lines in it will be executed.
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
        printf("\nTHIS LINE WILL NOT PRINT\n");
    }
    else
    {  // Parent process
        wait(NULL);
        printf("Sucsess!\n");
    }
    return 0;
}
