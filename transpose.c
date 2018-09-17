#include <stdio.h>
#include <stdlib.h>

int Create_matrix (int*** matrix, int m, int n);
int Scan_matrix (int*** matrix, int m, int n);
int Transpose_matrix (int*** matrix, int m, int n);
int Print_matrix (int*** matrix, int m, int n);
int Destroy_matrix (int*** matrix, int n);


int main()
{
    int m = 0, n = 0;
    int** matrix;

    scanf ("%d %d", &m, &n);
    Create_matrix (&matrix, m,n);
    Scan_matrix (&matrix, m, n);
    Transpose_matrix (&matrix, m, n);
    Print_matrix (&matrix, n, m);
    Destroy_matrix (&matrix, m);
    return 0;
}


int Create_matrix (int*** matrix, int m, int n)
{
    int i = 0;
    *matrix = (int**) calloc (n, sizeof(int*));
    for (i = 0; i < n; i++)
    {
        (*matrix)[i] = (int*) calloc (m, sizeof(int));
    }
    return 0;
}

int Scan_matrix (int*** matrix, int m, int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf ("%d", &(*matrix)[i][j]);
    }
    return 0;
}


int Transpose_matrix (int*** matrix, int m, int n)
{
    int** matrix_t;
    int i = 0, j = 0;

    Create_matrix(&matrix_t, n, m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            matrix_t [j][i] = (*matrix)[i][j];
    }
    Destroy_matrix((matrix), n);
    (*matrix) = matrix_t;
    return 0;
}
int Print_matrix (int*** matrix, int m, int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf ("%6d", (*matrix)[i][j]);
        printf ("\n");
    }
    return 0;
}


int Destroy_matrix (int*** matrix, int n)
{
    int i = 0;
    for (i < 0; i < n; i++)
        free ((*matrix)[i]);
    free (*matrix);
    return 0;
}

