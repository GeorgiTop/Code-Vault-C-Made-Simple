#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *roll_dice(void *arg)
{
    int value = (rand() % 6) + 1;
    int * result = malloc(sizeof(int));
    *result = value;
    printf("Thread result: %d\n", value);
    // printf("Thread result %p\n", result);
    // return (void*) result;
    pthread_exit( result );
}

int main(int argc, char const *argv[])
{
    int* res;
    srand(time(NULL));
    pthread_t th;
    if(pthread_create(&th, NULL, &roll_dice, NULL) != 0 )
    {
        perror("Failed to create thread");
        return 1;
    }
    // pthread_exit(0);  // usefull when we want to stop main execution, but the threads continue.
    if (pthread_join( th, (void **) &res ) != 0)
    {
        perror("Thread failed to execute");
        return 2;
    }
    printf("Thread result %p\n", res);
    free(res);
    return 0;
}
