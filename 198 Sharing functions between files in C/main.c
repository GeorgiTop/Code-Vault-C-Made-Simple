#include <stdio.h>
#include <stdlib.h>

int getSum( int x, int y );
int otherFunction( int x, int y );

int main( int argc, char const *argv[] )
{
    printf( "Sum is %d\n", otherFunction( 15, 20 ) );
    return 0;
}
