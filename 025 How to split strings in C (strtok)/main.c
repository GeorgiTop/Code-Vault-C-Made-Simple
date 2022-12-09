#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main (int argc, char *argv[])
{
    char arr[] = "Let's break this string into pieces";
    char *token = strtok(arr, " ");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    
    return 0;
}
