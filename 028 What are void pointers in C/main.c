#include <stdio.h>
#include <stdlib.h>

void printBytes(void *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%02x ", ((char*)arr)[i]);
    }    
}

int main(int argc, char const *argv[])
{
    long long arr1[] = { 16, 31, 32, 65 };
    int arr2[] = { 16, 31, 32, 65 };
    printBytes(arr1, 4 * sizeof(long long));
    printf("\n");
    printBytes(arr2, 4 * sizeof(int));
    return 0;
}