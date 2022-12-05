#include <stdio.h>
#include <stdlib.h>

int sumAndProduct(int a, int b, int *sum, int *product);

int main(int argc, char const *argv[])
{
    /* a, b => a+b and a*b */

    int x = 5, y = 12, sum, prod;

    int status = sumAndProduct(x, y, &sum, &prod);
    if (status == 0)
    {
        printf("Something went wrong!\n");
    }
    else
    {
        printf("The sum is %d, the product is %d\n", sum, prod);
    }

    return 0;
}

int sumAndProduct(int a, int b, int *sum, int *product)
{
    if (sum == NULL || product == NULL)
    {
        // return/error code if the function did not get all the needed parameters
        return 0;
    }
    *sum = a + b;
    *product = a * b;
    return 1;
}