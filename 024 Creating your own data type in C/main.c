#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point_t
{
    double x;
    double y;
} point_t;

int main(int argc, char const *argv[])
{
    point_t p = {
        p.x = 0.25,
        p.y = 0.78 
        };
    printf("%lf, %lf\n", p.x, p.y);
    return 0;
}
