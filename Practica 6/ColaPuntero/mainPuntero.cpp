#include <iostream>
#include <cstdlib>
#include "ColaPuntero.h"
#include "ColaPuntero.cpp"
using namespace std;

int main()
{
    ColaP<float> *cola = new ColaP<float>();

    cola->Qpush(2.43534);
    cola->Qpush(2.34534);
    cola->Qpush(2.234);
    cola->Qpush(2.745);
    cola->Qpush(2.8);

    cout << "tope: " << cola->Qtop() << "\n";
    cout << "cantidad: " << cola->longitudCola() << "\n";
    cola->imprimir();
    return 0;
}