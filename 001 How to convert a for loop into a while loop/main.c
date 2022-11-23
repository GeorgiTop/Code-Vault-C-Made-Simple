#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5 };
    int n = 5;
    
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    i = 0;
    while (i < n) 
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}
