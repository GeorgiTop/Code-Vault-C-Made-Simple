#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibo(int k);

int main(int argc, char* argv[]) {
    int r = fibo(6);
    printf("We got %d in the main function\n", r);
    int r2 = fibo(17);
    printf("We got %d in the main function\n", r2);
    return 0;
}

int fibo(int k) {
    int n1, n2, x;
    int i;
    n1 = 0;
    n2 = 1;    
    if (k == 1)
    {
        printf("The %dth number: %d\n", k, n2);
        return n1;
    }
    for (i = 0; i < k - 2; i++) {
        x = n2;
        n2 = n1 + n2;
        n1 = x;
    }
    
    printf("The %dth number: %d\n", k, n2);
    return n2;
}