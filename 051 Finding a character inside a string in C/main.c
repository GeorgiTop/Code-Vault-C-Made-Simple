#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    char str[] = "hello, friend!";

    // get a pointer of the FIRST char if it exists in a string
    char* result = strchr(str, 'e');

    // get a pointer of the LAST char if it exists in a string
    // result = strrchr(str, 'e');
    if(result) {
        printf("Character was found\n");
        int index = result - str;
        printf("Position %d\n", index);
    } else {
        printf("Character was not found\n");
    }
    return 0;
}
