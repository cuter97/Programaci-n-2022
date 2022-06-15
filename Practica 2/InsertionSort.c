#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

int InsertionSort(int vector[])
{
    int i, j, aux;
    // inicializacion del vector
    for (i = 0; i < N; i++)                       //O(n)
    {
        aux = vector[i];                          //O(1)
        j = i - 1;                                //O(1)
        while ((j >= 0) && (vector[j] > aux))     // O(n/2)
        {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = aux;                      //O(1)
    }
    return 0;
}
// n(n/2)  =  (n^2z)/2  = O(n^2) en el peor de los casos

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
    InsertionSort(vec);
    mostrar(vec);
    return 0;
}
