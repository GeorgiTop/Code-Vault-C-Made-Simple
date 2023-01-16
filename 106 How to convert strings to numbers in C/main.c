#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str[] = "210f name";
    // wrong way
    int x = atoi(str);
    printf("The number is %d\n", x);
    // wright way
    char* endPntr;
    long int y = strtol(str, &endPntr, 16);
    printf("The number is %x\n", y);
    printf("We still have: %s  after the number\n", endPntr);
    return 0;
}
