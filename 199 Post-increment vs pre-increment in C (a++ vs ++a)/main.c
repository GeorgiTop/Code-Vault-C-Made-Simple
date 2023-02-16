#include <stdio.h>
#include <stdlib.h>

int a = 5;

int a_plus_plus() {
    int temp = a;
    a = a + 1;
    return temp;
}

int plus_plus_a() {
    a = a + 1;
    return a;
}

int main(int argc, char const *argv[])
{
    printf("a = %d\n", a);
    // evaluate a
    // a = 5;
    // print...
    // increment
    // a = a+1;
    printf("a++ = %d\n", a++);

    printf("a = %d\n", a);
    
    // increment
    // a = a+1;
    // evaluate a
    // a = 7;
    // print...
    printf("++a = %d\n", ++a);

    return 0;
}
