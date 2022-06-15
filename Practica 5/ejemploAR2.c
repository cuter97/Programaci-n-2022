/*16.9. Dados dos árboles binarios de búsqueda indicar mediante un programa si los árboles
tienen o no elementos comunes.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../TadArbol/ABB.h"

typedef int Tipo_Dato;
//defino un tamano chico a fin de poder probar el algoritmo
#define N 4

int Llenararbol(Arbol_T *a);
int comun(Arbol_T a, Arbol_T b);

int main()
{
	Arbol_T b = NULL;
	Arbol_T a = NULL;

	srand(time(NULL));
	
	Llenararbol(&a);
	Llenararbol(&b);

	InOrder(a);
	printf("\n");

	InOrder(b);
	printf("\n");

	(comun(a, b) == 1) ? printf("tienen elementos en comun") : printf("no tiene");

	return 0;
}

int Llenararbol(Arbol_T *a)
{
	int aux;
	for (int i = 0; i < N; ++i)
	{
		aux = rand() % 9 + 1;
		InsertarElemento(a, aux);
	}
	return 0;
}

//caso muy similar a la funcion Existe()
int comun(Arbol_T a, Arbol_T b)
{
	if (a == NULL)
		return 0;
	else
	{
		if (Existe(b, a->dato)) // es lo mismo que poner (Existe(b, a->dato) == 1)
			return 1;
		else
		{ 
			if (a->izq != NULL)
				return comun(a->izq, b);
			if (a->der != NULL)
				return comun(a->der, b);
		}
	}
}