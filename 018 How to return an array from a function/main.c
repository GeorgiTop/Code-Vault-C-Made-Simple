#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int *getNextFive(int x);

int main(int argc, char const *argv[])
{
    int x = 5;
    int *arr = getNextFive(x);
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

int *getNextFive(int x)
{
    int *result = malloc(sizeof(int) * 5);
    int i;
    for (i = 0; i < 5; i++)
    {
        result[i] = x + i + 1;
    }
    return result;
}