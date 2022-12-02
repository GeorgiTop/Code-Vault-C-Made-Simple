#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define START 1
#define SIZE 10
#define PRODUCT(X, Y) (X) * (Y)


// #define varad_head(type, name) type variadic_##name(variadic_type_##name x)
// #define varad_declare(type, name, ...) typedef struct {__VA_ARGS__ ;} variadic_type_##name; varad_head(type, name);
// #define varad_var(name, value) name = x.name ? x.name : (value);
// #define varad_link(name,...) variadic_##name((variadic_type_##name) {__VA_ARGS__})

// varad_declare(double, sum, int first; double second; int third;)
// #define sum(...) varad_link(sum,__VA_ARGS__)

// varad_head(double, sum) {
// int varad_var(first, 0)
// double varad_var(second, 2.2)
// int varad_var(third, 8);
// return first + second + third;
// }
// #define print_a_multiplyed_by_b(...) void var_f((f_args){__VA_ARGS__});
// #define f_link()
// void print_a_multiplyed_by_b(int a, int b);
// typedef struct {
//     int a;
//     int b;
// } f_args;

void print_array_with_even_numbers(int starting_from, int size);


int main(int argc, char const *argv[])
{

    print_array_with_even_numbers(START, SIZE);

    int a = 2; 
    int b = 6;
    printf("%d\n", PRODUCT(a + 1, b));
    return;

    // print_a_multiplyed_by_b();
    
    return 0;
}

void print_array_with_even_numbers(int starting_from, int size)
{
    int arr[size];
    int i;

    for (i = 0; i < size; i++)
    {
        arr[i] = (starting_from + i) * 2;
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// void var_f(f_args in)
// {
//     int a_out = in.a ? in.a : 2;
//     int b_out = in.b ? in.b : 6;
//     return print_a_multiplyed_by_b(a_out, b_out);
// }

// void print_a_multiplyed_by_b(int a, int b)
// {
//     printf("%d\n", PRODUCT(a + 1, b));
//     return;
// }
