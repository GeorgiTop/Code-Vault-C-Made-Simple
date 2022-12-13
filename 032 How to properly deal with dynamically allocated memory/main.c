#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *arr = calloc(256, sizeof(int)); // Usualy not fixed size
    if (arr == NULL)
    {
        return 1;
    }
    // malloc(64 * sizeof(int)); //
    // memset(arr, 0, sizeof(int) * 64);
    arr = realloc(arr, 64 * sizeof(int));
    int i;
    for (i = 0; i < 64; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
