#include <stdio.h>
#include <stdlib.h>

#define PRINT_VAR(X) \
    printf(#X " is %d at address %p\n", X, &X);

#define SWAP(A, B) A ^= B ^= A ^= B;

int main(int argc, char const *argv[])
{
    int a = 3, b = 8;
    PRINT_VAR(a);
    PRINT_VAR(b);

    SWAP(a, b);

    PRINT_VAR(a);
    PRINT_VAR(b);

    return 0;
}
