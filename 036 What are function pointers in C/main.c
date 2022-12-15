#include <stdio.h>
#include <stdlib.h>

long long add(int a, int b)
{
    return a + b;
}

long long mul(int a, int b)
{
    return a * b;
}

void exec(long long (*func) (int, int)) 
{
    printf("%lld\n", func(5, 7));
}

int main(int argc, char const *argv[])
{
    // Function pointer declaration and usage
    // long long (*func) (int, int);
    // func = &mul;
    // printf("%lld\n", func(5, 7));

    printf("%lld\n", add(5, 7));
    // Awesome usage (like drcorators in python)
    exec(&mul);
    
    return 0;
}
