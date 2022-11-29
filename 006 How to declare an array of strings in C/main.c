#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_arr_1(void);
void string_arr_2(void);
void string_arr_3(void);
// void print_element(char *array);

int main(void)
{
    // string_arr_1();
    /* string_arr_2(); */
    string_arr_3();
    return 0;
}

/* Implementation 1*/
void string_arr_1(void)
{
    char array[3][50];

    /* String copy */
    strcpy(array[0], "Hello world!");
    strcpy(array[1], "test");
    strcpy(array[2], "123");

    printf("Strings are: \n%s\n%s\n%s\n", array[0], array[1], array[2]);
}

/* Implementation 2*/
void string_arr_2(void)
{

    /* String copy */
    char array[3 * 50];

    /* String copy */
    strcpy(array, "Hello world!");
    strcpy(array + 50, "test");
    strcpy(array + 100, "123");

    printf("Strings are: \n%s\n%s\n%s\n", array, array + 50, array + 100);
}

/* Implementation 3 */
void string_arr_3(void)
{
    char array[][50] = 
    {
        "Hello world!",
        "test",
        "123",
        "other values"
    };
    
    // print_element(array);
    printf("Strings are: \n%s\n%s\n%s\n%s\n", array[0], array[1], array[2], array[3]);
}

// void print_element(char *array)
// {
//     int i;
//     for(i = 0; array[i]; i++)
//     {
//         printf("%s\n", array[1]);
//     }
// }