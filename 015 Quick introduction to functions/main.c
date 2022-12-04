#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(int argc, char const *argv[])
{
    int i, j;
    for (i = 0; i <= 15; i++)
    {
        printf("The %d number: %d\n", i, fibonacci(i));
    }
    return 0;
}

int fibonacci(int n)
{
    int n1, n2, i, x;
    n1 = 0;
    n2 = 1;
    for (i = 0; i < n; i++)
    {
        x = n2;
        n2 += n1;
        n1 = x;
    }
    return n2;
}