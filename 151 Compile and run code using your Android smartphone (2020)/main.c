#include <stdio.h>

int add(int a, int b)
{
    return a + b
}

int main( int argc, char const *argv[] )
{
    int x = 0;
    printf( "Hello droids.\n" );
    printf( "Input a number: " );
    scanf( "%d", &x );
    printf( "Result is %d\n", ( x * 5 ) );
    return 0;
}
