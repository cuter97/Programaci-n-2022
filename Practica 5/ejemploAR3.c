/*Dado un árbol binario de búsqueda construir su árbol espejo. (Arbol espejo es el
que se construye a partir de uno dado, convirtiendo el subárbol izquierdo en subárbol
derecho y viceversa.)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../TadArbol/ABB.h"
typedef int Tipo_Dato;
#define N 5

int llenarArbol(Arbol_T *a);
int Insertar(Arbol_T *a, Tipo_Dato x);
int espejo(Arbol_T a, Arbol_T *b);
int main()
{
	int x;
	// Arbol_T a = NULL;
	Arbol_T a ;
	Arbol_T b = NULL;
	a = CrearArbol(5);
	// llenarArbol(&a);
	InsertarElemento(&a, 1);
    InsertarElemento(&a, 4);
    InsertarElemento(&a, 6);
    InsertarElemento(&a, 7);
    InsertarElemento(&a, 9);
	espejo(a, &b);
	
	InOrder(a);
	printf("\n");

	InOrder(b);
	printf("\n");

	// la funcion eliminar buscaria el dato por izquierda pero como es el espejo ahora el cuatro
	// esta en la derecha por lo que saldria el mensaje de el dato no se encuentra. Asi podemos ver
	// que el ejercicio esta bien hecho
	EliminarElemento(&b, 4);
    InOrder(b);
    printf("\n");
	return 0;
}

int llenarArbol(Arbol_T *a)
{
	int aux;
	for (int i = 0; i < N; ++i)
	{
		aux = rand() % 10;
		InsertarElemento(a, aux);
	}
	return 0;
}

int Insertar(Arbol_T *a, Tipo_Dato x)
{
	if ((*a) == NULL)
		*a = CrearArbol(x);
	else if (x < (*a)->dato)
		Insertar(&((*a)->der), x);
	else
		Insertar(&((*a)->izq), x);
}

int espejo(Arbol_T a, Arbol_T *b)
{
	if (a != NULL)
	{
		Insertar(b, a->dato);
		espejo(a->izq, b);
		espejo(a->der, b);
	}
	return 0;
}