#include <stdio.h>
#include <stdlib.h>

int add(int x)
{
    static int sum = 0;
    sum += x;
    return sum;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", add(5));
    printf("%d\n", add(6));
    printf("%d\n", add(5));
    // printf("%d\n", sum);    
    /* The above line will lead to compile error, 
    as the static variable sum only acts as a presistent (global variable),
    but has limited scope.
    */

    return 0;

}
