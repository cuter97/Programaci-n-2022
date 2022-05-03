#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>

// funcion que crea un conjunto y lo retorna
Conjunto_T CrearConjunto()
{
    Conjunto_T conj;
    conj.n = 0;
    conj.conjunto = NULL;
    return conj;
}

// retorna la cantidad de elemntos del conjunto
int Cardinal(Conjunto_T conj)
{
    return conj.n;
}

// Retorna 1 si el conjunto está vacio, 0 caso contrario
int ConjuntoVacio(Conjunto_T conj)
{
    return (conj.n == 0);
}

// funcion que retorna 1 si el elemento x pertenece al conjunto, 0 caso contrario
int Existe(Conjunto_T conj, int x)
{
    struct Nodo *act, *ant;
    if (!ConjuntoVacio(conj))
    {
        // me ubico al principio del conjunto
        act = ant = conj.conjunto;

        // avanzo en el conjunto hasta encontrar el dato
        while (act != NULL && act->dato != x)
        {
            ant = act;
            act = act->sig;
        }

        // si el dato se encontro y es distinto de null retorno 1 sino 0
        // if (act)
        if (act != NULL && act->dato == x)
            return 1;
        else
            return 0;
    }
}

// funcion que agrega un elemento x al conjunto
int InsertarElemento(Conjunto_T *conj, int x)
{
    // creacion del nodo con el nuevo elemento
    struct Nodo *nuevo;
    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (!nuevo)
    {
        printf("no se aloco memoria");
        exit(-1);
    }

    if (!ConjuntoVacio(*conj))
    {
        // primero verifico si el dato ya existe en el conjunto
        if (Existe(*conj, x) != 1)
        {
            // actualizacion de punteros
            nuevo->dato = x;
            nuevo->sig = conj->conjunto;
            conj->conjunto = nuevo;
            // actualizacon de la cantidad de elemntos de la lista
            (conj->n)++;
        }
    }
    else
    {
        // si el conjunto esta vacio lo agrega al principio
        nuevo->dato = x;
        nuevo->sig = NULL;
        conj->conjunto = nuevo;
        (conj->n)++;
    }

    return 0;
}

// imprime en pantalla los elementos del conjunto
int Imprimir(Conjunto_T conj)
{
    struct Nodo *aux;
    if (!ConjuntoVacio(conj))
    {
        aux = conj.conjunto;
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

// diferencia de dos conjuntos (x ∈ A−B cuando x ∈ A pero x ∈/ B)
/* la diferencia de dos conjuntos es una operación que da como resultado otro
conjunto con los elementos del primer conjunto sin los elementos del segundo conjunto.*/
Conjunto_T Diferencia(Conjunto_T A, Conjunto_T B)
{
    Conjunto_T C;
    C = CrearConjunto();

    struct Nodo *aux;
    aux = A.conjunto;

    while (aux != NULL)
    {
        if (Existe(B, aux->dato) == 0)
            InsertarElemento(&C, aux->dato);

        aux = aux->sig;
    }

    return C;
}