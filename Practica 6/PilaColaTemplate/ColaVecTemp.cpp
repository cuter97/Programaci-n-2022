#include <stdlib.h>
#include <stdio.h>
#include "ColaVecTemp.h"

using namespace std;

template <class T>
Cola<T>::Cola(int size)
{
    capacidad = size;
    arreglo = new T [size];
    frente = 0;
    final = -1;
}

template <class T>
Cola<T>::~Cola(){
    // delete []arreglo;// no me funciona el delete con colas
    final = -1; 
}

template <class T>
void Cola<T>::Q_push(T x)
{
    if (cola_Llena())
    {
        cout << "cola llena...\n";
        exit(EXIT_FAILURE);
    }
    final = final + 1;
    arreglo[final] = x;
}

template <class T>
T Cola<T>::Q_pop()
{
    if (cola_vacia())
    {
        cout << "cola llena\n";
        exit(EXIT_FAILURE);
    }
    T dato = arreglo[frente];
    frente = frente + 1;
    return dato;
}

template <class T>
bool Cola<T>::cola_Llena()
{
    return (final == capacidad - 1);
}

template <class T>
bool Cola<T>::cola_vacia()
{
    return (((frente == final + 1) || (final == -1)) ? true : false);
}

template <class T>
int Cola<T>::longitud_Cola()
{
    return final + 1; 
}

template <class T>
T Cola<T>::Q_top()
{
    if (cola_vacia())
    {
        cout << "cola llena\n";
        exit(EXIT_FAILURE);
    }
    return arreglo[frente];
}

template <class T>
void Cola<T>::imprimir()
{
    while (!cola_vacia())
        cout << Q_pop() << endl;
}