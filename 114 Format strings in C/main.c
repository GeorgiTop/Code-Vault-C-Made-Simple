#include <stdio.h>
#include <stdlib.h>

#define POINT_FORMAT "(%lf, %lf)"

typedef struct point
{
    double x, y;
} Point;

void process(Point q)
{
    // ...
    q.x += 5;
    printf(POINT_FORMAT"\n", q.x, q.y);
}

int main(int argc, char const *argv[])
{
    Point p = {
        .x = 10,
        .y = 25
    };
    char buf[100];

    process(p);
    snprintf(buf, 100, POINT_FORMAT"\n", p.x, p.y);

    printf("%s", buf);
    return 0;
}
