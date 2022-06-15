/*16.13. Dado un árbol binario de búsqueda diseñe un
procedimiento que liste los nodos del árbol
ordenados descendentemente.*/

#include <stdio.h>
#include <stdlib.h>
#include "../TadArbol/ABB.h"
typedef int Tipo_Dato;
int INordenDescendente(Arbol_T a);
int main()
{

	Arbol_T a = NULL;
	InsertarElemento(&a, 7);
	InsertarElemento(&a, 4);
	InsertarElemento(&a, 2);
	InsertarElemento(&a, 5);
	InsertarElemento(&a, 9);
	InsertarElemento(&a, 8);
	INordenDescendente(a);

	return 0;
}
int INordenDescendente(Arbol_T a)
{
	if (a != NULL)
	{
		INordenDescendente(a->der);
		printf("%d ", a->dato);
		INordenDescendente(a->izq);
	}
	return 0;
}
