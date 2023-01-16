#include <stdio.h>
#include <stdlib.h>

int main( int argc, char const *argv[] )
{
    int fruit = -1;
    printf( "What is your favourite fruit?\n" );
    scanf_s( "%d", &fruit );
    
    switch ( fruit )
    {
    case 0:
        printf( "You selected apples\n" );
        break;
    case 1:
        printf( "You selected lemons\n" );
        break;
    case 2:
        printf( "You selected oranges\n" );
        break;
    default:
        printf( "No such fruit\n");
        break;
    }
    return 0;
}
