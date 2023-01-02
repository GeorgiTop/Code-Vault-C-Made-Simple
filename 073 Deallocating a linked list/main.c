#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          x;
    struct Node *next;
} Node;

Node *node_init( int value, Node *next_node )
{
    Node *new_node = malloc( sizeof( Node ) );
    if ( new_node == NULL )
    {
        exit( 1 );
    }
    new_node->x    = value;
    new_node->next = next_node;
    return new_node;
}

void insert_end( Node **root, int value )
{
    // Node Init
    Node *new_node = node_init( value, NULL );

    // Insertion point is the start
    if ( *root == NULL )
    {
        *root = new_node;
        return;
    }
    // Search for the last element
    Node *curr = *root;
    while ( curr->next != NULL )
    {
        curr = curr->next;
    }

    // Insertion
    curr->next = new_node;
}

void deallocate( Node **root )
{
    Node *curr = *root;
    while ( curr != NULL )
    {
        Node *aux = curr;
        curr      = curr->next;
        free( aux );
    }
    *root = NULL;
}

void recursive_dealloc( Node **root)
{
    if ((*root)->next != NULL)
    {
        recursive_dealloc( &(*root)->next );
    }
    free( *root );
    *root = NULL;
}

int main( int argc, char const *argv[] )
{
    // Node *root = node_init( 15, NULL );
    Node *root = NULL;
    insert_end( &root, 15 );
    insert_end( &root, -2 );
    insert_end( &root, 42 );

    Node *curr = root;

    printf( "While Loop prints\n" );
    while ( curr != NULL )
    {
        printf( "%d\n", curr->x );
        curr = curr->next;
    }

    printf( "For Loop prints\n" );
    // Node *curr;
    for ( curr = root; curr != NULL; curr = curr->next )
    {
        printf( "%d\n", curr->x );
    }

    recursive_dealloc( &root );

    return 0;
}
