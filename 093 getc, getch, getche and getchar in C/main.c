#include <stdio.h>

int main(int argc, char const *argv[])
{
    // int c = getch();     // obsolite
    // int c = getche();    // obsolite
    
    // int c = getc(stdin);  // from c lib
    // int c = getcar();  // same as above line
    int c = fgetc(stdin);
    
    printf("Printed char: %c\n", c);
    return 0;
}
