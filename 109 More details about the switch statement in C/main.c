#include <stdio.h>
#include <stdlib.h>

int main( int argc, char const *argv[] )
{
    int fruit = -1;
    // char fruit[100];
    printf( "What is your favourite fruit?\n" );
    scanf_s( "%d", &fruit );
    // fgets( fruit, 100, stdin );
    // fruit[strlen( fruit ) - 1] = 0;

    switch ( fruit )
    {
    case 0:
        printf( "You selected apples\n" );
        break;
    case 1:
    case 2:
        printf( "You selected oranges or lemons\n" );
        break;
    default:
        printf( "No such fruit\n" );
        break;
    }
    return 0;
}
