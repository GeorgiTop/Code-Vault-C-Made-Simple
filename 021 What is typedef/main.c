#include <stdio.h>
#include <stdlib.h>

/* create short alias for unsigned long long type - uint64 */
typedef unsigned long long uint64;

/* create structure AND give it alias */
typedef struct Point
{
    double x, y;
} Point;

int main(int argc, char const *argv[])
{
    Point p;
    p.x = 0.24;
    p.y = 0.78;
    printf("x = %.2lf\ny = %.2lf\n", p.x, p.y);
    uint64 l = 14;
    printf("l = %llu\n", l);
    return 0;
}
