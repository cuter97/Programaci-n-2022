#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

/* Crea una lista vacia*/
Lista_T Crear_Lista()
{
    Lista_T l;
    l.n = 0;
    l.lista = NULL;
    return l;
}

/* Inserta el dato x como primer elemento de la lista l*/
int Insertar_Primero(Lista_T *l, int x)
{
    // creacion del nodo con el nuevo elemento
    struct Nodo *nuevo;
    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (!nuevo)
    {
        printf("no se aloco memoria");
        exit(-1);
    }
    // actualizacion de punteros
    nuevo->dato = x;
    nuevo->sig = l->lista;
    l->lista = nuevo;
    // actualizacon de la cantidad de elemntos de la lista
    (l->n)++;
    return 0;
}

/* Recorre la lista imprimiento por pantalla cada dato */
int Recorrer_Lista(Lista_T l)
{
    struct Nodo *aux;
    if (!Lista_Vacia(l))
    {
        aux = l.lista;
        while (aux != NULL)
        {
            printf("%d ", aux->dato);
            aux = aux->sig;
        }
        printf("\n");
    }
    else
        printf("esta vacia\n");
    return 0;
}

/* Inserta el dato x como último elemento de la lista l*/
int Insertar_Ultimo(Lista_T *l, int x)
{
    // creamos nuevo nodo y nodo auxiliar para recorrer la lista
    struct Nodo *nuevo, *aux;
    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (!nuevo)
    {
        printf("no se aloco memoria\n");
        exit(-1);
    }
    // inicilizamos el nodo nuevo a NULL y le damos el valor
    nuevo->dato = x;
    nuevo->sig = NULL;

    if (!Lista_Vacia(*l))
    {
        // puntero auxiliar apunta a la cabeza de la lista
        aux = l->lista;
        // recorremos Lista
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        // actualizacion del puntero del ultimo Nodo
        // aux ubicado en el ultimo Nodo
        aux->sig = nuevo;
    }
    else
        // si la lista esta vacia el nuevo nodo es el primero
        l->lista = nuevo;

    // actualizamos la cantidad de elementos de la Lista
    (l->n)++;
    return 0;
}

/* Retorna True si la lista está vacia, FALSE caso contrario*/
int Lista_Vacia(Lista_T l)
{
    return (l.n == 0);
}

/* Vacia la lista, desalocando memoria alocada por la misma */
int Vaciar_Lista(Lista_T *l)
{
    // creo nodo aux
    struct Nodo *aux;
    if (!Lista_Vacia(*l))
    {
        // apunto auxiliar a la cabeza de la lista
        aux = l->lista;

        // recorro y borro
        while (aux != NULL)
        {
            l->lista = aux->sig;
            free(aux);
            aux = l->lista;

            // actualizo n
            (l->n)--;
        }
    }
    return 0;
}

/* Suprime el dato x de la lista. Si el dato no existe lo informa y la lista queda sin modificar */
int Suprimir_Dato(Lista_T *l, int x)
{
    struct Nodo *act, *ant;
    if (!Lista_Vacia(*l))
    {

        // me ubico al principio de la lista
        act = ant = l->lista;

        // avanzo en la lista hasta encontrar el dato
        while (act != NULL && act->dato != x)
        {
            ant = act;
            act = act->sig;
        }

        // si encuentro el dato lo elimino
        if (act)
        {
            if (act == ant)
            {
                l->lista = act->sig;
                ant = l->lista;
            }
            else
                ant->sig = act->sig;

            free(act);
            // actualizo la cantidad de nodos
            (l->n)--;
        }
        else
            printf("el dato no existe\n");
    }
    return 0;
}

/* Inserta el elemento x en la lista l en la posición pos. Si la posición pos es mayor que la
   longitud de la lista lo informa y no se modifica la lista */
int Insertar_Dato_Posicion(Lista_T *l, int pos, int x)
{
    // se asume como rango valido desde 1 a la cantidad de elementos
    struct Nodo *act, *nuevo;
    // verifico que la pos sea correcta
    if (!Lista_Vacia(*l) && (pos <= Longitud_Lista(*l)))
    {
        // si esta en la primer pos llamo a Insertar_Primero
        if (pos == 1)
            Insertar_Primero(l, x);
        else
        {
            // creamos nuevo nodo
            nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
            if (!nuevo)
            {
                printf("no se aloco memoria");
                exit(-1);
            }
            // me ubico al principio de la lista
            nuevo->dato = x;
            act = l->lista;
            // avanzar en la lista hasta posicion
            int i = 1;
            while (i < pos - 1)
            {
                i++;
                act = act->sig;
            }
            // actualizo punteros
            nuevo->sig = act->sig;
            act->sig = nuevo;
            // actualizo campo n
            (l->n)++;
        }
    }
    else // la pos esta fuera de rango
        printf("posicion fuera de rango\n");
    return 0;
}

/* Retorna la cantidad de elementos de la lista l*/
int Longitud_Lista(Lista_T l)
{
    return l.n;
}

/* Suprime el dato de posición pos de la lista l. Si pos no existe en la lista l
   lo informa y la lista queda sin modificar */
int Suprimir_Dato_Posicion(Lista_T *l, int pos)
{
    struct Nodo *act, *ant;
    if (!Lista_Vacia(*l) && pos <= Longitud_Lista(*l))
    {
        // me ubico al principio de la lista
        ant = act = l->lista;

        // avanzo en la lista hasta encontrar la posición
        int i = 1;
        while (i != pos)
        {
            ant = act;
            act = act->sig;
            i++;
        }
        // una vez que encontro la posición actualizo punteros y borro el nodo
        if (ant == act)
        {
            l->lista = act->sig;
            ant = l->lista;
        }
        else
            ant->sig = act->sig;

        free(act);
        (l->n)--;
    }
    else
        printf("la posición no existe o su lista se encuentra vacia\n");
    return 0;
}

/* Retorna el elemento de posición pos de la lista l. En caso que pos no existe en la lista lo informa.
   En ambos casos la lista no es modificada. */
int Devolver_Dato_Posicion(Lista_T l, int pos)
{
    struct Nodo *aux;
    // corroboramos que la posicion sea valida
    if ((pos >= 1) && (pos <= Longitud_Lista(l)))
    {
        // nos colocamos al principio de la lista
        aux = l.lista;
        int i = 1;
        // avanzamos hasta la posicion deseada
        while (i < pos)
        {
            i++;
            aux = aux->sig;
        }
        // retornamos valor
        return (aux->dato);
    }
    else
    {
        printf("la posición no existe\n");
        exit(-1);
    }
}
