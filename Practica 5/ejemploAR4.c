/*Escribir una función booleana IDENTICOS que permita decir
si dos árboles binarios son iguales.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../TadArbol/ABB.h"
typedef int Tipo_Dato;

int iguales(Arbol_T a, Arbol_T b);

int main()
{
	Arbol_T a;
	Arbol_T b;

	a = CrearArbol(5);
	b = CrearArbol(5);

	InsertarElemento(&a, 0);
	InsertarElemento(&a, 1);
	InsertarElemento(&a, 2);
	InsertarElemento(&a, 3);
	InsertarElemento(&a, 4);
	InsertarElemento(&a, 9);
	InsertarElemento(&a, 11);
	InsertarElemento(&a, 6);

	InsertarElemento(&b, 1);
	InsertarElemento(&b, 2);
	InsertarElemento(&b, 3);
	InsertarElemento(&b, 4);
	InsertarElemento(&b, 9);
	InsertarElemento(&b, 12);
	InsertarElemento(&b, 6);

    printf("la profundidad es: %d \n", Profundidad(a));

	InOrder(a);
	printf("\n");
	InOrder(b);
	printf("\n");

	(iguales(a, b) == 0) ? printf("son iguales\n") : printf("no son iguales\n");

	return 0;
}

//retorna 0 si los arboles son iguales 1 caso contrario
int iguales(Arbol_T a, Arbol_T b)
{
	if (a == NULL && b == NULL)
		return 0;
	else
	{
		if (a == NULL || b == NULL)
			return 1;
		else
		{
			if (a->dato == b->dato)
			{
				iguales(a->izq, b->izq);
				iguales(a->der, b->der);
			}
			else
				return 1;
		}
	}
}