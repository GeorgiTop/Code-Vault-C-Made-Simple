#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>

int main( int argc, char const *argv[] )
{
    int x = 15;

    if ( x >= 10 and x <= 20 or x < 0 )
    {
        printf( "Result is true!\n" );
    }
    return 0;
}
