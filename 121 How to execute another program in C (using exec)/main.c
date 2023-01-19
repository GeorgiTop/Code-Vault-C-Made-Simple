#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>  // for windows
// #include <unistd.h>  // for Linux
#include <errno.h>

int main( int argc, char const *argv[] )
{
    // // execute with list of arguments
    // _execl( "C:\\Windows\\System32\\ping.exe", "C:\\Windows\\System32\\ping.exe", "google.com", NULL );

    // // execute with list of arguments found in windows PATH
    // _execlp( "ping", "ping", "google.com", NULL );

    // // execute with vector of parameters found in windows PATH
    char *arr[] = { "ping", "google.com", NULL };
    _execvp( "ping", arr );
    
    // // execute with list of parameters found in PATH and Enviroment variables
    // char *env[] = { "TEST=enviroment variable", NULL };
    // _execlpe( "ping", "ping", "google.com", env );

    int err = errno;
    printf( "If you read this the exec function failed to run\n" );
    return 0;
}
