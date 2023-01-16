#include <stdio.h>

int main( int argc, char const *argv[] )
{
    int x, y;
    scanf_s( "%d", &x );
    scanf_s( "%d", &y );
    int max = x > y ? x : y;

    // if ( x > y )
    // {
    //     max = x;
    // }
    // else
    // {
    //     max = y;
    // }

    printf( "Maximum is %d\n", max );
    return 0;
}
