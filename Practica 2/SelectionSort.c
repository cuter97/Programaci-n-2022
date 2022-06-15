#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
int swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
    return (0);
}
int SelectionSort(int vector[])
{
    int i, j, p, limite = N - 1;
    // inicializacion del vector
    for (i = 0; i < limite; i++)
    {
        p = i;
        for (j = i + 1; j <= limite; j++)
        {
            if (vector[j] < vector[p])
            {
                p = j;
            }
        }
        if (p != i)
        {
            swap(&vector[p], &vector[i]);
        }
    }
    return 0;
}
int mostrar(int vector[])
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", vector[i]);
    printf("\n");
    return 0;
}
int main()
{
    int vec[N];
    int i;
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
        vec[i] = rand() % 10;
        printf("%d ", vec[i]);
    }
    printf("\n");
    SelectionSort(vec);
    mostrar(vec);
    return 0;
}
