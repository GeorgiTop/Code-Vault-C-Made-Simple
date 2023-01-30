#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point
{
    int x;
    int y;
    int val;
} Point;

int main( int argc, char const *argv[] )
{
    // printf("wtf\n");
    FILE *file = fopen( "input.txt", "r" );
    if ( file == NULL )
    {
        return 1;
    }
    char buffer[100];
    fgets( buffer, 100, file );

    // while ( !feof( file ) )
    // {
    //     Point p;
    //     sscanf( buffer, "%d %d %d", &p.x, &p.y, &p.val );
    //     printf( "Read point: %d %d %d\n", p.x, p.y, p.val );
    //     fgets( buffer, 100, file );
    // }

    Point points[100];
    int   i = 0;
    for ( i = 0; !feof( file ); i++ )
    {
        Point *p = points + i;
        sscanf( buffer, "%d %d %d", &p->x, &p->y, &p->val );
        // printf( "Read point: %3d %3d %3d\n", p->x, p->y, p->val );
        fgets( buffer, 100, file );
    }
    int n = i;
    for ( i = 0; i < n; i++ )
    {
        printf( "Point %d: %3d %3d %3d\n", i+1, points[i].x, points[i].y, points[i].val );
    }

    fclose( file );
    return 0;
}
