#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char const *argv[] )
{
    int arr[][5] = { 
        { 1, 1, 1, 1, 1 }, 
        { 2, 2, 2, 2, 2 }, 
        { 3, 3, 3, 3, 3 }, 
        { 4, 4, 4, 4, 4 }, 
        { 5, 5, 5, 5, 5 } 
        };
                //    up  ur  r dr dwn dl lft  ul
    int offsety[] = { -1, -1, 0, 1, 1,  1,  0, -1};
    int offsetx[] = {  0,  1, 1, 1, 0, -1, -1, -1};
    
    // Note - no input bound checks
    int x, y;
    printf("Input X: ");
    scanf("%d", &x);
    printf("Input Y: ");
    scanf("%d", &y);
    
    int i;
    int sum = arr[y][x];
    for (i = 0; i < 4; i++)
    {
        // Neighbor to x
        int nx = x + offsetx[i];
        int ny = y + offsety[i];
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4)
        {
            continue;
        }
        sum += arr[ny][nx];
    }
    
    printf("The sum is %d\n", sum);

    return 0;
}
