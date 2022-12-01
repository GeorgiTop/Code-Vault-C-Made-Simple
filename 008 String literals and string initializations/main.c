#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // Sring on the stack, will work
    // char str[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    // char str[] = "Hello!";

    // Const string in memory, will break on edit
    // char *str = "Hello!"; // this line translates roughly to the next 2 lines
    // const static char noname[] = "Hello!";
    // char *str = noname;

    // Dynamically allocated string on the heap, will work
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "Hello!");

    printf("%s\n", str);
    str[0] = 'h';
    printf("%s\n", str);

    // Only needed for dynamically allocated string
    free(str);
    return 0;
}
