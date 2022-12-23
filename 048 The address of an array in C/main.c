#include <stdio.h>
#include <stdlib.h>

int main( int argc, char const *argv[] )
{
    int x = 15;
    printf( "Value: %d\n", x );
    printf( "Address: %p\n", &x );

    char str[16] = "Example string";
    printf( "Value: %s\n", str );
    printf( "Address: %p\n", str );
    printf( "Address: %p\n", str + 1 );
    printf( "Address: %p\n", &str + 1 );
    printf( "Size of array: %llu\n", sizeof( str ) );

    return 0;
}
