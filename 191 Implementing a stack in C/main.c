#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[256];
int count = 0;

void push( int x )
{
    if ( count == 256 )
    {

        printf( "No more space in the queue\n" );
        return;
    }
    stack[count++] = x;
}

int pop()
{
    if ( count == 0 )
    {
        fprintf(stderr, "No elements to extract from stack\n");
        // printf("No elements to extract from stack\n");
        exit( 1 );
    }    
    return stack[--count];
}

int main( int argc, char const *argv[] )
{
    push( 1 );
    push( 2 );
    push( 3 );
    push( 4 );
    push( 5 );

    int i;
    int n = count;
    for ( i = 0; i < n; i++ )
    {
        printf( "%d ", pop() );
    }
    printf( "\n" );
    return 0;
}
