#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display( char **output )
{
    printf( "%s\n", *output );
    *output = "This is Another test";
}

int main( int argc, char const *argv[] )
{
    char *str = "This is a test";
    // char *str2 = &str;
    // char **str3 = &str2;
    // char ***str4 = &str3;
    // char ****str5 = &str4;
    display( &str );
    printf("%s\n", str);
    return 0;
}
