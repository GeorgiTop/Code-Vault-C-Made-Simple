#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getString(char *str)
{
    strcpy(str, "test");
    return str;
}

int main(int argc, char const *argv[])
{
    char s[50];
    getString(s);
    printf("%s\n", s);
    s[0] = 'P';
    printf("%s\n", s);
    return 0;
}
