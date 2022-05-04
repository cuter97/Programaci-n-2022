// ejercicio 4 de la guia de pilas, ejercicio realizado con el tad de pilas con punteros.
#include <stdio.h>
#include "PilaPuntero.h"

// funcion que imprime los datos de una pila con punteros y no modifica el valor de la pila,
// sino que la vuelve a dejar como estaba.
int imprimir(Pila_T pila)
{
    Pila_T aux;
    aux = CrearPila();
    int n;
    while (!PilaVacia(pila))
    {
        n = STop(pila);
        printf("%d ", n);
        SPush(&aux, n);
        SPop(&pila);
    }
    // vuelvo a llenar la pila original
    while (!PilaVacia(aux))
    {
        n = STop(aux);
        SPush(&pila, n);
        SPop(&aux);
    }

    return 0;
}

int copiaInv(Pila_T pila)
{
    int n;
    Pila_T aux;
    aux = CrearPila();
    while (!PilaVacia(pila))
        SPush(&aux, SPop(&pila));

    while (!PilaVacia(aux))
    {
        n = SPop(&aux);
        printf("%d ", n);
        SPush(&pila, n);
    }
    
    return 0;
}
int main()
{
    Pila_T pilita, copia;
    pilita = CrearPila();
    copia = CrearPila();
    SPush(&pilita, 1);
    SPush(&pilita, 2);
    SPush(&pilita, 3);
    SPush(&pilita, 4);

    imprimir(pilita);
    printf("\n");
    imprimir(pilita);
    printf("\n");

    copiaInv(pilita);
    printf("\n");

    imprimir(pilita);
    printf("\n");
    imprimir(pilita);
    printf("\n");

    return 0;
}