#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    char     str[]  = "200 22 111";
    char *   cursor = str;
    long int sum    = 0;
    while ( cursor != str + strlen( str ) )
    {
        long int x = strtol( cursor, &cursor, 10 );

        // while ( *cursor == " " || *cursor == ',' )
        // {
        //     cursor++;
        // }

        sum += x;
    }
    printf( "Sum is %ld\n", sum );
    return 0;
}
