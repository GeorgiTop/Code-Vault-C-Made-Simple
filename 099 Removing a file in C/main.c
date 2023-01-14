#include <stdio.h>
#include <errno.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    int res = remove( "number1.dat" );
    if ( res == 0 )
    {
        printf( "Removed File Successfully!\n" );
    }
    else
    {
        char buf[256];
        strerror_s(buf, 256, errno);
        printf("Failed to remove because: %s\n", buf);
    }
    return 0;
}
