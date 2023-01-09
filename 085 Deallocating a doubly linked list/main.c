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

int main( int argc, char const *argv[] )
{
    Node *tail = malloc( sizeof( Node ) );
    if ( tail == NULL )
    {
        exit( 1 );
    }
    tail->x    = 1;
    tail->prev = NULL;
    tail->next = malloc( sizeof( Node ) );
    if ( tail->next == NULL )
    {
        exit( 1 );
    }
    tail->next->x    = 2;
    tail->next->prev = tail;
    tail->next->next = malloc( sizeof( Node ) );
    if ( tail->next->next == NULL )
    {
        exit( 1 );
    }
    tail->next->next->x    = 7;
    tail->next->next->prev = tail->next;
    tail->next->next->next = NULL;
    Node *head             = tail->next->next;

    Node *curr;
    for ( curr = tail; curr != NULL; curr = curr->next )
    {
        printf( "%d\n", curr->x );
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
