#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    int a = -34857729;
    int i;
    for ( i = 0; i < 32; i++ )
    {
        // a <<= 1;
        printf( "Left shifted by i: %d: %08X | %u\n", i, ( a << i ), ( a << i ) );
    }

    for ( i = 0; i < 32; i++ )
    {
        // a >>= 1;
        printf( "Right shifted by i: %d: %08X | %u\n", i, ( a >> i ), ( a >> i ) );
    }
    return 0;
}
