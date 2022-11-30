#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

void string_arr_1(void);
void string_arr_2(void);
void string_arr_3(void);
void print_element(int length, int size, char string_array[length][size])
{
    int i;
    for (i = 0; i <= length; i++)
    {
        printf("%s\n", string_array[i]);
    }
}

int main(void)
{
    string_arr_1();
    string_arr_2();
    string_arr_3();
    return 0;
}

/* Implementation 1*/
void string_arr_1(void)
{
    char array[3][SIZE];

    /* String copy */
    strcpy(array[0], "Hello world!");
    strcpy(array[1], "test");
    strcpy(array[2], "123");

    int length = sizeof(array) / sizeof(array[0]);
    print_element(length, SIZE, array);
    // printf("Strings are: \n%s\n%s\n%s\n", array[0], array[1], array[2]);
}

/* Implementation 2*/
void string_arr_2(void)
{

    /* Array prep */
    int length = 3;
    char array[length * SIZE];

    /* String copy */
    strcpy(array, "Hello world!");
    strcpy(array + 50, "test");
    strcpy(array + 100, "123");

    // print_element(-1, (length * SIZE), array);
    printf("Strings 2 are: \n%s\n%s\n%s\n\n", array + 0, array + 50, array + 100);
}

/* Implementation 3 */
void string_arr_3(void)
{
    char array[][SIZE] = {
        "Hello world!",
        "test",
        "123",
        "other values"};

    int length = sizeof(array) / sizeof(array[0]);
    print_element(length, SIZE, array);
    // printf("Strings are: \n%s\n%s\n%s\n%s\n", array[0], array[1], array[2], array[3]);
}
