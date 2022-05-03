#include "listaDE.h"
#include <stdlib.h>
#include <stdio.h>

ListaDE_T CrearLista()
{
    ListaDE_T l;
    l.n = 0;
    l.primero = NULL;
    l.ultimo = NULL;
    return l;
}

int InsertarPrimero(ListaDE_T *l, int x)
{
    struct NodoDE *nuevo;
    nuevo = (struct NodoDE *)malloc(sizeof(struct NodoDE));
    if (!nuevo)
    {
        printf("no se aloco memoria \n");
        exit(-1);
    }

    nuevo->dato = x;
    nuevo->sig = l->primero;
    nuevo->ant = NULL;

    if (l->n == 0)
    {
        l->ultimo = nuevo;
    }
    else
        l->primero->ant = nuevo;

    l->primero = nuevo;
    (l->n)++;

    return 0;
}

// inserta el nodo con el dato x como el ultimo elemento de la lista
int InsertarUltimo(ListaDE_T *l, int x)
{
    struct NodoDE *nuevo, *aux;

    nuevo = (struct NodoDE *)malloc(sizeof(struct NodoDE));
    if (!nuevo)
    {
        printf("no se aloco memoria\n");
        exit(-1);
    }

    nuevo->dato = x;
    nuevo->sig = NULL;

    if (!ListaVacia(*l))
    {
        aux = l->ultimo;
        nuevo->ant = aux;
        aux->sig = nuevo;
    }
    else
        l->primero = nuevo;

    l->ultimo = nuevo;
    (l->n)++;

    return 0;
}

// recorre la lista en orden imprimiendo sus elementos
int RecorrerListaEnOrden(ListaDE_T l)
{
    if (!ListaVacia(l))
    {
        struct NodoDE *aux;
        aux = l.primero;
        while (aux != NULL)
        {
            printf("%d ", aux->dato);
            aux = aux->sig;
        }
        printf("\n");
    }
    else
        printf("la lista esta vacia \n");
    return 0;
}

// recorre la lista en orden inverso imprimiendo sus elementos
int RecorrerListaEnOrdenInverso(ListaDE_T l)
{
    if (!ListaVacia(l))
    {
        struct NodoDE *aux;
        aux = l.ultimo;
        while (aux != NULL)
        {
            printf("%d ", aux->dato);
            aux = aux->ant;
        }
        printf("\n");
    }
    else
        printf("la lista esta vacia \n");
    return 0;
}

// retorna si la lista esta vacia
int ListaVacia(ListaDE_T l)
{
    return (l.n == 0);
}

// Elimina el dato con posición {pos} de la lista (liberando memoria). Determinar la acción a realizar en caso que la posición no exista en la lista. */
int SuprimirDatoPosicion(ListaDE_T *l, int pos)
{
    if (!ListaVacia(*l) && pos <= LongitudLista(*l))
    {
        struct NodoDE *act, *anterior;
        anterior = act = l->primero;
        int i = 1;

        while (i != pos)
        {
            anterior = act;
            act = anterior->sig;
            i++;
        }
        if (anterior == act)
        {
            l->primero = act->sig;
            act->sig->ant = NULL;
        }
        if (act->sig == NULL)
        {
            l->ultimo = act->ant;
            anterior->sig = NULL;
        }
        else
        {
            anterior->sig = act->sig;
            act->sig->ant = act->ant;
        }
        free(act);
        (l->n)--;
    }
    else
        printf("la posicion no existe o la lista esta vacia \n");

    return 0;
}

// desaloca la memoria de cada nodo. Longitud de la lista = 0.
int VaciarLista(ListaDE_T *l)
{
    if (!ListaVacia(*l))
    {
        struct NodoDE *aux;
        aux = l->primero;
        while (aux != NULL)
        {
            l->primero = aux->sig;
            free(aux);
            aux = l->primero;
            (l->n)--;
        }
    }
    return 0;
}

// Elimina el nodo con el dato x de la lista.
int SuprimirDato(ListaDE_T *l, int x)
{
    if (!ListaVacia(*l))
    {
        struct NodoDE *act, *anterior;
        act = anterior = l->primero;
        while (act != NULL && act->dato != x)
        {
            anterior = act;
            act = act->sig;
        }
        if (act)
        {
            if (anterior == act)
            {
                l->primero = act->sig;
                act->sig->ant = NULL;
            }
            if (act->sig == NULL)
            {
                l->ultimo = act->ant;
                anterior->sig = NULL;
            }
            else
            {
                anterior->sig = act->sig;
                act->sig->ant = act->ant;
            }
            free(act);
            (l->n)--;
        }
        else
            printf("el dato no existe \n");
    }
    else
        printf("lista vacia \n");
    return 0;
}

// retorna la longitud de la lista
int LongitudLista(ListaDE_T l)
{
    return l.n;
}

// devuelve el dato de la posición pos.
int DevolverDatoPosicion(ListaDE_T l, int pos)
{
    struct NodoDE *aux;
    if ((pos >= 1) && (pos <= LongitudLista(l)))
    {
        aux = l.primero;
        int i = 1;
        while (i < pos)
        {
            i++;
            aux = aux->sig;
        }
        return (aux->dato);
    }
    else
    {
        printf("la posición no existe\n");
        exit(-1);
    }
}

// se inserta el dato x en la pos deseada.
int InsertarPosicion(ListaDE_T *l, int pos, int x)
{
    // se asume como rango valido desde 1 a la cantidad de elementos de la lista
    if (!ListaVacia(*l) && (pos <= LongitudLista(*l)))
    {
        struct NodoDE *act, *anterior, *nuevo;
        if (pos == 1)
        {
            InsertarPrimero(l, x);
        }
        else
        {
            nuevo = (struct NodoDE *)malloc(sizeof(struct NodoDE));
            if (!nuevo)
            {
                printf("no se aloco memoria");
                exit(-1);
            }
            nuevo->dato = x;
            act = l->primero;
            int i = 1;
            while (i != pos)
            {
                anterior = act;
                act = act->sig;
                i++;
            }
            anterior->sig = nuevo;
            nuevo->sig = act;
            act->ant = nuevo;
            nuevo->ant = anterior;
            (l->n)++;
        }
    }
    else
        printf("posicion fuera de rango \n");
    return 0;
}
