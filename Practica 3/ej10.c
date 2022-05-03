/*10) El TAD Lista Ordenada, es similar a la lista simple, pero cada elemento que se agrega 
a la lista se agrega de forma ordenada, según un criterio de orden. 
Este criterio puede ser un campo clave o cualquier otra comparación de sus elementos. 
Cada vez que se agrega un dato a la lista ordenada, se busca su posición correcta y se inserta. 
Es un post condición que luego de insertar un dato a una lista ordenada, la misma sigue 
siendo una lista ordenada. 
Implementar este TAD para elementos del tipo complejo donde se pide que queden ordenados por su
magnitud (magnitud de z = raiz(re(z)2 +im(z)2).
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "tadComplejo.h"

int main(){
  Complejo_T lista;
  lista = CrearListaComplejo();

  InsertarComplejo(&lista, 2, 4);
  InsertarComplejo(&lista, 6, 60);
  InsertarComplejo(&lista, 8, 23);
  InsertarComplejo(&lista, 8, 23);
  InsertarComplejo(&lista, 22, 9);
  InsertarComplejo(&lista, 11, 5);
  Imprimir(lista);
  return 0;
}

/*al compilar usa al final -lm asi forzamos a usar la libreria math.h
ya que no la lee cuando la agrego en el tad*/