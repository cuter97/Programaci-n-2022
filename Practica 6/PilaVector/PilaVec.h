#ifndef PILA_ENTEROS
#define PILA_ENTEROS

#include <iostream>
#include <cstdlib>
using namespace std;
// capacidad por defecto
#define SIZE 10

// clase pila
class Pila
{
    private:
        int *arreglo;
        int tope;
        int capacidad;

    public:
        Pila(int size = SIZE); // constructor
        ~Pila();               // destructor

        void push(int);
        int pop();
        int top();

        int size();
        bool isEmpty();
        bool isFull();
};

#endif