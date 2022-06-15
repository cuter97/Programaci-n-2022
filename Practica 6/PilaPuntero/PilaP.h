#ifndef PILA_PUNTEROS
#define PILA_PUNTEROS
#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
class Pila
{
    private:
        class Nodo
        {
        public:
            T dato;
            Nodo *sig;
        };

        Nodo *raiz;

    public:
        Pila();
        ~Pila();
        void sPush(T x);
        T sPop();
        T sTop();
        bool pilaVacia();
        int longitud();
        void imprimir();
};
#endif