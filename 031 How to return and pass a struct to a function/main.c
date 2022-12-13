#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    double x;
    double y;
} Point;

void getMiddlePoint(Point *out, const Point *a, const Point *b);

int main(int argc, char *argv[])
{
    Point p1 = {
        .x = 1,
        .y = 1
    };
    Point p2 = {
        .x = 3,
        .y = 2
    };
    Point middle;
    
    getMiddlePoint(&middle, &p1, &p2);
    
    printf("%lf, %lf\n", middle.x, middle.y);
    
    return 0;
}

void getMiddlePoint(Point *out, const Point *a, const Point *b)
{
    out->x = (a->x +b->x)/2;
    out->y = (a->y +b->y)/2;
}
