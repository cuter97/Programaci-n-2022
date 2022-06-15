#include <iostream>
#include <cstdlib>
#include "PilaP.h"

using namespace std;

template <class T>
Pila<T>::Pila()
{
    raiz = NULL;
}

template <class T>
Pila<T>::~Pila()
{
    Nodo *aux = raiz;
    Nodo *bor;
    while (aux != NULL)
    {
        bor = aux;
        aux = aux->sig;
        delete bor;
    }
}

template <class T>
void Pila<T>::sPush(T x)
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->dato = x;

    if (raiz == NULL)
    {
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

template <class T>
T Pila<T>::sPop()
{
    if (raiz != NULL)
    {
        T dato = raiz->dato;
        Nodo *aux = raiz;
        raiz = raiz->sig;
        delete aux;
        return dato;
    }
    else
        return -1;
}

template <class T>
bool Pila<T>::pilaVacia()
{
    return (raiz == NULL ? true : false);
}

template <class T>
T Pila<T>::sTop()
{
    T x;
    if (raiz == NULL)
        cout << "\nPila Vacia...";
    else
        x = raiz->dato;

    return x;
}

template <class T>
int Pila<T>::longitud()
{
    Nodo *aux = raiz;
    int cant = 0;
    while (aux != NULL)
    {
        cant++;
        aux = aux->sig;
    }
    return cant;
}

template <class T>
void Pila<T>::imprimir()
{
    while (!pilaVacia())
        cout << sPop() << endl;
}