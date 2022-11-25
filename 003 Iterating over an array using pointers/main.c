#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int arr[] = {7, 8, 9, 10, 11};
    int n = 5;

    printf("Start address: %d\nEnd address:   %d\n", &arr[0], &arr[4]);

    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int *p;
    for (p = &arr[0]; p <= &arr[4]; p++) {
        printf("%d ", p);
    }
    return 0;
}
