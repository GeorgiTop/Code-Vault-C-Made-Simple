#include <stdio.h>

int main( int argc, char const *argv[] )
{
    int  a = 16;
    int *p = &a;
    *p     = 17;

    printf( "A value: %d\n", a );
    printf( "Dereferenced value: %d\n", *p );

    int arr[] = { 5, 13, 31 };
    // we dont need the addidtional brackets for the first element
    printf( "1st:  %d\n", *arr); 
    // Dereferencing arr + 1 will do pointer arithmetic and give us the second int in the array
    printf( "Math: %d\n", *(arr + 1) ); 
    // Sintax shugar that does the dereferencing math
    printf( "2nd:  %d\n", arr[1] );
    // Fun stuff we can swap the places of the operators in the brackets cuz math :P
    printf( "Fun:  %d\n", 1[arr] );



    return 0;
}
