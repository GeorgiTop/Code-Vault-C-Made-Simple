#include <stdio.h>
#include <stdlib.h>

// Globaly allocated variable; 
// end of life is when program finishes execution;
// can be referenced in the this file.
int n = 42; 

int main(int argc, char const *argv[])
{
    // Staticaly allocated variable; 
    // end of life is when program finishes execution;
    // Can only be referenced in this block;
    int a = 5;

    // Dynamicly allocated variable;
    // end of life is up to us;
    int* b = malloc(sizeof(int));
    
    *b = 2;
    printf("%d\n", *b);

    // deallocate b after we are done using it
    free(b);
    
    return 0;
}
