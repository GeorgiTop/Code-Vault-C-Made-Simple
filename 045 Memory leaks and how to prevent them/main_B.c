#include <stdio.h>
#include <stdlib.h>

void random_array(int *arr, int n)
{
    // to avoid memmory leaks dont instantiate returned arrays in functions
    // int *arr = malloc(sizeof(int) * n);
    int i;

    srand(0);
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    // we can decide to either use dinamicaly allocated array in the heap
    // int *arr = malloc(sizeof(int) * 15);
    // or use the stack
    int arr[15];

    random_array(arr, 15);

    int i;
    for (i = 0; i < 15; i++)
    {
        printf("%d ", arr[i]);
        // printf("%d ", *(arr++));
    }
    // if we used the heap we have to free the used memmory
    // free(arr);

    // Examples as row 32 and the following
    //arr = NULL;
    //free(arr);
    // will correctly compile and run the code
    // but the result of the free call will not actualy free, the memmory we allocated
    
    // WE MUST TRY TO PAIR THE ALLOCATING CALLS WITH FREE CALLS ON THE SAME FUNCTION
    // if we need piece of memory "everywhere" in our program,\
    // global variables are much easyer to work with
    return 0;
}
