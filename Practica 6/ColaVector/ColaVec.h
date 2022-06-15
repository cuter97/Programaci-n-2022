#ifndef COLA_ENTEROS
#define COLA_ENTEROS

#include <iostream>
#include <cstdlib>
using namespace std;
// capacidad por defecto
#define SIZE 10

// clase pila
class Cola
{
    private:
        int *arreglo;
        int frente;
        int final;
        int capacidad;

    public:
        Cola(int size = SIZE); // constructor
        ~Cola();               // destructor

        void Q_push(int x);
        int Q_pop();
        int Q_top();

        int longitud_Cola();
        bool cola_Llena();
        bool cola_vacia();
        void imprimir();
};

#endif