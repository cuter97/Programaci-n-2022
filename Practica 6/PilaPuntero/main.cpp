#include <iostream>
#include "PilaP.h"
#include "PilaP.cpp"

using namespace std;
//funciona
int main()
{
    Pila<float> *pila1;
    pila1 = new Pila<float>();
    pila1->sPush(1.56345);
    pila1->sPush(2.345);
    pila1->sPush(3.2345);
    pila1->sPush(4.974);
    pila1->sPush(34.234);
    pila1->sPush(634.37);
    pila1->sPush(243.8);
    pila1->sPush(41.9);
    cout << "tope: " << pila1->sTop() << "\n";
    cout << "cantidad: " << pila1->longitud() << "\n";
    // while (pila1->pilaVacia() == false)
    //     cout << "exraemos pila: " << pila1->sPop() << "\n";
    pila1->imprimir();
    return 0;
}