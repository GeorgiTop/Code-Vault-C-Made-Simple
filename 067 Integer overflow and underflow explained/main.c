#include <stdio.h>

int main( int argc, char const *argv[] )
{
    unsigned char n = 5;

    int i;
    for ( i = 0; i < 10; i++ )
    {
        printf( "%02hhX | %hhu\n", n, n );
        n--;
    }
    return 0;
}
