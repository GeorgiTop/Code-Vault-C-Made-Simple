#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some compillers do get a third parameter passed to the main function
// that is filled with system enviroment variables

int main( int argc, char const *argv[], char *envp[] )
{
    int i;
    for ( i = 0; i < argc; i++ )
    {
        printf("%s\n", argv[i]);
    }

    printf("\n Enviroment Variables start from here:\n\n");

    for ( i = 0; envp[i] != NULL; i++ )
    {
        printf( "%s\n", envp[i] );
    }

    return 0;
}
