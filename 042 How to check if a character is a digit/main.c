#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // char c = 't';
    char c = '6';
    // char c = 116;
    
    if (c >= 48 && c <= 57)
    // if (c >= '0' && c <= '9')
    {
        printf("This is a digit: %c\n", c);
    }
    else
    {
        printf("This is not a digit: %c\n", c);
    }

    return 0;
}
