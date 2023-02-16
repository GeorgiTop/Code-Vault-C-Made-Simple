#include <stdio.h>
#include <stdlib.h>

int f( int x )
{
    if ( x == 0 )
        return 0;

    printf( "Hello from f with x = %d\n", x );
    return x + f( x - 1 );
}

int main( int argc, char const *argv[] )
{
    
    int result = f( 4 );
    printf( "Result of calling f is %d\n", result );
    return 0;
}
