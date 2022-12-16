#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
    // p1 is pointer but p2 is not
    int *p1, p2;

    // str is an array of 20 pointers of characters
    char *str[20];
    // prints 20 * 8
    printf("%lu\n", sizeof(str));  

    return 0;
}