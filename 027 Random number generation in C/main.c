#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t secondsFromEpoch = time(NULL);   // Current time
    srand(secondsFromEpoch);                // Seed change
    printf("%lu\n", secondsFromEpoch);
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    return 0;
}
