#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int          x;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node Node;

void deallocate( Node **tail, Node **head )
{
    if ( tail == NULL )
    {
        return;
    }

    Node *curr = *tail;
    while ( curr->next != NULL )
    {
        curr = curr->next;
        free( curr->prev );
    }
    free( curr );
    *tail = NULL;
    *head = NULL;
}

Node *node_init( Node *prev, int value, Node *next )
{
    Node *new_node = malloc( sizeof( Node ) );
    if ( new_node == NULL )
    {
        exit( 1 );
    }
    new_node->x    = value;
    new_node->prev = prev;
    new_node->next = next;
    return new_node;
}

void list_init( Node **tail, int value, Node **head )
{
    Node *new_node = node_init( NULL, value, NULL );
    *tail          = new_node;
    *head          = new_node;
}

void insert_begining( Node **tail, int value )
{
    Node *new_node = node_init( NULL, value, *tail );
    if ( *tail != NULL )
    {
        ( *tail )->prev = new_node;
    }
    *tail = new_node;
}

void insert_end( Node **head, int value )
{
    Node *new_node = node_init( *head, value, NULL );
    if ( *head != NULL )
    {
        ( *head )->next = new_node;
    }
    *head = new_node;
}

void insert_after( Node *node, int value )
{
    Node *new_node = node_init( node, value, node->next );
    if ( node->next != NULL )
    {
        node->next->prev = new_node;
    }
    node->next = new_node;
}

void remove_node( Node *node )
{
    if ( node->next != NULL )
    {
        node->next->prev = node->prev;
    }

    if ( node->prev != NULL )
    {
        node->prev->next = node->next;
    }

    free( node );
}

Node *find_node( Node *tail, int value )
{
    Node *curr = tail;
    while ( curr != NULL )
    {
        if ( curr->x == value )
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

Node *find_node_recursively( Node *node, int value )
{
    if ( node == NULL )
    {
        return NULL;
    }
    if ( node->x == value )
    {
        return node;
    }
    return find_node_recursively( node->next, value );
}

int main( int argc, char const *argv[] )
{
    Node *tail = NULL;
    Node *head = NULL;
    list_init( &tail, 7, &head );
    insert_begining( &tail, 2 );
    insert_begining( &tail, 1 );
    insert_end( &head, 42 );
    insert_after( tail->next, 5 );

    Node *curr;
    for ( curr = tail; curr != NULL; curr = curr->next )
    {
        printf( "%d\n", curr->x );
    }

    Node *aux = head->prev;
    remove_node( head );
    head = aux;

    Node *found = find_node_recursively( tail, 7 );
    if ( found == NULL )
    {
        printf( "No node was found\n" );
    }
    else
    {
        printf( "Value %d; next: %p\n", found->x, found->next );
    }

    curr = head;
    while ( curr != NULL )
    {
        printf( "%d\n", curr->x );
        curr = curr->prev;
    }

    deallocate( &tail, &head );

    return 0;
}
