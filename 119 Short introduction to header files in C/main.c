#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

int main( int argc, char const *argv[] )
{
    char str[100] = "The apples are delicious apples apples.";

    printf( "%s\n", str );

    while ( string_replace( str, 100, "apples", "hamburgers" ) )
        ;

    printf( "%s\n", str );

    return 0;
}
