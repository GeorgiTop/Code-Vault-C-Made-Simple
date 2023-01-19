#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    STACK_INT,
    STACK_CHAR,
    STACK_UINT64
} DataType;

typedef struct Stack
{
    DataType type;
    size_t   size;
    void *   data;
    void *   top;

} Stack;

Stack stackCreate( size_t size, DataType type )
{
    size_t effectiveSize = 0;
    if ( type == STACK_CHAR )
    {
        effectiveSize = size * sizeof( char );
    }
    else if ( type == STACK_INT )
    {
        effectiveSize = size * sizeof( int );
    }
    else if ( type == STACK_UINT64 )
    {
        effectiveSize = size * sizeof( unsigned long long );
    }

    Stack s = { .type = type, .size = size, .data = malloc( effectiveSize ), .top = NULL };
    return s;
}

void stackPush( Stack *s, void *element )
{
    // TODO Finish implementation of push func
    // if ( s->size - 1 < 0 )
    // {
    //     printf( "Error: Stack Overflow" );
    //     exit( 1 );
    // }

    // switch ( s->type )
    // {
    // case 0:
    //     if ( s->top == NULL )
    //     {
    //         (int*)s->data[s->size] = (int*)element;
    //         s->top           = s->data[s->size];
    //     }
    //     else
    //     {
    //         (int*)s->data[s->size - 1] = (int*)element;
    //         s->top               = s->data[s->size - 1];
    //     }
    //     s->size -= 1;
    //     break;

    // default:
    //     break;
    // }
}

void stackDelete( Stack *s )
{
    free( s->data );
    s->data = NULL;
}

int main( int argc, char const *argv[] )
{
    Stack s = stackCreate( 10, STACK_INT );
    // int   a = 64;
    // int   b = 128;
    // stackPush( &s, &a );
    // stackPush( &s, &b );
    ( ( int * ) s.data )[0] = 64;
    s.top                   = ( ( int * ) s.data ) + 0;

    ( ( int * ) s.data )[1] = 128;
    s.top                   = ( ( int * ) s.data ) + 1;

    int i;
    for ( i = 0; i < 10; i++ )
    {
        printf( "Data: %d Top: %d\n", ( ( int * ) s.data )[i], s.top );
    }

    stackDelete( &s );
    return 0;
}
