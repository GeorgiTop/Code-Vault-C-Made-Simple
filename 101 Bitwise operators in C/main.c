#include <stdio.h>

int main(int argc, char const *argv[])
{
    int r;
    // r = 9 & 5;  //bw and
    // r = 9 | 5;  //bw or
    // r = 9 ^ 5;  //bw xor 
    r = ~ 5;    // bw not
    // 0000 0000 0000 0000 0000 0000 0000 0101
    // 1111 1111 1111 1111 1111 1111 1111 1010
    printf("Result: %x\n", r);
    return 0;
}
