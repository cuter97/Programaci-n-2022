#include <stdio.h>
#include <stdlib.h>
#include "ColaP.h"

Cola_T CrearCola()
{
    Cola_T cola;
    cola.frente = NULL;
    cola.final = NULL;
    cola.size = 0;
    return cola;
}

int QPush(Cola_T *cola, Tipo_Dato x)
{
    struct NodoC *nuevo;
    nuevo = (struct NodoC *)malloc(sizeof(struct NodoC));
    if (!nuevo)
    {
        printf("no se aloco memoria\n");
        exit(-1);
    }
    nuevo->dato = x;
    nuevo->sig = NULL;

    if (ColaVacia(*cola))
        cola->frente = nuevo;
    else
        cola->final->sig = nuevo;

    cola->final = nuevo;
    (cola->size)++;
    return 0;
}

Tipo_Dato QPop(Cola_T *cola)
{
    Tipo_Dato dato;
    if (!ColaVacia(*cola))
    {
        struct NodoC *aux;
        aux = cola->frente;
        dato = cola->frente->dato;
        cola->frente = cola->frente->sig;
        free(aux);
        (cola->size)--;
        return dato;
    }
    else
    {
        printf("Error: la cola esta vacia\n");
        exit(-1);
    }
}

int ColaVacia(Cola_T cola)
{
    return cola.size == 0;
}

Tipo_Dato QTop(Cola_T cola)
{
    if (ColaVacia(cola))
    {
        printf("Error: cola vacía ");
        exit(-1);
    }
    return (cola.frente->dato);
}

int LongitudCola(Cola_T cola)
{
    return cola.size;
}

int VaciarCola(Cola_T *cola)
{
    while (!ColaVacia(*cola))
        QPop(cola);
}
