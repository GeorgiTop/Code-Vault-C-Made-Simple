#include <stdio.h>

#define X 5
#define Y 6

void print_primary_diagonal(int size, int matrix[size][size]);
void print_primary_diagonal_complex(int x, int y, int matrix[x][y]);
void print_secondary_diagonal(int x, int y, int matrix[x][y]);
void print_secondary_diagonal_complex(int x, int y, int matrix[x][y]);
void print_primary_top_half(int x, int y, int matrix[x][y]);
void print_primary_bottom_half(int x, int y, int matrix[x][y]);
void print_secondary_top_half(int x, int y, int matrix[x][y]);
void print_secondary_top_half(int x, int y, int matrix[x][y]);
void print_triangle_top(int x, int y, int matrix[x][y]);
void print_triangle_right(int x, int y, int matrix[x][y]);
void print_triangle_bottom(int x, int y, int matrix[x][y]);
void print_triangle_left(int x, int y, int matrix[x][y]);

int main(int argc, char *argv[])
{
    int matrix[X][Y] = {
    //   0  1  2  3  4  5
        {1, 1, 1, 1, 1}, // 0
        {2, 2, 2, 2, 2}, // 1
        {3, 3, 3, 3, 3}, // 2
        {4, 4, 4, 4, 4}, // 3
        {5, 5, 5, 5, 5}, // 4
        {6, 6, 6, 6, 6}  // 5
    };

    printf("Primay diagonal\n");
    // print_primary_diagonal(SIZE, matrix);
    // printf("\n");
    print_primary_diagonal_complex(X, Y, matrix);
    printf("\n");

    printf("Primay top half, without diagonal\n");
    print_primary_top_half(X, Y, matrix);
    printf("\n");

    printf("Primay bottom half, without diagonal\n");
    print_primary_bottom_half(X, Y, matrix);
    printf("\n");

    printf("Secondary diagonal\n");
    print_secondary_diagonal(X, Y, matrix);
    printf("\n");
    // print_secondary_diagonal_complex(X, Y, matrix);
    // printf("\n");

    printf("Secondary top half, without diagonal\n");
    print_secondary_top_half(X, Y, matrix);
    printf("\n");

    printf("Secondary bottom half, without diagonal\n");
    print_secondary_bottom_half(X, Y, matrix);
    printf("\n");

    printf("Top triangle between the diagonals\n");
    print_triangle_top(X, Y, matrix);
    printf("\n");

    printf("Right triangle between the diagonals\n");
    print_triangle_right(X, Y, matrix);
    printf("\n");

    printf("Bottom triangle between the diagonals\n");
    print_triangle_bottom(X, Y, matrix);
    printf("\n");
    
    printf("Left triangle between the diagonals\n");
    print_triangle_left(X, Y, matrix);
    printf("\n");

    return 0;
}

void print_primary_diagonal(int size, int matrix[size][size]) // KISS
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

void print_primary_diagonal_complex(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (i == j) // Primary diagonal
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_secondary_diagonal(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate colums
        {
            if (i + j == x - 1) // Secondary diagonal
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_secondary_diagonal_complex(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate colums
        {
            if (i + j == x - 1 && i + j == y - 1) // Secondary diagonal
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_primary_top_half(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate colums
        {
            if (i < j) // Top right half without the diagonal
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_primary_bottom_half(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate colums
        {
            if (i > j) // Bottom left half without the diagonal
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_secondary_top_half(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate colums
        {
            if (i + j < y - 1) // Top right half without the diagonal
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

/// @brief Prints given matrix's bottom left half without the diagonal
/// @param x number of rows to iterate over
/// @param y number of colums to iterate over
/// @param matrix [x][y]
void print_secondary_bottom_half(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate Colums
        {
            if (i + j > x - 1) // Bottom left half without the diagonal
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_triangle_top(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate Colums
        {
            if (i < j && x - i - 1 > j) // Top triangle between the diagonals
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_triangle_right(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate Colums
        {
            if (i < j && y - 1 < i + j) // Right triangle between the diagonals
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_triangle_bottom(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate Colums
        {
            if (i > j && x - i - 1 < j) // Bottom triangle between the diagonals
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_triangle_left(int x, int y, int matrix[x][y])
{
    int i, j;
    for (i = 0; i < x; i++) // iterate Rows
    {
        for (j = 0; j < y; j++) // iterate Colums
        {
            if (i > j && y - i - 1 > j) // Left triangle between the diagonals
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}