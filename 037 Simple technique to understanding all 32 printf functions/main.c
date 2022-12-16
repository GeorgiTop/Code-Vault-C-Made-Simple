#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("test %d\n", 5);
    // s - buffer
    char buffer[200];
    sprintf(buffer, "test %d\n", 6);
    printf("%s\n", buffer);

    // n - buffer size
    snprintf(buffer, 200, "test %d\n", 7);

    // f - stream (file) (in this case the standard error)
    fprintf(stderr, "test %d\n", 8);

    // _s - safer version (C11) - checks the validity of the arguments
    fprintf_s(stderr, "test %d\n", "asd");

    // w - wide char (more than byte)
    fwprintf_s(stderr, "test %d\n", "asd");

    // v - all arguments are passed as var args list (va_list)
    // vfprintf_s(stderr, "test %d\n", args);


    // vfwprintf_s(stderr, "test %d\n", args);
    return 0;
}
