/*9) Un conjunto es una colección de elementos del mismo tipo sin duplicados. 
Escribir un programa para representar un conjunto de enteros mediante una lista enlazada. 
El programa debe contemplar las operaciones:
- Crear un conjunto.
- Cardinal del conjunto. (cantidad de elementos)
- Pertenencia de un elemento al conjunto. (si x pertenece al conjunto A, por ejemplo)
- Añadir un elemento al conjunto. (un conjunto no tiene valores repetidos)
- Escribir en pantalla los elementos del conjunto.
- Diferencia de dos conjuntos (x ∈ A−B cuando x ∈ A pero x ∈/ B).

dato: no es necesario que el conjunto este ordenado*/

#include <stdio.h>
#include "conjunto.h"

int main()
{
    Conjunto_T A;
    A = CrearConjunto();
    Conjunto_T B;
    B = CrearConjunto();

    InsertarElemento(&A, 1);
    InsertarElemento(&A, 2);
    InsertarElemento(&A, 3);
    InsertarElemento(&A, 4);
    InsertarElemento(&A, 5);

    InsertarElemento(&B, 2);
    InsertarElemento(&B, 4);
    InsertarElemento(&B, 6);
    InsertarElemento(&B, 8);
    InsertarElemento(&B, 10);


    // InsertarElemento(&elementos, 4);
    // InsertarElemento(&elementos, 3);
    // InsertarElemento(&elementos, 6);
    // InsertarElemento(&elementos, 7);
    // InsertarElemento(&elementos, 4); //no se agrerga
    // InsertarElemento(&elementos, 8);
    // InsertarElemento(&elementos, 9);
    // InsertarElemento(&elementos, 10);
    // InsertarElemento(&elementos, 6); //no se agrega
    Imprimir(A);
    printf("\n");
    Imprimir(B);
    printf("\n");

    Conjunto_T C = Diferencia(A, B);
    Imprimir(C);
    printf("\n");

    return 0;
}