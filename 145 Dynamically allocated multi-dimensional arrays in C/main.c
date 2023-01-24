#include <stdio.h>
#include <stdlib.h>

int main( int argc, char const *argv[] )
{
    // int arr[3][3] = { 
    //     { 1, 1, 1 }, 
    //     { 2, 2, 2 }, 
    //     { 3, 3, 3 } 
    // };
    // printf("Stack array size: %lu\n", sizeof(arr));
    int **arr = malloc(sizeof(int*) * 3);
    int i = 0;
    for ( i = 0; i < 3; i++)
    {
        arr[i] = malloc(sizeof(int) * 3); 
    }
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 1;
    printf("Heap array pointer size: %lu\n", sizeof(arr));
    // The real size of the heap array should be 8 + (8 * 3) + (4 * 3 * 3) = 68 bytes;
    printf("Heap array size: %lu\n", sizeof(arr) + sizeof(arr[0]) * 3 + sizeof(int) * 3 * 3);

    // Free allocated memory
    for ( i = 0; i < count; i++)
    {  // First the sub arrays
        free(arr[i]);
        arr[i] = NULL;
    }  // Then the main
    free(arr);
    arr = NULL;
    
    return 0;
}
