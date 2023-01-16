#include <stdio.h>

#define FIRST_FLAG  0b1
#define SECOND_FLAG 0b10
#define THIRD_FLAG  0b10000000

int main( int argc, char const *argv[] )
{
    // unsigned int flags = 3;
    unsigned int flags = FIRST_FLAG | SECOND_FLAG | THIRD_FLAG;

    // 00000000 00000000 00000000 00000001
    // 00000000 00000000 00000000 00000010  |
    // 00000000 00000000 00000000 10000000  |

    // 00000000 00000000 00000000 10000011

    // disable the second flag
    flags &= ~SECOND_FLAG;

    if ( flags & FIRST_FLAG )
    {
        printf( "1st feature is enabled\n" );
    }
    if ( flags & SECOND_FLAG )
    {
        printf( "2nd feature is enabled\n" );
    }
    if ( flags & THIRD_FLAG )
    {
        printf( "3rd feature is enabled\n" );
    }
    return 0;
}
