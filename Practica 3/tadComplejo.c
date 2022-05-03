
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tadComplejo.h"

Complejo_T CrearListaComplejo()
{
    Complejo_T l;
    l.n = 0;
    l.listaComplejo = NULL;
    return l;
}

int InsertarComplejo(Complejo_T *l, int re, int im)
{
    struct Nodo *nuevo;
    if (ListaVacia(*l))
    {
        nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
        if (!nuevo)
        {
            printf("no se aloco memoria\n");
            exit(-1);
        }
        nuevo->Re = re;
        nuevo->Im = im;
        nuevo->sig = l->listaComplejo;
        l->listaComplejo = nuevo;
        (l->n)++;
    }
    else
    {
        struct Nodo *act, *ant, *fut;

        nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
        if (!nuevo)
        {
            printf("no se aloco memoria\n");
            exit(-1);
        }
        nuevo->Re = re;
        nuevo->Im = im;
        ant = act = l->listaComplejo;
        while (act != NULL && Modulo(act->Re, act->Im) < Modulo(nuevo->Re, nuevo->Im))
        {
            ant = act;
            act = act->sig;
        }
        if (act == ant)
        {
            if (Modulo(nuevo->Re, nuevo->Im) < Modulo(act->Re, act->Im))
            {
                nuevo->sig = act;
                l->listaComplejo = nuevo;
            }
            else
            {
                fut = act->sig;
                nuevo->sig = fut;
                ant->sig = nuevo;
            }
        }
        else
        {
            if (act == NULL)
            {
                ant->sig = nuevo;
                nuevo->sig = NULL;
            }
            else
            {
                nuevo->sig = act;
                ant->sig = nuevo;
            }
        }
    }
    return 0;
}

int Imprimir(Complejo_T l)
{
    struct Nodo *aux;
    if (!ListaVacia(l))
    {
        aux = l.listaComplejo;
        while (aux != NULL)
        {
            printf("(%d, %di)", aux->Re, aux->Im);
            aux = aux->sig;
        }
        printf("\n");
    }
    else
        printf("la lista esta vacia\n");
    return 0;
}

int ListaVacia(Complejo_T l)
{
    return (l.n == 0);
}

float Modulo(int re, int img)
{
    return ((float)sqrt(pow(re, 2) + pow(img, 2)));
}