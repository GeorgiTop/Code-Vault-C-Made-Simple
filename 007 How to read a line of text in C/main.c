#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanf_and_print(void);
void fgets_and_print(void);

int main(int argc, char const *argv[])
{
    // scanf_and_print();   // this can lead to buffer overflow or if one does not clear the '\n' symbol from the buffer.
    fgets_and_print();      // good allaround use, but the last '\n' can sneak up/or not depending on the implementation.
    
    return 0;
}

void scanf_and_print(void)
{
        char text[100];
    printf("Type a line of text here: ");
    scanf("%[^\n]s", text);
    printf("You typed the line: %s", text);
    
    //Important for clearing the previous \n symbol from the buffer                  
    getchar();                      
    
    char text2[100];
    printf("Type a line of text here: ");
    scanf("%[^\n]s", text2);

    printf("You typed the line: %s", text2);
}

void fgets_and_print(void)
{
    char text[100];
    printf("Type a line of text here: ");
    fgets(text, 100, stdin);
    text[strlen(text)-1] = '\0';
    printf("You typed the line: %s", text);
}
