#include <iostream>
#include <cstdlib>
#include "PilaVec.h"
using namespace std;

// funca piola
int main()
{
    Pila pila_1(6);
    int x;

    // cout << "apilo el entero 1" << endl;
    pila_1.push(1);
    // cout << "apilo el entero 2" << endl;
    pila_1.push(2);
    // cout << "apilo el entero 4" << endl;
    pila_1.push(4);
    pila_1.push(5);
    pila_1.push(7);

    x = pila_1.pop();
    cout << "desapilo el entero" << x << endl;
    x = pila_1.pop();
    cout << "desapilo el entero" << x << endl;

    pila_1.push(3);
    cout << "el elemento del tope de la pila es: " << pila_1.top() << endl;
    cout << "la dimension de la pila es: " << pila_1.size() << endl;

    (pila_1.isEmpty()) ? cout << "pila vacia" << '\n' : cout << "pila no vacia" << '\n';

    while (!pila_1.isEmpty())
        cout << pila_1.pop() << "\n";

    pila_1.~Pila();
    (pila_1.isEmpty()) ? cout << "pila vacia" << '\n' : cout << "pila no vacia" << '\n';

    return 0;
}