#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[10];
    int v = 0;
    // gets(str);  // can lead to stack overload
    // gets_s(str, 10);  //  newer and "safer" version
    fgets(str, 10, stdin);  // also safe and can read from files
    printf("You typed: %s\n", str);
    printf("v: %d | %x\n", v, v);
    return 0;
}
