#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h> // for offsetof()

typedef struct Example
{
    int  x;  // 4 bytes
    char y;  // 1 byte
    // 3 bytes padding
    int z;  // 4 bytes
} Example;

typedef struct Example2
{
    long long x;  // 8 bytes
    Example   e;
} Example2;

int main( int argc, char const *argv[] )
{
    Example t;
    printf( "Size: %llu\n", sizeof( t ) );
    
    printf( "Offset of 'y' is %llu\n", offsetof( Example, y ) );
    printf( "Offset of 'e' within Example 2 is %llu\n", offsetof( Example2, e.y ) );

    return 0;
}
