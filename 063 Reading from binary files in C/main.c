#include <stdio.h>

typedef struct Point
{
    int x, y;
} Point;

int main( int argc, char const *argv[] )
{
    // Initial data Point to write in a file
    Point p1 = { .x = 42, .y = -7 };
    // Data Point to read from a file and use later
    Point p2;

    // Read buffer handler
    FILE *in;
    // Write buffer handler
    FILE *out;

    // WRITE

    // File to write in binary
    // fopen_s( &out, "point.bin", "wb" );
    // if ( out == NULL )
    // {
    //     return 1;
    // }

    // size_t elements_rwitten = fwrite( &p1, sizeof( Point ), 1, out );
    // fclose(out);
    // if ( elements_rwitten == 0 )
    // {
    //     return 2;
    // }

    // READ

    // Open file and read binary binary data to buffer
    fopen_s( &in, "point.bin", "rb" );

    if ( in == NULL )
    {
        return 3;
    }

    size_t elements_read = fread( &p2, sizeof( Point ), 1, in );
    // size_t elements_read = fread_s( &p2, sizeof( Point ), sizeof( Point ), 1, in );

    fclose( in );

    if ( elements_read == 0 )
    {
        return 4;
    }

    printf( "Point read from binary file: %d, %d\n", p2.x, p2.y );

    return 0;
}
