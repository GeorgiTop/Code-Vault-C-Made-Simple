#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    char str[]     = "Apples are good for your health and good for me too for I am apple-eater";
    char to_find[] = "good";
    char *res = strstr( str, to_find );
    if ( res )
    {   
        printf("%s\n", res);
        printf( "The word has been found at position %llu\n",  (res - str));
    }
    else
    {
        printf("%p\n", res);
        printf( "The word has NOT been found\n" );
    }

    return 0;
}
