#include <stdio.h>
#include <stdlib.h>

int add( const int x, const int y )
{
    // x = x + y;
    return x;
}

int main( int argc, char const *argv[] )
{
    int n = 50;
    int m = 60;

    // Lock the value at a pointer
    
    // const int *number_of_elements = &n;
    // *number_of_elements           = 20;  // error at compile time
    // number_of_elements            = &m;

    // Lock the pointer to a value

    // int *const number_of_elements = &n;
    // *number_of_elements           = 20;
    // number_of_elements            = &m;  // error at compile time

    // Lock the pointer AND the value

    const int *const number_of_elements = &n;
    // *number_of_elements                 = 20;  // error at compile time
    // number_of_elements                  = &m;  // error at compile time

    return 0;
}
