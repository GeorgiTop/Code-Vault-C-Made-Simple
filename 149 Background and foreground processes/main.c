#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, char const *argv[] )
{
    int x = 0;
    printf( "Input a number: " );  
    
    // try ctrl+z in the terminal where the app is executing
    // ctrl+z sends SIGTSTP -> pauses the process/sends it to the background
    // now try the command: fg
    // it will send SIGCONT

    scanf( "%d", &x );
    printf( "result %d * 5 = %d\n", x, ( x * 5 ) );
    return 0;
}
