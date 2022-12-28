#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    char str[] = "Start stop";
    // str[0] == str[6];

    printf( "%s\n", str );

    // memcpy( str, ( str + 6 ), ( 4 * sizeof( char ) ) );
    // memmove( str, ( str + 6 ), ( 4 * sizeof( char ) ) );

    // Memcpy just takes and places the bites specified
    // depending on the compiler it might
    // or might not work correctly with overlapping adresses

    // Mememove puts the bites in a buffer first then places them

    // memcpy( str, ( str + 2 ), ( 3 * sizeof( char ) ) );
    memmove( str, ( str + 2 ), ( 3 * sizeof( char ) ) );

    printf( "%s\n", str );
    return 0;
}
