#include <stdio.h>
#include <stdlib.h>

int Create_array (int** array, int n);
int Scan_array (int** array,int n);
int Print_array (int* array, int n);
int Compare (const void *x1, const void *x2);

int main()
{
    int n = 0;
    int* array;
    int i = 0;

    scanf ("%d", &n);
    Create_array(&array, n);
    Scan_array (&array, n);
    qsort (array, n, sizeof(int), Compare);
    Print_array (array, n);

    free(array);
    return 0;
}

int Create_array (int** array, int n)
{
    *array = (int*) calloc (n, sizeof(int));

    return 0;
}
int Scan_array (int** array,int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf ("%d,", &(*array)[i]);
    }

    return 0;
}

int Compare (const void *x1, const void *x2)
{
    return (*(int*)x1 - *(int*) x2);
}

int Print_array (int* array, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf ("%d ", array[i]);
    }
    return 0;
}
