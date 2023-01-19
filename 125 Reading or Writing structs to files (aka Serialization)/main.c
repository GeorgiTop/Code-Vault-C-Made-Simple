#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *PERSON_FORMAT_IN = "{\"name\": \"%[^\"]\", \"age\":%d, \"gender\": \"%c\"}";
const char *PERSON_FORMAT_OUT = "{\"name\": \"%s\", \"age\":%d, \"gender\": \"%c\"}\n";

typedef struct Person
{
    char name[20];
    int  age;
    char gender;
} Person;

int main( int argc, char const *argv[] )
{
    Person p1 = { .name = "John Doe", .age = 22, .gender = 'M' };
    Person p2;

    FILE *file;
    fopen_s( &file, "people.json", "w+" );
    if ( file == NULL )
    {
        return 1;
    }

    fprintf( file, PERSON_FORMAT_OUT, p1.name, p1.age, p1.gender );
    fseek( file, 0, SEEK_SET);
    fscanf_s( file, PERSON_FORMAT_IN, p2.name, 20, &p2.age, &p2.gender);

    return 0;
}
