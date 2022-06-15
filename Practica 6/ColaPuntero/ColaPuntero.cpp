#include <iostream>
#include <cstdlib>
#include "ColaPuntero.h"

using namespace std;

template <class T>
ColaP<T>::ColaP()
{
    frente = NULL;
    final = NULL;
    size = 0;
}

template <class T>
ColaP<T>::~ColaP()
{
    while (!colaVacia())
        Qpop();
}

template <class T>
void ColaP<T>::Qpush(T x)
{
    NodoPun *nuevo;
    nuevo = new NodoPun();
    nuevo->dato = x;
    nuevo->sig = NULL;

    if (colaVacia())
        frente = nuevo;
    else
        final->sig = nuevo;

    final = nuevo;
    size = size + 1;
}

template <class T>
T ColaP<T>::Qpop()
{
    if(colaVacia())
    {
        cout << "error: cola vacia...\n";
        exit(EXIT_FAILURE);
    }
    NodoPun *aux;
    aux = frente;
    T dato = frente->dato;
    frente = frente->sig;
    delete(aux);
    size = size - 1;
    return dato;
}

template <class T>
bool ColaP<T>::colaVacia()
{
    return (size == 0);
}

template <class T>
int ColaP<T>::longitudCola()
{
    return size;
}


template <class T>
T ColaP<T>::Qtop()
{
    if (colaVacia())
    {
        cout << "error: cola vacia...\n";
        exit(EXIT_FAILURE);
    }
    return frente->dato;
}

template <class T>
void ColaP<T>::imprimir()
{
    while (!colaVacia())
        cout << Qpop() << endl;
}