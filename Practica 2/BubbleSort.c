#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50
int swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
    return (0);
}

int BubbleSort(int vector[])
{
    int i, j;
    for (i = 0; i < N; i++)                     //O(n)
    {
        for (j = i + 1; j < N; j++)             //O(n - 1)/2              
        {
            if (vector[j] < vector[i])          //O(1)
            {
                swap(&vector[i], &vector[j]);   //O(1)                       
            }
        }
    }
    return 0;
}
// n(n + 1)/2  =  (n^2 + n)/2  = O(n^2) en el peor de los casos

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
    BubbleSort(vec);
    mostrar(vec);
    return 0;
}
