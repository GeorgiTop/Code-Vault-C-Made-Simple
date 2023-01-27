#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigtstp(int sig)
{
    printf("Stop not allowed!\n");
}

void handle_sigcont(int sig)
{
    fflush(stdin);
    printf( "Input a number: " );
    fflush(stdout);
}

int main(int argc, char const *argv[])
{
    struct sigaction sa;
    // sa.sa_handler = &handle_sigtstp;
    sa.sa_handler = &handle_sigcont;
    sa.sa_flags = SA_RESTART;
    // sigaction(SIGTSTP, &sa, NULL);
    sigaction(SIGCONT, &sa, NULL);
    
    // same execution as above, but sigaction is more portable
    // signal(SIGTSTP, &handle_sigstp);

    int x = 0;
    printf( "Input a number: " );  
    scanf( "%d", &x );
    printf( "result %d * 5 = %d\n", x, ( x * 5 ) );

    return 0;
}
