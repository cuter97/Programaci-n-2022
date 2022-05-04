/*6) Genera una pila con N enteros aleatorios, en el rango de valores de 0..99. Luego, procese la pila de tal forma
que contenga todos sus valores excepto los valores pares, en el mismo orden de la pila original.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../TadPila/PilaPuntero.h"

int imprimir(Pila_T pila);
int GenerarPila(Pila_T *pila, int n);
Pila_T Pares(Pila_T pila);

int main()
{
    Pila_T pila, pila2;
    pila = CrearPila();
    pila2 = CrearPila();

    srand(time(NULL));
    int datos = 10;
    GenerarPila(&pila, datos);
    imprimir(pila);
    printf("\n");

    pila2 = Pares(pila);
    imprimir(pila2);
    printf("\n");

    return 0;
}

int GenerarPila(Pila_T *pila, int n)
{
    for (int i = 0; i < n; i++)
        SPush(pila, rand()%100);

    return 0;
}

int imprimir(Pila_T pila)
{
    Pila_T aux;
    aux = CrearPila();
    int n;
    while (!PilaVacia(pila))
    {
        n = SPop(&pila);
        printf("%d ", n);
        SPush(&aux, n);
    }
    // vuelvo a llenar la pila original
    while (!PilaVacia(aux))
        SPush(&pila, SPop(&aux));

    return 0;
}

Pila_T Pares(Pila_T pila)
{
    Pila_T aux, aux2;
    aux = CrearPila();
    aux2 = CrearPila();

    int n;
    while (!PilaVacia(pila))
    {
        n = SPop(&pila);
        if(n % 2 == 0)
            SPush(&aux, n);
    }
    while (!PilaVacia(aux))
        SPush(&aux2, SPop(&aux));
    
    return aux2;
}