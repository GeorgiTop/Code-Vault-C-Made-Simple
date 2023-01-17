#include <stdlib.h>
#include <stdio.h>

int main( int argc, char const *argv[] )
{
    char  str[] = "Daniel is 25 years old";
    char *age = str;
    
    age = strpbrk(str, "0123456789");

    // int   i;
    // for ( i = 0; i < strlen( str ); i++ )
    // {
    //     if ( str[i] >= '0' && str[i] <= '9' )
    //     {
    //         age = str + i;
    //         break;
    //     }
    // }
    printf( "%s\n", age );


    size_t number_of_digits = strspn(age, "0123456789");    
    int   i;
    for(i = 0; i < number_of_digits; i++)
    {
        printf("%c", age[i]);
    }
    printf("\n");
    return 0;
}
