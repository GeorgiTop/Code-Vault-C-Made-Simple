#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point
{
    int x, y;
} Point;

int main( int argc, char const *argv[] )
{
    // Source Data for WRITING to a file 
    Point p1 = { .x = 42, .y = -7 };

    // Data "Point" for READING from a file or later operations
    Point p2;

    FILE *in;
    FILE *out;

    char buffer_in[256], buffer_out[256];

    // WRITE to a file

    // fopen_s( &out, "point.dat", "w" );
    // if ( out == NULL )
    // {
    //     return 1;
    // }

    // sprintf_s( buffer_out, 256, "%d, %d\n", p1.x, p1.y );

    // size_t bytes_wrote = fwrite( buffer_out, sizeof( char ), strlen( buffer_out ), out );

    // fclose( out );

    // if ( bytes_wrote != strlen( buffer_out ) )
    // {
    //     return 1;
    // };

    // READ from a File

    // Open the File
    fopen_s( &in, "point.dat", "r" );
    if ( in == NULL )
    {
        return 1;
    }

    // Reading the file with fgets as far right or up to 256 bytes from our file stream to our buffer
    if ( fgets( buffer_in, 256, in ) == NULL )
    {
        fclose( in );
        return 1;
    }
    fclose( in );

    
    
    // DeSerialization of our buffer to variable for later use
    sscanf_s( buffer_in, "%d, %d\n", &p2.x, &p2.y );
    
    // Sample usage of our data
    printf( "Read from file the point: %d %d\n", p2.x, p2.y );

    return 0;
}
