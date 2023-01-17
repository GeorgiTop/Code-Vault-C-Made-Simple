#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    char str[100] = "133333333333333333333333";
    // char str[100] = "google.com";
    // char str[100] = "133";
    char * endPtr;
    long int x = strtol(str, &endPtr, 10);
    if (str == endPtr)
    {
        printf("Number could not be parsed!\n");
    }
    if (errno == ERANGE)
    {
        printf("Number is too big to store in the variable!\n");
    }
    printf("%ld\n", x);
    return 0;
}
