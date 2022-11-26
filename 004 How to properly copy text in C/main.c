#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char text1[50];
    char text2[] = "Temp";
    char text3[17] = "Hello this world";

    // char *p;
    // for (p = text3; p < text1 + 20; p++)
    // {
    //     printf("%c ", *p);
    // }
    // printf("\n");

    // strcpy(text1, text3);
    
    strncpy(text1, text3, 16);
    text1[16] = '\0';

    printf("%s\n%s\n%s\n", text1, text2, text3);

    return 0;
}
