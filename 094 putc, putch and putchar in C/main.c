#include <stdio.h>

int main( int argc, char const *argv[] )
{
    // int res = putch('e');  // obsolite, only in windows?
    // int res = fputchar('e');  // depricated name, does't work with file streams

    int res = putchar('e');
    // int res = putc('e', stdout);  // same as above
    // int res = fputc( 'e', stdin );  // works with file streams, can be used for write check.
    if ( res == EOF )
    {
        printf( "Error\n" );
    }
    else
    {
        printf( "Result: %c\n", res );
    }
    return 0;
}
