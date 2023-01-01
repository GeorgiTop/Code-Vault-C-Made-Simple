#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[256];
    unsigned short i;
    for (i = 0; i < 256; i++)
    {
        arr[i] = -5;
        printf("%d ", arr[i]);
    }
    
    return 0;
}
