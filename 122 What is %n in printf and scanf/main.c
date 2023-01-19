#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // _set_printf_count_output(1);
    int num, x;
    num = printf("This is a test string\n");
    // printf("This is a test%n string\n", &num);  // Not recommended
    printf("Number of characters return: %d\n", num);
    // scanf("%d%n", &x, &num);                       // Not recommended
    // printf("Number of characters return: %d\n", num);

    return 0;
}
