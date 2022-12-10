#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int a = 255;
    printf("%d\n", a);

    float b = 255;
    printf("%f\n", b);

    long long c = 255;
    printf("%lld\n", c);

    unsigned long long d = 255;
    printf("%llu\n", d);
    printf("%lu\n", sizeof(d)); // Always use %lu for sizeof() - it returns 64bit unsgined integer

    float e = 2.55;
    printf("%f\n", e);
    printf("%.2f\n", e); //  .2 specifies the number of simbols behind the decimal point we want to see

    int f = 70;
    printf("%8d\n", a);  // The %8 adds leading spaces to the left (for alignment)
    printf("%08d\n", f); // The %08 will add leading zeroes insted of spaces

    printf("%x\n", a);  // Print in hexadecimal
    printf("%X\n", a);  // Print in hexadecimal capitalized
    printf("%#x\n", a); // Print in hexadecimal with prefix 0x

    printf("%p\n", &a); // Prrints the address of a

    printf("%c\n", f); // Prints the ASCI character coresponding to that number

    // Printf does not change the data type, it only shows interpretation of the binary value behind the given variable

    return 0;
}
