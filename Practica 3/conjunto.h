/*trabajo practico ejercicio numero 9*/
#include <stdio.h>
struct Nodo
{
    int dato;
    struct Nodo *sig;
};

typedef struct
{
    int n;
    struct Nodo *conjunto;
} Conjunto_T;

// funcion que crea un conjunto y lo retorna
Conjunto_T CrearConjunto();

// retorna la cantidad de elemntos del conjunto
int Cardinal(Conjunto_T conjunto);

// funcion que retorna 1 si el elemento x pertenece al conjunto, 0 caso contrario
int Existe(Conjunto_T conjunto, int x);

// funcion que agrega un elemento x al conjunto
int InsertarElemento(Conjunto_T *conjunto, int x);

// imprime en pantalla los elementos del conjunto
int Imprimir(Conjunto_T conjunto);

// diferencia de dos conjuntos (x ∈ A−B cuando x ∈ A pero x ∈/ B)
/* la diferencia de dos conjuntos es una operación que da como resultado otro 
conjunto con los elementos del primer conjunto sin los elementos del segundo conjunto.*/
Conjunto_T Diferencia(Conjunto_T A, Conjunto_T B);

// Retorna 1 si el conjunto está vacio, 0 caso contrario
int ConjuntoVacio(Conjunto_T conj);