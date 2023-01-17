#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double rand_double()
{
    return ( ( double ) rand() ) / ( ( double ) RAND_MAX );
    // 1 / 32767
}

double rand_double_interval( double a, double b )
{
    // [0, 1] => [0,5] => [5,10]
    return rand_double() * ( b - a ) + a;
}

int main( int argc, char const *argv[] )
{
    srand( time( NULL ) );
    int i;
    for ( i = 0; i < 100; i++ )
    {
        // printf( "%lf ", rand_double() );
        printf( "%lf ", rand_double_interval( 5, 10 ) );
    }

    return 0;
}
