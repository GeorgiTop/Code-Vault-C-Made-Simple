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

#define THREAD_COUNT 4

typedef struct Task
{
    void ( *taskFunction )( int, int );
    int arg1, arg2;
} Task;

Task            taskQueue[256];
int             taskCount = 0;
pthread_mutex_t mutexQueue;
pthread_cond_t  condQueue;

void sumAndProduct( int a, int b )
{
    usleep( 50000 );
    int sum  = a + b;
    int prod = a * b;
    printf( "The sum and product of %d and %d is %d and respectively %d\n", a, b, sum, prod );
}

void sum(int a, int b)
{
    usleep( 50000 );
    int sum  = a + b;
    printf( "The sum of %d and %d is %d \n", a, b, sum );
}

void prod(int a, int b)
{
    usleep( 50000 );
    int prod  = a * b;
    printf( "The prod of %d and %d is %d \n", a, b, prod );
}

void executeTask( Task *task )
{
    task->taskFunction(task->arg1, task->arg2);
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
            taskQueue[i] = taskQueue[i + 1];
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
    for ( i = 0; i < 64; i++ )
    {
        Task t = { 
            .taskFunction = i % 2 == 0 ? &sum : &prod, 
            .arg1 = rand() % 100, 
            .arg2 = rand() % 100 };
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
