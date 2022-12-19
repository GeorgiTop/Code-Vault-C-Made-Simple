#include <stdio.h>
#include <stdlib.h>


// 1) Do you need an array used in many other places
// 2) Do you know the max amout of elements?
// int arr[256];
// 3) Is that max amount too big?
    // if yes => use dinamicaly allocated array
int *arr;
size_t arrSize = 256;

int main(int argc, char const *argv[])
{
    arr = calloc(arrSize, sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Array not allocated!");
        return 1;
    }

    arr[10] = 17;

    // double the size of our array
    arrSize *= 2;

    // find (new) place for our array in memmory with the new size in bytes.
    arr = realloc(arr, arrSize * sizeof(int));
        if (arr == NULL)
    {
        fprintf(stderr, "Array not reallocated!");
        return 2;
    }

    printf("%d\n", arr[10]);

    free(arr);
    return 0;
}
