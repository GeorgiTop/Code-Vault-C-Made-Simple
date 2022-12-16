#include <stdio.h>
#include <stdlib.h>

typedef union Example {
    long long num;
    char bytes[8];
    float floats[2];
} Example;

int main(int argc, char const *argv[])
{
    Example e;
    e.num = 17;
    // e.bytes[0] = 17;
    printf("%lld\n", e.num);
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%02hhx ", e.bytes[i]);
    }
    return 0;
}
