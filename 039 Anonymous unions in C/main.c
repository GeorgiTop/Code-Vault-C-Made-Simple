#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct customFloat {
    bool isExtended;
    union {
        float value;
        double valueExtended;
    };
} CustomFloat;

int main(int argc, char const *argv[])
{
    CustomFloat cf;
    CustomFloat cf2;
    cf.isExtended = false;
    cf.value = 12.5f;

    cf2.isExtended = true;
    cf2.valueExtended = 0.25;

    printf("%f %lf\n", cf.value, cf2.valueExtended);
    printf("%p %p\n", &cf.value, &cf.valueExtended);
    return 0;
}
