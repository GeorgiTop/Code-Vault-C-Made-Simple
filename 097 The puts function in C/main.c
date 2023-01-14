#include <stdio.h>

int main( int argc, char const *argv[] )
{
    char str[] = "hello world";
    int  res   = puts( str );
    // fputs(str, stdout);
    if ( res >= 0 )
    {
        printf( "Success\n" );
    }
    else
    {
        printf( "Failure\n" );
    }
    return 0;
}
