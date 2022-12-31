#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * file;
    fopen_s(&file, "number.dat", "w");
    if(file == NULL)
    {
        fclose(file);
        return 1;
    }
    fprintf(file, "20");
    // fseek(file, 0, SEEK_SET);
    // fseek(file, 3, SEEK_CUR);
    fseek(file, -2, SEEK_END);
    fprintf(file, "22");
    
    fclose(file);
    return 0;
}
