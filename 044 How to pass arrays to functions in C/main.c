#include <stdio.h>
#include <stdlib.h>

int sum(int *arr, int n)
{
    int i, s = 0;
    arr[0] = 10;
    for (i = 0; i < n; i++)
    {
        s+= arr[i];
    }
    // printf will give us the size of the pointer to the array not the actual array size
    // printf("Size: %llu\n", sizeof(arr)); 
    return s;
}

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7};
    int s = sum(arr, 7); //sum
    
    printf("Sum : %d\n", s);
    printf("First element: %d\n", arr[0]);
    // printf will give us the size of  the array
    printf("Size: %llu\n", sizeof(arr));

    return 0;
}
