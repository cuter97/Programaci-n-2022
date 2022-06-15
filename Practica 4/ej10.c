/*10) Se tiene una pila de enteros positivos. Con las operaciones básicas de pilas y colas escribir
un programa para poner todos los elementos que son par de la pila en una cola.
Luego, mostrar los elementos de la cola. NO acceder a la estructura, usar funciones del TAD.*/

#include <stdio.h>
#include <stdlib.h>
// tad de pila y cola con arreglos
#include "../TadCola/Cola.h" 
#include "../TadPila/Pila.h"

int LlenarPilaOriginal(Pila_T *pila);
int MostrarPila(Pila_T pila);
Cola_T numParCola(Pila_T pila);
int MostrarCola(Cola_T cola);

int main()
{

    Pila_T pilaOriginal;
    Cola_T cola;

    pilaOriginal = Crear_Pila();
    cola = Crear_Cola();

    LlenarPilaOriginal(&pilaOriginal);
    MostrarPila(pilaOriginal);
    cola = numParCola(pilaOriginal);
    MostrarCola(cola);

    return 0;
}

int LlenarPilaOriginal(Pila_T *pila)
{
    int n;
    do
    {
        scanf("%d",&n);
        S_Push(pila, n);
    } while (S_Top(*pila) != -1 && !Pila_Llena(*pila));
    S_Pop(pila);

    return 0;
}

int MostrarPila(Pila_T pila)
{
    while (!Pila_Vacia(pila))
        printf("%d ", S_Pop(&pila));

    printf("\n");
    return 0;
}

Cola_T numParCola(Pila_T pila)
{
    Cola_T aux;
    int a;
    aux = Crear_Cola();
    while (!Pila_Vacia(pila) && !Cola_Llena(aux))
    {
        a = S_Pop(&pila);
        if (a % 2 == 0)
            Q_Push(&aux, a);
    }
    return aux;
}

int MostrarCola(Cola_T cola)
{
    while (!Cola_Vacia(cola))
        printf("%d ", Q_Pop(&cola));
    return 0;
}