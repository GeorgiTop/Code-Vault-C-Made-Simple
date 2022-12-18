#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    short int x = -16384;
    // 2 bytes - 2^14
    // 01000000 00000000
    
    int y = 1073741824;
    // 4 bytes - 2^30
    // 01000000 00000000 00000000 00000000
    
    x = y; // y % 65536 or y % 2^16
    // 00000000 00000000
    
    printf("%hd %d", x, y);
    return 0;
}
