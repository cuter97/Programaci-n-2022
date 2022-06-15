#include <stdlib.h>
#include <stdio.h>
#include "ColaVec.h"

using namespace std;

Cola::Cola(int size)
{
    capacidad = size;
    arreglo = new int[size];
    frente = 0;
    final = -1;
}

Cola::~Cola(){
    // delete []arreglo;// no me funciona el delete con colas
    final = -1; 
}

void Cola::Q_push(int x)
{
    if (cola_Llena())
    {
        cout << "cola llena...\n";
        exit(EXIT_FAILURE);
    }
    final = final + 1;
    arreglo[final] = x;
}

int Cola::Q_pop()
{
    if (cola_vacia())
    {
        cout << "cola llena\n";
        exit(EXIT_FAILURE);
    }
    int dato = arreglo[frente];
    frente = frente + 1;
    return dato;
}

bool Cola::cola_Llena()
{
    return (final == capacidad - 1);
}

bool Cola::cola_vacia()
{
    return (((frente == final + 1) || (final == -1)) ? true : false);
}

int Cola::longitud_Cola()
{
    return final + 1; 
}

int Cola::Q_top()
{
    if (cola_vacia())
    {
        cout << "cola llena\n";
        exit(EXIT_FAILURE);
    }
    return arreglo[frente];
}


void Cola::imprimir()
{
    while (!cola_vacia())
        cout << Q_pop() << endl;
}