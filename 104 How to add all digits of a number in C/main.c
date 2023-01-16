#include <stdio.h>

int sumOfDigits( int n )
{
    int sum = 0;
    while ( n > 0 )
    {
        int d = n % 10;
        n     = n / 10;
        sum += d;
    }
    return sum;
}

int main( int argc, char const *argv[] )
{
    int x = 38511;  // 385 / 10 = q: 38, r: 5
    // int d1 = x % 10;  // 5
    // x = x / 10;       // 38
    // int d2 = x % 10;  // 8
    // x = x / 10;       // 3
    // int d3 = x % 10;  // 3

    // int sum = d1 + d2 + d3;
    int sum = sumOfDigits( x );

    printf( "%d\n", sum );
    return 0;
}
