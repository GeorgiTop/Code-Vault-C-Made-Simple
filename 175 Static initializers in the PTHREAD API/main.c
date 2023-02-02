// https://youtu.be/Xo6e6RsWoBk 4 min video on this 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define THREAD_COUNT 10

pthread_mutex_t mutexFuel = PTHREAD_MUTEX_INITIALIZER;
// Can NOT be used for creation of array of mutexes

void *routine(void *args)
{

}

int main(int argc, char const *argv[])
{
    pthread_t th[THREAD_COUNT];
    // pthread_mutex_init(&mutexFuel, NULL);  
    // Made redundant if we:
    // Leave the second parameter of the init to NULL;
    // Use PTHREAD_MUTEX_INITIALIZER, here on line 9 pthread_mutex_t mutexFuel

    int i;
    for( i=0; i<THREAD_COUNT; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread\n");
        }
    }
    for( i=0; i<THREAD_COUNT; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread\n");
        }
    }
    pthread_mutex_destroy(&mutexFuel)
    return 0;
}
