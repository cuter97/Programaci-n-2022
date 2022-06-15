#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"
int main()
{
    Arbol_T a;
    a = CrearArbol(11);
    InsertarElemento(&a, 1);
    InsertarElemento(&a, 4);
    InsertarElemento(&a, 6);
    InsertarElemento(&a, 7);
    InsertarElemento(&a, 9);
    InsertarElemento(&a, 2);
    InsertarElemento(&a, 10);
    InsertarElemento(&a, 14);
    InsertarElemento(&a, 15);
    InsertarElemento(&a, 3);
    InsertarElemento(&a, 5);
    InsertarElemento(&a, 21);
    InsertarElemento(&a, 12);
    InsertarElemento(&a, 8);

    InOrder(a);
    printf("\n");

    EliminarElemento(&a, 4);
    InOrder(a);
    printf("\n");

    if (Existe(a, 4) == 1)
        printf("el dato existe\n");
    else
        printf("el dato no existe\n");

    // ImprimirNivel(a, 3);
    // printf("\n");

    // int dato, dato2, min, max;

    // dato = ContarNodos(a);
    // printf("la cantidad de nodos es: %d \n", dato);

    // dato2 = Profundidad(a);
    // printf("la profundidad es: %d \n", dato2);

    // min = Minimo(a);
    // printf("el minimo es: %d \n", min);

    // max = Maximo(a);
    // printf("el maximo es: %d \n", max);

    // ImprimirPares(a);
    // printf("\n");
    return 0;
}
