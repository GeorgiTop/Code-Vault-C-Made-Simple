#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[] = "abvg4";
    char str2[] = "abvg1";

    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", strncmp(str1, str2, 4));
    printf("%d\n", memcmp(str1, str2, 4));

    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 4};

    printf("%d\n", memcmp(arr1, arr2, sizeof(arr1)));
    return 0;
}
