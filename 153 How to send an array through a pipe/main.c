// 2 processes
// Child process should generate random numbers and send them to parent in an array
// Parent should sum all numbers and print the result

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main( int argc, char const *argv[] )
{
    int fd[2];
    int i = 0;
    int arr[5];

    if ( pipe( fd ) == -1 )
    {
        return 1;
    }
    int pid = fork();
    if ( pid == -1 )
    {
        return 2;
    }

    if ( pid == 0 )
    {
        // child
        close( fd[0] );

        int arr[10];
        srand( time( NULL ) );
        int n = rand() % 10 + 1;
        printf("Generating %d\n", n);

        for ( i = 0; i < n; i++ )
        {
            arr[i] = rand() % 6 + 1;
            printf("%d ", arr[i]);
        }
        printf("\n");
        if ( write( fd[1], &n, sizeof( int ) ) == -1 )
        {
            return 3;
        }
        printf("Sent n = %d\n", n);
        if ( write( fd[1], arr, sizeof( int ) * n ) == -1 )
        {
            return 4;
        }
        printf("Sent array\n");
        close( fd[1] );
    }
    else
    {
        // parent
        close( fd[1] );
        int arr[10];
        int i   = 0;
        int n   = 0;
        int sum = 0;
        if ( read( fd[0], &n, sizeof( int ) ) < 0 )
        {
            return 5;
        }
        printf("Received n = %d\n", n);
        if ( read( fd[0], &arr, sizeof( int ) * n ) < 0 )
        {
            return 6;
        }
        printf("Received array\n");
        for ( i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        printf("Total is: %d\n", sum);
        close( fd[0] );
        wait(NULL);
    }

    return 0;
}
