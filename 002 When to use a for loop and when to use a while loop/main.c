#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char text[] = "Hello world!";

    int i;
    for(i = 0; i < strlen(text); i++)
    {
        printf("%c ", text[i]);
    }
    printf("\n");

    i = 0;
    while (text[i] != ' ')
    {
        printf("%c ", text[i]);
        i++;
    }

    return 0;
}
