#include <stdio.h>
#include <errno.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    int res = rename( "number2.dat", "number3.dat" );
    if ( res == 0 )
    {
        printf( "File rename successful!\n" );
    }
    else
    {
        char buf[256];
        strerror_s(buf, 256, errno);
        printf( "Failed to rename file with error: %s!\n", buf );
    }
    return 0;
}
