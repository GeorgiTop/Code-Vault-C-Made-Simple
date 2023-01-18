#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    char str1[100] = "my name is ";
    char str2[] = "Bob Jordan aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    // string concatenate with limit number to copy
    strncat(str1, str2, 100 - strlen(str1) - 1);
    
    printf("%s\n", str1);
    printf("%zu\n", strlen(str1));


    return 0;
}
