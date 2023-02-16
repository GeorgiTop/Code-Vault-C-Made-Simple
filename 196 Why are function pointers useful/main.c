#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sum( int x, int y )
{
    return x + y;
}

int prod( int x, int y)
{
    return x * y;
}

void shouldNotBeChanged(int (*operation)(int, int))
{
    int a = rand() % 100;
    int b = rand() % 100;

    printf("The result of the operation between %d and %d is %d\n", a, b, operation(a, b));
}

int main( int argc, char const *argv[] )
{
    srand(time(NULL));
    shouldNotBeChanged(&sum);
    shouldNotBeChanged(&prod);

    return 0;
}
