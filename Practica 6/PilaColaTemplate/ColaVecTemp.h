#ifndef COLA_ENTEROS
#define COLA_ENTEROS

#include <iostream>
#include <cstdlib>
using namespace std;
// capacidad por defecto
#define SIZE 10

// clase pila
template <class T>
class Cola
{
    private:
        T *arreglo;
        int frente;
        int final;
        int capacidad;

    public:
        Cola(int size = SIZE); // constructor
        ~Cola();               // destructor

        void Q_push(T x);
        T Q_pop();
        T Q_top();

        int longitud_Cola();
        bool cola_Llena();
        bool cola_vacia();
        void imprimir();
};

#endif