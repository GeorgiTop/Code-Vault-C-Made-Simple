#include <stdio.h>

void f(void)
{
    char c = getchar();
    printf( "Again the same result: %c\n", c );
}

int main( int argc, char const *argv[] )
{
    char c = getchar();
    printf( "Rresult %c\n", c );
    // ungetc(c, stdin);  // returns the read value back to the stream
    int res = ungetc('f', stdin);  //  can't actualy write to a file but only changes the stream seen by the computer
    if (res == EOF)
    {
        printf("Error\n");
    }
    f();
    return 0;
}
