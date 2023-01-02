#include <stdio.h>
#include <stdlib.h>

// Linked list Node element
typedef struct Node
{
    int          x;
    struct Node *next;
} Node;

// Malloc Node element or exit with code 1
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

// Malloc New node at the end of a Linked List
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

// Malloc New Node at the beginning of a linked list
void insert_beginning( Node **root, int value )
{
    Node *new_node = node_init( value, *root );
    *root          = new_node;
}

// Malloc New Node after a Node or exit with code 2 if node is NULL
void insert_after( Node *node, int value )
{
    if ( node == NULL )
    {
        exit( 2 );
    }

    Node *new_node = node_init( value, node->next );
    node->next     = new_node;
}

// Suposed use is in already sorted linked list
void insert_sorted( Node **root, int value )
{
    // special cases
    // empty root or new value/element should be first
    // -- ( *root )->x >= value -- ascending order, recent first/LIFO (Stack)
    // -- ( *root )->x > value -- ascending order, recent first/FIFO (Queue)
    // -- ( *root )->x <= value -- descending order, recent first/LIFO (Stack)
    // -- ( *root )->x < value -- descending order, recent first/FIFO (Queue)
    if ( *root == NULL || ( *root )->x >= value )
    {
        insert_beginning( root, value );
        return;
    }

    // Find element to add after(before)
    Node *curr = *root;
    while ( curr->next != NULL )
    {
        // -- curr->next->x >= value -- ascending order, recent first/LIFO (Stack)
        // -- curr->next->x > value -- ascending order, recent last/FIFO (Queue)
        // -- curr->next->x <= value -- descending order, recent first/LIFO (Stack)
        // -- curr->next->x < value -- descending order, recent last/FIFO (Queue)
        if ( curr->next->x >= value )
        {
            break;
        }
        curr = curr->next;
    }
    // curr node is the, but we still have to insert the value
    insert_after( curr, value );
}

void remove_element( Node **root, int value )
{
    if ( *root == NULL )
    {
        return;
    }

    if ( ( *root )->x == value )
    {
        Node *to_remove = *root;
        *root = (*root)->next;
        free(to_remove);
        return;
    }
    Node *curr = *root;
    while ( curr->next != NULL )
    {
        if ( curr->next->x == value )
        {
            Node *to_remove = curr->next;
            curr->next      = curr->next->next;
            free( to_remove );
            return;
        }
        curr = curr->next;
    }
}

// Deallocate all linked Node elements
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

// Deallocate recursively all linked Node elements
void recursive_dealloc( Node **root )
{
    if ( ( *root )->next != NULL )
    {
        recursive_dealloc( &( *root )->next );
    }
    free( *root );
    *root = NULL;
}

int main( int argc, char const *argv[] )
{
    // Node *root = node_init( 15, NULL );
    Node *root = NULL;

    insert_sorted( &root, 7 );
    insert_sorted( &root, 15 );
    insert_sorted( &root, -2 );
    insert_sorted( &root, 3 );
    insert_sorted( &root, 42 );

    Node *curr = root;

    printf( "While Loop prints\n" );
    while ( curr != NULL )
    {
        printf( "%d\n", curr->x );
        curr = curr->next;
    }

    remove_element( &root, 42 );

    printf( "For Loop prints\n" );
    // Node *curr;
    for ( curr = root; curr != NULL; curr = curr->next )
    {
        printf( "%d\n", curr->x );
    }

    // recursive_dealloc( &root );
    deallocate( &root );

    return 0;
}
