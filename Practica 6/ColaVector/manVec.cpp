#include <iostream>
#include <cstdlib>
#include "ColaVec.h"
using namespace std;

int main()
{
    Cola cola(10);

    cola.Q_push(7);
    cola.Q_push(1);
    cola.Q_push(2);
    cola.Q_push(4);
    cola.Q_push(5);
    cola.Q_push(5);
    cola.Q_push(5);
    cola.Q_push(5);
    cola.Q_push(5);

    int x;
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