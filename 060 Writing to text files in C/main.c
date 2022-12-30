#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point
{
    int x, y;
} Point;

int main( int argc, char const *argv[] )
{
    Point p1 = { .x = 42, .y = -7 };

    FILE *in;
    FILE *out;

    char buffer_in[256], buffer_out[256];

    fopen_s( &out, "point.dat", "w" );
    if ( out == NULL )
    {
        return 1;
    }

    sprintf_s( buffer_out, 256, "%d, %d\n", p1.x, p1.y );

    size_t bytes_wrote = fwrite( buffer_out, sizeof( char ), strlen( buffer_out ), out );

    fclose( out );

    if ( bytes_wrote != strlen( buffer_out ) )
    {
        return 2;
    };

    return 0;
}
