#include <stdio.h>
#include <stdlib.h>


// Pragma tells the compiler to pack variables our way in memory
// It is not recomended to change it, as it is usualy done automaticaly for us
#pragma pack(2)

typedef struct
{
    int test;     // 4
    char k;       // 1
    char str[10]; // 10
    int *p;       // 8
    short sh;     // 2
} Thing;

int main(int argc, char const *argv[])
{
    int i;
    Thing t = {12, 'k', "testing", &i, 256};
    printf("%llu\n", sizeof(t));
    unsigned char data;
    for (i = 0; i < sizeof(t); i++)
    {
        if (i % 8 == 0)
        {
            printf("\n");
        }
        data = *(((unsigned char *)&t) + i);

        printf("%02x ", data);
        // printf("%03hhu ", data);
        // printf("%c ", data);
    }
    return 0;
}
