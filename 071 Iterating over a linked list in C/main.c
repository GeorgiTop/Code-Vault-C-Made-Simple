#include <stdio.h>
#include <stdlib.h>

/*
Normal iteration for
        Arrays      Linked Lists
init    int i=0     Node *curr = &root;
cond    i<n         curr != NULL;
iter    i++         curr=cur->next;

*/

typedef struct Node
{
    int          x;
    struct Node *next;
} Node;

int main( int argc, char const *argv[] )
{
    Node root;
    root.x                = 15;
    root.next             = malloc( sizeof( Node ) );
    root.next->x          = -2;
    root.next->next       = malloc( sizeof( Node ) );
    root.next->next->x    = 42;
    root.next->next->next = NULL;

    Node *curr = &root;

    printf( "While Loop prints\n" );
    while ( curr != NULL )
    {
        printf( "%d\n", curr->x );
        curr = curr->next;
    }

    printf( "For Loop prints\n" );
    // Node *curr;
    for ( curr = &root; curr != NULL; curr = curr->next )
    {
        printf( "%d\n", curr->x );
    }

    free( root.next->next );
    free( root.next );

    return 0;
}
