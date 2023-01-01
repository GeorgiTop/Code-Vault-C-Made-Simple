#include <stdio.h>

int func( int *p )
{
    ( *p )++;
    return *p;
}

int main( void )
{
    int x = 5;

    printf( "Size:  %llu\n", sizeof( func( &x ) ) );
    // sizeof() tries to figure out the size at compile time
    // it will not actualy call inside functions or execute operators
    printf( "Value: %d\n", x );

    return 0;
}
