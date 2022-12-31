#include <stdio.h>

typedef struct Point
{
    int x, y;
} Point;

int main( int argc, char const *argv[] )
{
    // Source Data for WRITING to a file
    Point p1 = { .x = 42, .y = -7 };

    // Data "Point" for READING file information and later operations
    Point p2;

    FILE *file;

    // WRITE

    // Open file for read and write operations
    fopen_s( &file, "point.dat", "w+" );
    if ( file == NULL )
    {
        fclose( file );
        return 1;
    }

    // Write data to a file
    int bytes_wrote = fprintf( file, "%d, %d\n", p1.x, p1.y );
    // QC check
    if ( bytes_wrote <= 0 )
    {
        fclose( file );
        return 2;
    };
    // fclose( file );

    // Return cursor to beginning of the file so we can read
    fseek( file, 0, SEEK_SET );

    // READ from a File

    // // Open the File for read only
    // fopen_s( file, "point.dat", "r" );
    // if ( file == NULL )
    // {
    //     fclose( file );
    //     return 3;
    // }

    // Pharse file data to variables and check if anything is read.
    int elements_read = fscanf_s( file, "%d, %d\n", &p2.x, &p2.y );
    fclose( file );
    // QC check
    if ( elements_read < 2 )
    {
        return 4;
    }

    // Sample usage of our data
    printf( "Read from binary file the point: %d, %d\n", p2.x, p2.y );

    return 0;
}
