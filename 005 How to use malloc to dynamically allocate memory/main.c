#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int main(void)
{
    /* Asks for int sized memory within the heap */
    int *i = (int *)malloc(sizeof(int));
    /* Gives back the allocated memory*/
    free(i);

    /* Asks for array within the heap */
    int *a = (int *)malloc(3 * sizeof(int));

    a[1] = 3;
    a[2] = 90;

    /* printf("The value of p[0]: %d is grabage(old data), because it was not initialized.", a[0]); */
    printf("The values are %d, %d and %d\n", a[0], a[1], a[2]);

    free(a);

    /* The propper way to instantiate array within the heap - all the values are going to be 0 to begin with*/
    int *p = (int *)calloc(3, sizeof(int));

    p[1] = 42;
    p[2] = 7;

    printf("The values are %d, %d and %d\n", p[0], p[1], p[2]);

    free(p);
    return 0;
}
