#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Nodo
{
    int Re;
    int Im;
    struct Nodo *sig;
};
typedef struct
{
    int n;
    struct Nodo *listaComplejo;
} Complejo_T;

// crea una lista de complejos con 0 elementos
Complejo_T CrearListaComplejo();

// Cada vez que se agrega un dato a la lista ordenada, se busca su posición correcta y se inserta.
int InsertarComplejo(Complejo_T *lista, int re, int im);

// imprimimos la lista de complejos ya ordenados
int Imprimir(Complejo_T lista);

// Retorna 1 si la lista está vacia, 0 caso contrario
int ListaVacia(Complejo_T lista);

// retorna el modulo de un complejo
float Modulo(int re, int img);