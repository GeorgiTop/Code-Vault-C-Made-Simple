#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int arr[5] = {2, 7, 8, 5, 7};
    int n = 5;

    int i, foundIndex = -1;

    // for (i = n-1; n>=0; i--) // reversed iteration
    for (i = 0; i <= n; i++)
    {
        if (arr[i] == 7)
        {
            foundIndex = i;
            break;
        }
    }

    // if (i <= n)              // for reversed iteration
    if (i >= n)
    {
        printf("Nothing found\n");
    }
    else
    {
        printf("Found element 7 at index %d\n", i);
    }

    return 0;
}
