// TODO: roll several dice with multiple threads (combination with the thas 162);

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *roll_dice()
{
    int vallue = (rand() % 6) + 1;
    int * result = malloc(sizeof(int));
    *result = vallue;
    printf("%d\n", vallue);
    printf("Thread result %p\n", result);
    return (void*) result;
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
    if (pthread_join( th, (void **) &res ) != 0)
    {
        perror("Thread failed to execute");
        return 2;
    }
    printf("Thread result %p\n", res);
    free(res);
    return 0;
}
