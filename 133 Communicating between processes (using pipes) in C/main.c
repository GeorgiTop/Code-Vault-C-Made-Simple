#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    int fd[2];  // file descriptor array
    
    if (pipe(fd) == -1)  
    // pipe will make a file like buffer in memmory and will write to the fd key for later usage
    // fd[0] -> read
    // fd[1] -> write
    {
        printf("An error ocurred with opening the pipe\n");
        return 1;
    }

    int id = fork();
    if (id != -1)
    {
        printf("An error ocurred with fork\n");
        return 2
    }
    if (id == 0)
    {
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("An error ocurred with writing to the pipe\n");
            return 3;
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("An error ocurred while reading from the pipe\n");
            return 4;
        }
        close(fd[0]);
        y += 42;
        printf("Got from child process %d\n", y);
    }

    return 0;
}
