#include <stdio.h>
#include <stdlib.h>

int main( int argc, char const *argv[] )
{
    int *offset_x = malloc( sizeof( int ) );
    int *offset_y = malloc( sizeof( int ) );
    if ( offset_x == NULL || offset_y == NULL )
    {
        return 1;
    }
    *offset_x = 10;
    *offset_y = 20;

    // ... more processing

    free(offset_x);
    return 0;
}
