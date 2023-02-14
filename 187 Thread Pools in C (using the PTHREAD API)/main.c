/*
 Main thread (might be user)
    |
    | insert + create a task
    V
 Task Queue
    ^
    | wait and get a task
    |
 Thread pool (loops on executing tasks)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define THREAD_COUNT 8

typedef struct Task
{
    int a, b;
} Task;

Task            taskQueue[256];
int             taskCount = 0;
pthread_mutex_t mutexQueue;
pthread_cond_t  condQueue;

void executeTask( Task *task )
{
    usleep( 50000 );
    int result = task->a + task->b;
    printf( "The sum of %d and %d is %d\n", task->a, task->b, result );
}

void submitTask( Task task )
{
    pthread_mutex_lock( &mutexQueue );
    taskQueue[taskCount] = task;
    taskCount++;
    pthread_mutex_unlock( &mutexQueue );
    pthread_cond_signal( &condQueue );
}

void *startThread( void *args )
{
    while ( 1 )
    {
        Task task;

        pthread_mutex_lock( &mutexQueue );
        while ( taskCount == 0 )
            pthread_cond_wait( &condQueue, &mutexQueue );

        task = taskQueue[0];
        int i;
        for ( i = 0; i < taskCount - 1; i++ )
        {
            taskQueue[i] = taskQueue[i - 1];
        }
        taskCount--;

        pthread_mutex_unlock( &mutexQueue );

        executeTask( &task );
    }
}

int main( int argc, char const *argv[] )
{
    // Thread setup
    pthread_mutex_init( &mutexQueue, NULL );
    pthread_cond_init( &condQueue, NULL );
    pthread_t th[THREAD_COUNT];
    int       i;
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_create( &th[i], NULL, &startThread, NULL ) != 0 )
        {
            perror( "Failed to create thread\n" );
        }
    }
    // Work
    srand( time( NULL ) );
    for ( i = 0; i < 100; i++ )
    {
        int  a = rand() % 100;
        int  b = rand() % 100;
        Task t = { .a = a, .b = b };
        submitTask( t );
    }

    // Thread clean up
    for ( i = 0; i < THREAD_COUNT; i++ )
    {
        if ( pthread_join( th[i], NULL ) != 0 )
        {
            perror( "Failed to join thread\n" );
        }
    }
    pthread_mutex_destroy( &mutexQueue );
    pthread_cond_destroy( &condQueue );
    return 0;
}
