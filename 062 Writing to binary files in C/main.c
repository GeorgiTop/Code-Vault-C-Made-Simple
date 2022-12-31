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

    FILE *in;
    FILE *out;

    // WRITE

    // File to write in binary
    fopen_s( &out, "point.bin", "wb" );
    if ( out == NULL )
    {
        return 1;
    }

    size_t elements_rwitten = fwrite( &p1, sizeof( Point ), 1, out );
    fclose(out);
    if ( elements_rwitten == 0 )
    {
        return 2;
    }

    return 0;
}
