#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    char str[] = "Here is an example";

    int *arr = malloc( sizeof( int ) * 16 );

    size_t i;
    for ( i = 0; i < strlen( str ); i++ )
    {
        // ..
        printf( "%zu\n", i );
    }

    return 0;
}
