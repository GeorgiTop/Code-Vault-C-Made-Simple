#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_interval( int a, int b )
{
    return rand() % ( b - a ) + a;
}

int main( int argc, char const *argv[] )
{
    srand( time( NULL ) );
    // [0, 10] + 4 => [4, 14]
    int i;
    for ( i = 0; i < 100; i++ )
    {
        // printf("%d ",rand() % 100 + 50);
        printf( "%d ", rand_interval( 5, 20 ) );
    }

    return 0;
}
