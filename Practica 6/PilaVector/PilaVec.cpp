#include <iostream>
#include <cstdlib>
#include "PilaVec.h"

using namespace std;

// constructor que inicializa la Pila
Pila::Pila(int size)
{
    arreglo = new int[size];
    capacidad = size;
    tope = -1;
}

//destructor de la Pila
Pila::~Pila() {
  delete[] arreglo;
}

// agrega a la pila si la pila no esta llena
void Pila::push(int x)
{
    if (isFull())
    {
        cout << "la pila esta llena\n";
        exit(EXIT_FAILURE);
    }
    arreglo[++tope] = x;
}

// saca un elemento de la pila si no esta vacia
int Pila::pop()
{
    if (isEmpty())
    {
        cout << "la pila esta llena\n";
        exit(EXIT_FAILURE);
    }
    return arreglo[tope--];
}

// retorna el elemnto de la pila sin modificarla
int Pila::top()
{
    if (!isEmpty())
        return arreglo[tope];
    else
        exit(EXIT_FAILURE);
}

// retorna la cantidad de elementos de la Pila
int Pila::size()
{
    return tope + 1;
}

// retorna si la pila esta vacia
bool Pila::isEmpty()
{
    return tope == -1; // tambien: return size == 0;
}

// retorna si la pila esta llena
bool Pila::isFull()
{
    return tope == capacidad - 1; // tambien: return size == capacidad;
}
