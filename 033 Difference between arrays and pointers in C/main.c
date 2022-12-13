#include <stdio.h>
#include <stdlib.h>

int example(int * l)
{
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 2, 3, 4 };

    int *arrp = arr;

    int * p = malloc( 4 * sizeof(int));
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    // arrp = arrp + 1;
    printf("%p %p %p\n", arr, arrp, p);

    example(p);
    example(arr);

    printf("%16llu %16llu %16llu\n", sizeof(arr), sizeof(arrp), sizeof(p));

    free(p);
    return 0;
}
