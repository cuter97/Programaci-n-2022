/*7) Se desea formar una lista enlazada de números aleatorios.
El programa que realiza esta tarea inserta los nuevos nodos por la cabeza de la lista.
Una vez creada la lista, se recorren los nodos para mostrar los números pares.
Implementar con funciones.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../Tadlista/lista.h"

int datosRandom(Lista_T *lista, int cant);
int mostrarPares(Lista_T lista);

int main()
{
    srand(time(NULL));
    int cantidadDatos = 10;
    Lista_T datos;
    datos = Crear_Lista();

    datosRandom(&datos, cantidadDatos);
    Recorrer_Lista(datos);
    printf("\n");
    mostrarPares(datos);
    printf("\n");
}

int datosRandom(Lista_T *lista, int cant)
{
    for (int i = 0; i < cant; i++)
        Insertar_Primero(lista, rand() % 10);

    return 0;
}

int mostrarPares(Lista_T lista)
{
    int aux;
    int i = 1;
    while (i < Longitud_Lista(lista))
    {
        aux = Devolver_Dato_Posicion(lista, i);
        if (aux % 2 == 0)
            printf("%d ", aux);
        i++;
    }
    return 0;
}