#include <iostream>
#include <cstdlib>
#include "PilaVecTemp.h"
#include "PilaVecTemp.cpp"
using namespace std;

// funca piola
int main()
{
    Pila <int> pila_1(8);
    int x;

    // cout << "apilo el entero 1" << endl;
    pila_1.push(1);
    // cout << "apilo el entero 2" << endl;
    pila_1.push(2);
    // cout << "apilo el entero 4" << endl;
    pila_1.push(4);
    pila_1.push(123);
    pila_1.push(234);
    pila_1.push(7);
    pila_1.push(5);

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