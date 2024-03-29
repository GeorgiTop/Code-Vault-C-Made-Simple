#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
    int i;
    for ( i = 0; i < 20000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        // read mails
        // increment
        //write mails
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    pthread_t t3, t4;
    pthread_mutex_init(&mutex, NULL);
    if ( pthread_create( &t1, NULL, &routine, NULL) != 0 )
    {
        return 1;
    }
    if ( pthread_create( &t2, NULL, &routine, NULL) != 0 )
    {
        return 2;
    }
    if ( pthread_create( &t3, NULL, &routine, NULL) != 0 )
    {
        return 3;
    }
    if ( pthread_create( &t4, NULL, &routine, NULL) != 0 )
    {
        return 4;
    }
    if ( pthread_join( t1, NULL ) != 0)
    {
        return 5;
    }
    if ( pthread_join( t2, NULL ) != 0)
    {
        return 6;
    }
    if ( pthread_join( t3, NULL ) != 0)
    {
        return 7;
    }
    if ( pthread_join( t4, NULL ) != 0)
    {
        return 8;
    }
    printf("Number of mails: %d\n", mails);
    pthread_mutex_destroy(&mutex);
    return 0;
}
