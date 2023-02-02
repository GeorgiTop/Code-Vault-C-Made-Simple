#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define THREAD_COUNT 8

pthread_barrier_t barrierRolledDice;
pthread_barrier_t barrierCalculated;
int               diceValues[THREAD_COUNT];
int               status[THREAD_COUNT] = { 0 };

void *rollDice( void *args )
{
    int index = *( int * ) args;
    while ( 1 )
    {
        diceValues[index] = rand() % 6 + 1;
        pthread_barrier_wait( &barrierRolledDice );
        pthread_barrier_wait( &barrierCalculated );
        if ( status[index] == 1 )
        {
            printf( "(%2d rolled %d) I won\n", index, diceValues[index] );
        }
        else
        {
            printf( "(%2d rolled %d) I lost\n", index, diceValues[index] );
        }
    }
    free( args );
}

int main( int argc, char const *argv[] )
{
    srand( time( NULL ) );
    pthread_t th[THREAD_COUNT];
    pthread_barrier_init( &barrierRolledDice, NULL, THREAD_COUNT + 1 );
    pthread_barrier_init( &barrierCalculated, NULL, THREAD_COUNT + 1 );
    int i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        int *a = malloc( sizeof( int ) );
        *a     = i;
        if ( pthread_create( &th[i], NULL, &rollDice, a ) != 0 )
        {
            perror( "Failed to create thread\n" );
        }
    }

    while ( 1 )
    {
        pthread_barrier_wait( &barrierRolledDice );
        // Calculcate winner
        int max = 0;
        for ( i = 0; i < THREAD_COUNT; i++ )
        {
            if ( diceValues[i] > max )
            {
                max = diceValues[i];
            }
        }

        for ( i = 0; i < THREAD_COUNT; i++ )
        {
            if ( diceValues[i] == max )
            {
                status[i] = 1;
            }
            else
            {
                status[i] = 0;
            }
        }
        sleep( 1 );
        printf( "======== NEW ROUND ========\n" );
        pthread_barrier_wait( &barrierCalculated );
    }

    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_join( th[i], NULL ) != 0 )
        {
            perror( "Failed to join thread\n" );
        }
    }

    pthread_barrier_destroy( &barrierRolledDice );
    pthread_barrier_destroy( &barrierCalculated );
    return 0;
}
