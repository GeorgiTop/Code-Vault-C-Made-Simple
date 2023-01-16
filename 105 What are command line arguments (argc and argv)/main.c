#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    
    int result = 1;
    for( i = 1; i < argc; i++)
    {
        int x = strtol(argv[i], NULL, 10);  // converts our string command line arguments to integers
        result *= x;
    }

    printf("Manipulation result is %d\n", result);
    return 0;
}
