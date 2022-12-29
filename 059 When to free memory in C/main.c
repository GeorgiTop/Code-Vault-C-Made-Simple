#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>

// there is no need to deallocate local variables, that are stored in the stack
int globalVariable = 42;
// the global variable will be freed when the whole program finishes execution

int main( int argc, char *argv[] )
{
    // making a simple memory "leak"
    int *p = malloc(sizeof(int));
    int *q = p;
    *p = -1;
    // clearing the "leak"
    free(p);
    // or free(q), but no need to free the same allocated address 2 times
    // free(q);

    // there is no need to allocate or deallocate a string.
    char *str = "test";
    
    // there is no need to manualy deallocate local variables, that are stored in the stack
    int a = 15;
    // the variable will be freed at the end of the main function execution
    p = &a;


    _CrtDumpMemoryLeaks();
    return 0;
}