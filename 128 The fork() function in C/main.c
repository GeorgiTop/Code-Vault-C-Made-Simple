#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // linux lib

int main( int argc, char const *argv[] )
{
    // int id = fork();
    // printf("Hello world from id: %d\n", id);
    // if (id == 0)
    // {
    //     printf("Hello from child process\n");
    // }
    // else
    // {
    //     printf("Hello from the main process\n");
    // }

    // fork();  // starts another process
    // fork();  // each of the processes starts another child
    // fork();  // 2^n

    int id = fork();
    if ( id != 0 )
    {  //  the main process will have id diferent than 0
        fork();
    }
    //  The folowing lines will be executed 3 times
    printf( "Hello world\n" );

    return 0;
}
