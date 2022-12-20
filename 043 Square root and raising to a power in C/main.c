#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    // using math.h pow and sqrt functions
    double a = 3;
    double b = 4;
    double res = pow(a, b);
    printf("%5.2f\n", res);
    printf("%5.2f\n", sqrt(res));
    
    // square root of a number
    float c = 3;
    float d = 4;
    float rez = powf(c, d);
    printf("%5.2f\n", rez);
    printf("%5.2f\n", sqrtf(rez));
    // using the power of to get the square root
    printf("%5.2f\n", pow(rez, 1.0f/2.0f));
    // only 1.0f or 2.0f need be specified to a float

    // qube root of a number
    float e = 27;
    float sqrt = powf(e, 1.0f/3.0f);
    printf("%5.2f\n", sqrt);
    return 0;
}
