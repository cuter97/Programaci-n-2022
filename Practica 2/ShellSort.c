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
int ShellSort(int *vector)
{
    int i, j, incr = N;
    // inicializacion del vector
    do
    {
        for (i = incr; i < N; i++)
        {
            for (j = i; (j >= incr) && (vector[j - incr] > vector[j]); j -= incr)
            {
                swap(&vector[j], &vector[j - incr]);
            }
        }
        incr = incr / 2;
    } while (incr > 0);
    return 0;
}
int mostrar(int *vector)
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
    ShellSort(vec);
    mostrar(vec);
    return 0;
}
