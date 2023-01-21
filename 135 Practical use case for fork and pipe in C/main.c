#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main( int argc, char const *argv[] )
{
    int arr[]   = { 1, 2, 3, 4, 1, 2, 3, 4, 5 };
    int arrSize = sizeof( arr ) / sizeof( int );
    int start, end;
    int fd[2];
    if ( pipe( fd ) == -1 )
    {
        printf( "Error pipe init fail\n" );
        return 1;
    }
    int id = fork();
    if ( id == -1 )
    {
        printf( "Error no fork\n" );
        return 2;
    }

    // Assign wich process reads what part of the array
    if ( id == 0 )
    {
        start = 0;
        end   = arrSize / 2;
    }
    else
    {
        start = arrSize / 2;
        end   = arrSize;
    }

    int sum = 0;
    int i;
    for ( i = start; i < end; i++)
    {
        sum += arr[i];
    }
    printf("Calcuclated partial sum %d\n", sum);

    if (id == 0)
    {
        close(fd[0]);
        if (write(fd[1], &sum, sizeof(sum)) == -1)
        {
            printf("An error ocurred with writing to the pipe\n");
            return 3;
        }
        close(fd[1]);
    }
    else
    {
        int sumFromChild;
        wait(NULL);
        close(fd[1]);
        if(read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
        {
            printf("An error ocurred while reading from the pipe\n");
            return 4;
        }
        close(fd[0]);
        int totalSum = sum + sumFromChild;
        printf("Total sum is %d\n", totalSum);
    }


    return 0;
}
