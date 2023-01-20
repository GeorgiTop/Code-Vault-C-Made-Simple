#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void process(int* arr)
// {
//     //for single dimention
// }
// void process(int** arr)
// {
//     //for multi dimention
// }

int main( int argc, char const *argv[] )
{
    // Array inits
    // int arr[9] = { 2, 7, 10, 12, 22, -20, 11, 5, 15 };           // simulated Matrix
    // int arr[][3] = { {2, 7, 10}, {12, 22, -20}, {11, 5, 15} };   // Stack Matrix
    int ** arr = malloc(sizeof(int*) * 3);                          // Heap Matrix
    int i, j;
    for ( i = 0; i < 3; i++)
    {
        arr[i] = malloc(sizeof(int) * 3);
    }
    
    // Iterating over the Matrix
    for ( i = 0; i < 3; i++ )
    {
        for ( j = 0; j < 3; j++ )
        {
            // process(arr);
            // printf( "%d ", arr[i * 3 + j] );             // Simulated Matrix needs math for indexing
            //  // dereference may look like -> *(*(arr + i) + j)
            printf( "%d ", arr[i][j] );  
        }
        printf("\n");
    }

    // free the Matrix
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            free(arr[i][j]);
            arr[i][j] = NULL;
        }
        free(arr[i]);
        arr[i] = NULL;
    }
    
    return 0;
}
