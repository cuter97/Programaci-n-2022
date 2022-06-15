#ifndef PILA_ENTEROS
#define PILA_ENTEROS

#include <iostream>
#include <cstdlib>

using namespace std;
// capacidad por defecto
#define SIZE 10

template <class T>
class Pila {
    private:
        int capacidad;
        int tope;
        T *arreglo;

    public:
        Pila(int size = SIZE); // constructor
        ~Pila();               // destructor
  
        void push(T x);
        T pop();
        T top();

        int size();
        bool isEmpty();
        bool isFull();
};
#endif