#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binaryRepresentation(char *outputArray, void *thingToCheck, int sizeOfThing);

int main(int argc, char const *argv[])
{
    int a = 13;
    printf("%d\n", a);

    char arr[sizeof(int) * 8];
    binaryRepresentation(arr, a, sizeof(int));
    printf("%s \n", arr);
    
    long long i;
    for (i = 0; i < sizeof(int); i++)
    {
        printf("%02hhx ", ((unsigned char*)&a)[i]);
    }

    // 1101 >> 0 => 1101
    // 1101 << 1 => 11010
    // 1100 & 0001 => 0000
    // 0000 | 0100 => 1101
    // 0 => 31
    // 1 => 30

    int reversed = 0;
    for (i = 0; i < 32; i++)
    {
        reversed |= ((a >> i) & 1) << (32-1-i);
    }
    printf("\n");
    printf("%d\n", reversed);

    binaryRepresentation(arr, reversed, sizeof(int));
    printf("%s \n", arr);

    for (i = 0; i < sizeof(int); i++)
    {
        printf("%02hhx ", ((unsigned char*)&reversed)[i]);
    }
    

    return 0;
}

void binaryRepresentation(char *outputArray, void *thingToCheck, int sizeOfThing)
{
    long long i, j;
    for (i = 0; i < sizeOfThing; i++)
    {
        // get a byte from the thing
        char byte = ((char *)&thingToCheck)[i];
        
        // cicle through the bits of the bytes
        for (j = 7; j >= 0; j--)
        {
            // get the next bit
            char bit = (byte >> j) & 1;
            // add the bit to the output array at the propper index as a char
            outputArray[(i * 8) + (7 - j)] = bit + '0';
        }
    }
    return;
}
