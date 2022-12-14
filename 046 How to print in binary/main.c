#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binaryRepresentation( char *outputArray, void *thingToCheck, int sizeOfThing )
{
    long long i, j;
    for ( i = 0; i < sizeOfThing; i++ )
    {
        // get a byte from the thing
        char byte = ( ( char * ) &thingToCheck )[i];

        // cicle through the bits of the bytes
        for ( j = 7; j >= 0; j-- )
        {
            // get the next bit
            char bit = ( byte >> j ) & 1;
            // add the bit to the output array at the propper index as a char
            outputArray[( i * 8 ) + ( 7 - j )] = bit + '0';
        }
    }
    return;
}

int main( int argc, char const *argv[] )
{
    int a = 2576980377;

    printf( "    Decimal: %d\n", a );
    printf( "Hexadecimal: %08X\n", a );
    printf( "      Octal: %011o\n", a );

    // comment the next 2 lines if you want to try the original from line 40 (it
    // has off by 1 issue)
    char arr[sizeof( int ) * 8 + ( sizeof( int ) )];
    binaryRepresentation( arr, a, sizeof( int ) );

    printf( "     Binary: %s\n", arr );

    // printf( "     Binary: " );
    // // The following 2 for loops will print correcly the memmory representation of
    // // our number thus revealing the endianness of our system.
    // long long i, j;
    // for ( i = 0; i < sizeof( int ); i++ )
    // {
    //     // char byte = *(((char*)&a) + i);
    //     char byte = ( ( char * ) &a )[i];
    //     // for (j = 0; j < 8; j++) // this will give us our number in reverse
    //     for ( j = 8; j >= 0; j-- )  // note the range is 9 not 8 as it is suggested
    //     {
    //         // the following commented lines are part of the thought process for the algorithm
    //         // 1101 & 1 => 1101 & 0001
    //         // => 0001 always gives us the last bit of whatever
    //         // 13 >> 1;
    //         // 1101 >> 1;
    //         // => 110
    //         // char bit = byte & 1;
    //         // byte >>= 1;
    //         char bit = ( byte >> j ) & 1;
    //         printf( "%hhd", bit );
    //     }
    //     printf( " " );
    // }
    // printf( "\n" );

    return 0;
}
