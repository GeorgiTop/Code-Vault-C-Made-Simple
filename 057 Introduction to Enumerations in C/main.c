#include <stdio.h>

enum Color {
    RED = 7,
    GREEN,
    BLUE
};

typedef enum Color Color;

int main(int argc, char const *argv[])
{
    Color c = BLUE;
    printf("%d\n", c);
    return 0;
}
