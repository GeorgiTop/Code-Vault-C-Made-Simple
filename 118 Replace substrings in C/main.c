#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_replace( char *source, size_t sourceSize, char *substring, char *with )
{
    char *substring_source = strstr( source, substring );
    if ( substring_source == NULL )
    {
        return NULL;
    }
    if ( sourceSize < strlen( source ) + ( strlen( with ) - strlen( substring ) ) + 1 )
    {
        printf( "Buffer size is too small\n" );
        return NULL;
    }
    memmove( substring_source + strlen( with ),
             substring_source + strlen( substring ),
             strlen( substring_source ) - strlen( substring ) + 1 );
    memcpy( substring_source, with, strlen( with ) );

    return substring_source + strlen(with);
}

int main( int argc, char const *argv[] )
{
    char str[100] = "The apples are delicious apples apples.";
    // "The apples are delicious.\0"
    //      ^p
    // strlen(p) -
    // strlen(substring) + 1 (for the null terminator)
    // "The hamburgers are delicious.\0"
    //            [  ]
    // strlen(with) -
    // strlen(substring)

    printf( "%s\n", str );

    while(string_replace( str, 100, "apples", "hamburgers" ));

    printf( "%s\n", str );

    return 0;
}
