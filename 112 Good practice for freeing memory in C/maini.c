#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void process_arr( int ** arr, int n)
{
    // ... some processing
    free(*arr);
    *arr = NULL;
}

int main( int argc, char const *argv[] )
{
    int *arr = malloc( sizeof( int ) * 10 );
    process_arr(&arr, 10);

    if (arr == NULL)
    {
        // .. arr has been freed
    }

    free(arr);
    arr = NULL;
    return 0;
}
