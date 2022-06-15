#include <iostream>
#include <cstdlib>
#include "ColaVecTemp.h"
#include "ColaVecTemp.cpp"
using namespace std;

//funciona bien el tad
int main()
{
    Cola <float> cola(10);

    // cola.Q_push('a');
    // cola.Q_push('a');
    // cola.Q_push('v');
    // cola.Q_push('g');
    cola.Q_push(5.234);
    cola.Q_push(5.24323);
    cola.Q_push(5.234);
    cola.Q_push(5.234);
    cola.Q_push(5.234);

    float x;
    x = cola.Q_pop();
    cout << "desapilo el entero " << x << endl;
    x = cola.Q_pop();
    cout << "desapilo el entero " << x << endl;

    cout << "el elemento del tope de la pila es: " << cola.Q_top() << endl;

    cola.cola_vacia() == true ? cout << "cola vacia" << '\n' : cout << "cola no vacia" << '\n';

    cola.imprimir();
    cola.~Cola();
    cola.cola_vacia() == true ? cout << "cola vacia" << '\n' : cout << "cola no vacia" << '\n';

    return 0;
}