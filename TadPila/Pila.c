#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

// Crea una pila vacía
Pila_T Crear_Pila()
{
    Pila_T pila;
    pila.indice = -1;
    pila.max = TamMax;
    return pila;
}

// Añade x a la pila, si la misma no está llena. Si está llena determinar el valor retornado.
int S_Push(Pila_T *pila, TipoDato x)
{
    if (!Pila_Llena(*pila))
    {
        pila->indice = pila->indice + 1;
        pila->pila[pila->indice] = x;
    }
    else
        printf("Error: pila llena\n");
    return 0;
}

// Saca un elemento de la pila si la pila no está vacía. La función retorna dicho dato. Determinar valor
// Determinar valor retornado si la pila está vacía.
TipoDato S_Pop(Pila_T *pila)
{
    if (!Pila_Vacia(*pila))
    {
        TipoDato dato;
        dato = pila->pila[pila->indice];
        pila->indice = pila->indice - 1;
        return dato;
    }
    else
    {
        printf("Error pop: pila vacia\n");
        exit(-1);
    }
}

// Retorna True si la pila está llena. False caso contrario.
int Pila_Llena(Pila_T pila)
{
    return (pila.indice == pila.max - 1);
}

// retorna True si la pila está vacía. False caso contrario.
int Pila_Vacia(Pila_T pila)
{
    return (pila.indice == -1);
}

// Retorna el dato que está en el tope de la pila, pero sin sacarlo (no modifica la pila)
TipoDato S_Top(Pila_T pila)
{
    if (!Pila_Vacia(pila))
    {
        return pila.pila[pila.indice];
    }
    else
        printf("Error: pila vacia\n");
    exit(-1);
}

// Retorna la longitud de la pila.
int Longitud_Pila(Pila_T pila)
{
    return pila.indice;
}

// Vacia la pila pasada como parámetro.
int Vaciar_Pila(Pila_T *pila)
{
    pila->indice == -1;
    return 0;
}
