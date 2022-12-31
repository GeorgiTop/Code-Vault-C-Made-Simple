#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point
{
    char *ptr; // Adding a simple pointer
    int   x, y;
} Point;

int main( int argc, char *argv[] )
{
    // The preformance of text read/write is worse than binary
    // The Portability of the program will be GOOD
    // and the pointer addition will not break on 32/64 bit systems
    Point p1 = { .ptr = 0x11, .x = 13, .y = -1 };
    Point p2;

    FILE *file;

    file = fopen( "point.dat", "w+" );
    if ( file == NULL )
    {
        fclose( file );
        return 1;
    }

    size_t bytes_wrote = fprintf( file, "%d, %d, %p\n", p1.x, p1.y, p1.ptr );
    if ( bytes_wrote <= 0 )
    {
        fclose( file );
        return 2;
    }

    fseek( file, 0, SEEK_SET );
    
    // -- READ --
    int elements_read = fscanf_s( file, "%d, %d, %p\n", &p2.x, &p2.y, &p2.ptr );
    fclose( file );
    if ( elements_read < 3 )
    {
        return 3;
    }

    printf( "Read from text file the point: %d, %d, %p\n", p2.x, p2.y, p2.ptr );

    return 0;
}
