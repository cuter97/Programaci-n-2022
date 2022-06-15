#ifndef COLA_PUNTEROS
#define COLA_PUNTEROS

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class ColaP
{
    private:
        class NodoPun
        {
            public:
                T dato;
                NodoPun *sig;
        };

        NodoPun *frente;
        NodoPun *final;
        int size;

    public:
        ColaP();
        ~ColaP();
        void Qpush(T x);
        T Qpop();
        T Qtop();
        bool colaVacia();
        int longitudCola();
        void imprimir();
};
#endif