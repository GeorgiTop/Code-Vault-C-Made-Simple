#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main( int argc, char const *argv[] )
{
    int arr[5];
    int fd = open( "sum", O_RDONLY );
    if ( fd == -1 )
    {
        printf( "Failed to open file sum\n" );
        return 1;
    }

    int i;
    if ( read( fd, &arr, sizeof( int ) * 5 ) == -1 )
    {
        printf( "Failed to read from file\n" );
        return 2;
    }
    // for ( i = 0; i < 5; i++ )
    // {
    //     if ( read( fd, &arr[i], sizeof( int ) ) == -1 )
    //     {
    //         printf( "Failed to read from file\n" );
    //         return 2;
    //     }
    //     printf( "Recieved %d\n", arr[i] );
    // }
    close( fd );

    int sum = 0;
    for ( i = 0; i < 5; i++ )
    {
        sum += arr[i];
    }
    printf( "Result is %d\n", sum );

    return 0;
}
