#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int main(int argc, char const *argv[])
{
    long long a = 15;
    long long b = 20;
    long long c[] = {1, 2, 3 };
    char d = 'a';

    long long *p = c;
    printf("Result is %lld at address %p\n", *p, p);
    long long result = &a - &b; // difference in memmory divided by sizeof(theri type)
    // long long result = &a - &d; // cannnot be done with diferent types
    printf("Result is %lld at address %p and %p\n", result, &a , &b);

    long long * o = malloc(sizeof(long long));
    long long * q = malloc(sizeof(long long));

    long long res = o - q;
    printf("Result is %lld at address %p and %p\n", result, &o , &q);

    free(o);
    free(q);

    return 0;
}
