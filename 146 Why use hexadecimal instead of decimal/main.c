#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    // int x = 23;  // 00010111
    int x = -13;  // 0000 1101
    printf( "Decimal     - %d\n", x );
    printf( "Hexadecimal - %x\n\n", x );


    // Little endian will store the smallest values to the left
    // 01 00 00 00 - allowing for "growing" numbers to just fill the next address (if free)
    // and reduce the number of operations
    
    // Big endian will store the biggest numbers to the left
    // 00 00 00 01 - much like a normal decimal representation
    // like  most languages read (Left to right)
    int arr[4] = { 1, 5, -3, 22 };
    int i      = 0;
    for ( i = 0; i < 16; i++ )
    {
        printf( "%02hhx ", *( ( ( char * ) arr ) + i ) );
        if ( ( ( i + 1 ) % 4 ) == 0 )
        {
            int idx = (( i + 1 ) / 4) -1;
            printf( " => %2d", arr[idx] );
            printf( "\n" );
        }
    }

    return 0;
}
