#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int queue[256];
int count = 0;

void insertIntoQueue( int x )
{
    if (count == 256)
    {
        printf("No more space in the queue\n");
        return;
    }
    queue[count] = x;
    count++;
}

int removeFromQueue()
{
    if (count == 0)
    {
        fprintf(stderr, "No elements to extract from queue\n");
        printf("No elements to extract from queue\n");
        return -1;
    }
    int res = queue[0];
    int i;
    for ( i = 0; i < count - 1 ; i++ )
    {
        queue[i] = queue[i + 1];
    }
    count--;
    return res;
}

int main( int argc, char const *argv[] )
{
    insertIntoQueue( 1 );
    insertIntoQueue( 3 );
    insertIntoQueue( 4 );
    insertIntoQueue( 7 );
    insertIntoQueue( 89 );

    int i;
    int n = count+1;
    for ( i = 0; i < n; i++ )
    {
        printf( "%d ", removeFromQueue() );
    }
    printf( "\n" );

    return 0;
}
