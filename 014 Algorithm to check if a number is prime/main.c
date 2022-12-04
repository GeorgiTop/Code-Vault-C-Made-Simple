#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int x);

int main(void)
{
    int i;
    for (i = -40; i <= 100; i++)
    {
        if (isPrime(i))
        {
            printf("The number %d is prime\n", i);
        }
    }
    return 0;
}

int isPrime(int x)
{
    if (x < 0 || x % 2 == 0 && x != 2)
    {
        return 0;
    }
    int d;
    int s = floor(sqrt(x));
    for (d = 3; d <= s; d += 2)
    {
        if (x % d == 0)
        {
            return 0;
        }
    }
    return 1;
}