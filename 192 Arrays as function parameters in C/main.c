#include <stdio.h>
#include <stdlib.h>

// void printSize(int arrParam[5])  // This
// void printSize(int arrParam[])   // and this will decay to the next example
void printSize( int *arrParam, size_t size )
{
    printf( "Arr in func is of size %lu\n", sizeof( arrParam ) );
    arrParam[0] = 10;  // this will actualy change the original array
}

void printSize2( int *dereffedMatrix, size_t size )
{
    printf( "Matix in func is of size %lu\n", sizeof( dereffedMatrix ) );
    dereffedMatrix[2 * size + 2] = 10;  // this will crash the program
}

int main( int argc, char const *argv[] )
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    printf( "Arr in main is of size %lu\n", sizeof( arr ) );
    printSize( arr, 5 );  // arr -> int*
    printf( "Arr[0] should be 1 but after func printSize is now %d\n", arr[0] );

    int matrix[5][5] = { 
            { 1, 2, 3, 4, 5 }, 
            { 1, 2, 3, 4, 5 }, 
            { 1, 2, 3, 4, 5 }, 
            { 1, 2, 3, 4, 5 }, 
            { 1, 2, 3, 4, 5 } 
        };
    printf( "Matrix in main is of size %lu\n", sizeof( matrix ) );
    printSize2( ( int * ) matrix, 5 );  // arr -> int (*)[5]
    printf( "Arr[2][2] should be 3 but after func printSize2 is now %d\n", matrix[2][2] );

    return 0;
}
