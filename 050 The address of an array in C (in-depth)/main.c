#include <stdio.h>
#include <stdlib.h>

void printIntArray( int *arr, size_t num );
void printStrArray( char **arr, size_t num );

int main( int argc, char const *argv[] )
{
    int intArr[3] = { 5, 22, 17 };
    printIntArray( intArr, 3 );

    int numElem = 42;
    printIntArray( &numElem, 1 );

    char *cArr[] = { "Baba", "Dyado" };
    printStrArray( cArr, 2 );

    char *elem = "Tate";
    printStrArray( &elem, 1 );

    // For String array we need to make our own place in memmory for a pointer to a pointer.
    char  arr[5] = "Mama";
    char *ref    = &arr;
    printStrArray( &ref, 1 );
    // printf("&ref:    %p\n", &ref);
    // printf("&refVal: %p\n", ref);

    return 0;
}

void printIntArray( int *arr, size_t num )
{
    int i;
    for ( i = 0; i < num; i++ )
    {
        printf( "%d\n", arr[i] );
    }
}

void printStrArray( char **arr, size_t num )
{
    int i;
    for ( i = 0; i < num; i++ )
    {
        printf( "%s\n", arr[i] );
    }
}