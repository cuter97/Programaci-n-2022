/*12) Escribir un programa en el que se generen 100 números
 aleatorios entre -25 y +25 y se guarden en una
cola. Una vez creada la cola, implementar una función que forma
ra cola con los números negativos de la cola
original. NO acceder a la estructura, usar funciones del TAD.*/

#include <stdio.h>
#include <stdlib.h>
// cola con arreglos
#include "../TadCola/Cola.h"

int llenarCola(Cola_T *cola);
void mostrar(Cola_T cola);
Cola_T negativosCola(Cola_T cola);

int main()
{
    Cola_T cola, colaneg;
    cola = Crear_Cola();
    colaneg = Crear_Cola();

    llenarCola(&cola);
    mostrar(cola);
    printf("\n");
    colaneg = negativosCola(cola);
    mostrar(colaneg);

    return 0;
}

int llenarCola(Cola_T *cola)
{
    int n;
    while (!Cola_Llena(*cola))
    {
        n = rand() % 51 - 25;
        Q_Push(cola, n);
    }
    return 0;
}

void mostrar(Cola_T cola)
{
    while (!Cola_Vacia(cola))
        printf("%d ", Q_Pop(&cola));
}

Cola_T negativosCola(Cola_T cola)
{
    Cola_T aux;
    aux = Crear_Cola();
    int a;
    while (!Cola_Vacia(cola))
    {
        a = Q_Pop(&cola);
        if (a < 0)
            Q_Push(&aux, a);
    }
    return aux;
}