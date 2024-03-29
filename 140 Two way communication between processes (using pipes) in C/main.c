#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <time.h>

int main( int argc, char const *argv[] )
{
    int p1[2];  // child to parent
    if ( pipe( p1 ) == -1 )
    {
        return 1;
    }
    int p2[2];  // parent to child
    if ( pipe( p2 ) == -1 )
    {
        return 1;
    }

    int pid = fork();
    if ( pid == -1 )
    {
        return 2;
    }
    if ( pid == 0 )
    {  // child process
        close(p1[0]);
        close(p2[1]);
        int x;
        if ( read( p2[0], &x, sizeof( x ) ) == -1 )
        {
            return 3;
        }
        printf( "Recieved %d\n", x );

        x *= 4;
        if ( write( p1[1], &x, sizeof( x ) ) == -1 )
        {
            return 4;
        }
        printf( "Wrote %d \n", x );

        close(p1[1]);
        close(p2[0]);
    }
    else
    {  // Parent process
        close(p1[1]);
        close(p2[0]);
        srand( time( NULL ) );
        int y = rand() % 10;
        if ( write( p2[1], &y, sizeof( y ) ) == -1 )
        {
            return 5;
        }
        printf( "Wrote %d\n", y );
        if ( read( p1[0], &y, sizeof( y ) ) == -1 )
        {
            return 6;
        }
        printf("Result is %d\n", y);
        close(p1[0]);
        close(p2[1]);
    }
    return 0;
}
