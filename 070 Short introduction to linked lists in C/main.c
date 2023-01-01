#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          x;
    struct Node *next;
} Node;

int main( int argc, char const *argv[] )
{
    // Node root, elem2, elem3;
    // root.x = 15;
    // root.next = &elem2;
    // elem2.x = -2;
    // elem2.next = &elem3;
    // elem3.x = 42;
    // elem3.next = NULL;

    // printf( "First  %d\n", root.x );
    // printf( "Second %d\n", elem2.x );
    // printf( "Third  %d\n", elem3.x );

    Node root;
    root.x                = 15;
    root.next             = malloc( sizeof( Node ) );
    root.next->x          = -1;
    root.next->next       = malloc( sizeof( Node ) );
    root.next->next->x    = 42;
    root.next->next->next = NULL;

    printf( "First  %d\n", root.x );
    printf( "Second %d\n", root.next->x );
    printf( "Third  %d\n", root.next->next->x );

    free( root.next->next );
    free( root.next );

    return 0;
}
