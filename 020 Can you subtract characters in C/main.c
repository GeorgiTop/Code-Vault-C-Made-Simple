#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char c = 'd';
    printf("%c\n", c);
    
    c -= 3;
    printf("%c\n", c);

    int a = c - '0';
    printf("%c\n", a);

    return 0;
}
