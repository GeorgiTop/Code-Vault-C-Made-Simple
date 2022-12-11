#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int arr1[] = { 3, 4 };
    int arr2[] = { 1, 2 };

    if (memcmp(arr1, arr2, 2 * sizeof(int)) == 0)
    {
        printf("Arrays are the same\n");
    }
    else 
    {
        printf("Arrays are NOT the same\n");
    }
    

    memcpy(arr1, arr2, 2 * sizeof(int));
    printf("%d %d\n", arr1[0], arr1[1]);
    // memcmp(arr1, arr2, 2 * sizeof(int)) // Number of elements * size of their type

    memset(arr1, 0, 2 * sizeof(int));
    printf("%d %d\n", arr1[0], arr1[1]);

    if (memchr(arr1, 0, 2 * sizeof(int)) != NULL)
    {
        printf("Found the byte\n");
    }
    else 
    {
        printf("Did not find the byte\n");
    }

    return 0;
}

