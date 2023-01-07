#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char *strstrall( const char *_str, const char *_subStr, size_t size_of_subStr );

int main( int argc, char const *argv[] )
{
    char  str[]     = "Apples are good for your health and good for me too for I am apple-eater";
    char  to_find[] = "for";
    char *res       = strstr( str, to_find );
    if ( res )
    {
        char *all[50];
        memset( all, 0, 50 );

        int i, n = 0;
        while ( res )
        {
            all[n] = res;
            res    = strstr( res + sizeof(to_find), to_find );
            n++;
        }
        // Sanity check
        for ( i = 0; i < n; i++ )
        {
            printf( "%s\n", all[i] );
            printf( "The word has been found at position %llu\n",  all[i] - str);
        }
    }
    else
    {
        printf( "%p\n", res );
        printf( "The word has NOT been found\n" );
    }
    return 0;
}

// char *strstrall( const char *_str, const char *_subStr, size_t size_of_subStr )
// {
//     char *res = strstr( _str, _subStr );
//     char *all[50];
//     memset( all, 0, 50 );
//     if ( res )
//     {
//         int i = 0;
//         while ( res )
//         {
//             all[i] = &res;
//             res    = strstr( res + size_of_subStr, _subStr );
//             i++;
//         }

//         all, i;

//         return &all;
//     }
//     return res;
// }
