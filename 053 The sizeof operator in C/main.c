#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    int a = 5;
    // sizeof() returns size_t - usaly 64 bit unsigned int
    printf( "Size of an int in bits   : %llu\n", sizeof( int ) );

    int  arr[10] = { 3, 9, 42 };  // -> int*
    int *arrp    = arr;

    printf( "Size of the Array in bits: %llu\n", sizeof( arr ) );
    printf( "Size of a Pointer in bits: %llu\n", sizeof( arrp ) );
    printf( "Number of elements in the Array: %llu\n", (sizeof( arr ) / sizeof( int )) );

    return 0;
}
