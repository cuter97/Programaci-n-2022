#include <iostream>
#include <cstdlib>
#include "PilaVecTemp.h"

// constructor que inicializa la Pila
template <class T>
Pila<T>::Pila(int size)
{
    arreglo = new T [size];
    capacidad = size;
    tope = -1;
}

//destructor de la Pila
template <class T>
Pila<T>::~Pila() {
  delete[] arreglo;
}

// agrega a la pila si la pila no esta llena
template <class T>
void Pila<T>::push(T x)
{
    if (isFull())
    {
        cout << "la pila esta llena\n";
        exit(EXIT_FAILURE);
    }
    arreglo[++tope] = x;
}

// saca un elemento de la pila si no esta vacia
template <class T>
T Pila<T>::pop()
{
    if (isEmpty())
    {
        cout << "la pila esta llena\n";
        exit(EXIT_FAILURE);
    }
    return arreglo[tope--];
}

// retorna el elemnto de la pila sin modificarla
template <class T>
T Pila<T>::top()
{
    if (!isEmpty())
        return arreglo[tope];
    else
        exit(EXIT_FAILURE);
}

// retorna la cantidad de elementos de la Pila
template <class T>
int Pila<T>::size()
{
    return tope + 1;
}

// retorna si la pila esta vacia
template <class T>
bool Pila<T>::isEmpty()
{
    return tope == -1; // tambien: return size == 0;
}

// retorna si la pila esta llena
template <class T>
bool Pila<T>::isFull()
{
    return tope == capacidad - 1; // tambien: return size == capacidad;
}