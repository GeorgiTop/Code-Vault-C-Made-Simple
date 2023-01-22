#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/wait.h>

int main( int argc, char const *argv[] )
{

    if ( mkfifo( "myfifo1", 0777 ) == -1 )
    {
        if ( errno != EEXIST )
        {
            printf( "Could not create fifo file\n" );
            printf( "Error # %d\n", errno );
            return 1;
        }
    }
    printf( "Opening...\n" );
    int fd = open( "myfifo1", O_WRONLY );
    if ( fd == -1 )
    {
        printf( "Coudnt not open fifo\n" );
        return 2;
    }
    printf( "Opened\n" );

    int x = 97;
    if ( write( fd, &x, sizeof( x ) ) == -1 )
    {
        printf( "Could not write to file\n" );
        return 3;
    }
    printf( "Written\n" );

    close( fd );    
    printf( "Closed\n" );
    return 0;
}
