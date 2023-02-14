#include <stdio.h>
#include <string.h>

int main( int argc, char const *argv[] )
{
    int a = 0;
    printf("%d\n", ++a + ++a - ++a + a++);
    // the satement above evalueates to 4 being printed, but
    // more than one side efect is undefined by specification, so
    // it depends on compiler solution what the result might be
    //              1     2     3    3 = 3
    //              4     3     2    0 = 5
    return 0;
}
