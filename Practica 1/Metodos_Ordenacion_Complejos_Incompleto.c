/*******************************************************/
/* UNRN Programacion y Algoritmos 2022                 */
/* Ordenacion de un vector de numeros complejos        */
/* usando el modulo como criterio de                   */
/* orden. Búsquedas.                                   */
/*******************************************************/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>

// Compilacion: -lm para incluir math.h y la opcion -D si se quiere inicializar N
//  gcc Metodos_Ordenacion_Incompleto.c -DN=8989 -o ordenacion -lm

/*estas lineas permiten compilar con la opcion -DN=XX para inicializar N con el valor XX*/
#ifndef N
#define N 2 << 10
#endif

#define IMPRIMIR (N < 20)

/*******************************************************/
/*  DECLARACION DE TIPOS                               */
/*******************************************************/

typedef struct
{
	int real, imag;
} Complejo_T;

/*******************************************************/
/*  PROTOTIPO DE FUNCIONES                             */
/*******************************************************/

/*Inicializa parte real e imaginaria con valores random */
int inicializar_datos(Complejo_T vec[N], int size);

/* imprime parte real e imaginaria de cada complejo del arreglo */
int imprimir_arreglo(Complejo_T vec[N], int size);

/* retorna 1 (verdadero) si modulo(a) < modulo(b). Retorna 0 (falso) caso contrario*/
/* moduloA = sqrt(pow(a.real,2) + pow(a.imag,2)); usando math.h y compilando con -lm*/
int esMenor(Complejo_T a, Complejo_T b);

/* intercambia los valores de x y de y*/
int swap(Complejo_T *x, Complejo_T *y);

/* ordena los valores de vector de menor módulo a mayor módulo */
int orden_Burbuja(Complejo_T vector[N], int size);

/* metodo inserción */
int orden_insercion(Complejo_T vector[N], int size);

/*metodo seleccion*/
int orden_seleccion(Complejo_T vector[N], int size);

/*metodo shellsort*/
int orden_shellsort(Complejo_T vector[N], int size);

/*metodo quicksort*/
void orden_quicksort(Complejo_T vector[N], int primero, int ultimo);

/* busqueda secuencial */
int busqueda_secuencial(Complejo_T vector[N], Complejo_T x, int size);

/* funcion que retorna 1 si los complejos son iguales y 0 caso contrario*/
int iguales(Complejo_T a, Complejo_T b);

/*busqueda binaria*/
int busqueda_binaria(Complejo_T vector[N], Complejo_T x, int size);

/*funcion que calcula el modulo de un complejo y lo retorna*/
float modulo_calc(Complejo_T n);

/*******************************************************/
/*  FUNCION MAIN                                       */
/*******************************************************/
int main()
{
	Complejo_T vec1[N], i;
	srand(time(NULL));

	// incializacion de datos del vector
	inicializar_datos(vec1, N);
	// si el arreglo es pequenio se imprimen sus valores
	if (IMPRIMIR){
		printf("arreglo original\n");
		imprimir_arreglo(vec1, N);
	}

	printf("\n");
	printf("\n");

	struct timeval begin, end;
	// empezamos a medir el tiempo que tarda cada algoritmo de busqueda
	gettimeofday(&begin, 0);

	// orden_Burbuja(vec1, N);
	// orden_insercion(vec1, N);
	// orden_seleccion(vec1, N);
	orden_shellsort(vec1, N);

	// int primero = 0;
	// int ultimo = N - 1;
	// orden_quicksort(vec1, primero, ultimo); 

	gettimeofday(&end, 0);

	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	double tiempo = seconds + microseconds * 1e-6;

	if (IMPRIMIR){
		printf("metodo de ordenamiento\n");
		imprimir_arreglo(vec1, N);
	}
	printf("\n");
	printf("Tiempo medido: %.8f seconds.\n", tiempo);

	printf("\n");
	printf("\n");

	printf("ingrese parte real del numero complejo a buscar: ");
	scanf("%d", &i.real);
	printf("ingrese parte imaginaria del numero complejo a buscar: ");
	scanf("%d", &i.imag);

	if (busqueda_secuencial(vec1, i, N) == 1)
		printf("el complejo ingresado existe");
	else
		printf("No existe ");
	// if (busqueda_binaria(vec1, i, N) != 0)
	// 	printf("el complejo ingresado existe");
	// else
	// 	printf("No existe ");

	return 0;
}

/*******************************************************/
/*  IMPLEMENTACION DE FUNCIONES                        */
/*******************************************************/

/*Inicializa parte real e imaginaria con valores random */
int inicializar_datos(Complejo_T vec[N], int size)
{
	for (int i = 0; i < size; i++)
	{
		vec[i].real = rand() % 10;
		vec[i].imag = rand() % 10;
	}
	return 0;
}

/* imprime parte real e imaginaria de cada complejo del arreglo */
int imprimir_arreglo(Complejo_T vec[N], int size)
{
	for (int i = 0; i < size; i++)
		printf("(%d, %di)", vec[i].real, vec[i].imag);
	return 0;
}

/* funcion que compara a y b. Retorna verdadero (1) si el modulo(a) < modulo(b)*/
int esMenor(Complejo_T a, Complejo_T b)
{
	// llamamos a la funcion que calcula el modulo
	return ((modulo_calc(a) < modulo_calc(b)) ? 1 : 0);
}

/*funcion que calcula el modulo de un complejo y lo retorna*/
float modulo_calc(Complejo_T n)
{
	return ((float)sqrt(pow(n.real, 2) + pow(n.imag, 2)));
}

/* intercambia los valores de x y de y*/
int swap(Complejo_T *x, Complejo_T *y)
{
	Complejo_T aux;
	aux = *x;
	*x = *y;
	*y = aux;
	
	return 0;
}

/* ordena los valores de vector de menor módulo a mayor módulo  (metodo bubble sort) */
int orden_Burbuja(Complejo_T vector[N], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (modulo_calc(vector[j]) < modulo_calc(vector[i]))
				swap(&vector[i], &vector[j]);	
		}
	}
	return 0;
}

/* metodo de ordenacion por inserción */
int orden_insercion(Complejo_T vector[N], int size)
{
	for (int i = 0; i < size; i++)
	{
		Complejo_T aux = vector[i];

		int j = i - 1;
		while ((j >= 0) && (modulo_calc(vector[j]) > modulo_calc(aux)))
		{
			vector[j + 1] = vector[j];
			j--;
		}
		vector[j + 1] = aux;
	}
	return 0;
}

/* metodo de ordenacion por seleccion */
int orden_seleccion(Complejo_T vector[N], int size)
{
	int limite = size - 1;
	for (int i = 0; i < limite; i++)
	{
		int p = i;
		for (int j = i + 1; j <= limite; j++)
		{
			if (modulo_calc(vector[j]) < modulo_calc(vector[p]))
				p = j;
		}
		if (p != i)
			swap(&vector[p], &vector[i]);
	}
	return 0;
}

/*metodo shellsort*/
int orden_shellsort(Complejo_T vector[N], int size)
{
	int incr = size;
	do
	{
		for (int i = incr; i < size; i++)
		{
			for (int j = i; (j >= incr) && (modulo_calc(vector[j - incr]) > modulo_calc(vector[j])); j -= incr)
			{
				swap(&vector[j], &vector[j - incr]);
			}
		}
		incr = incr / 2;
	} while (incr > 0);

	return 0;
}

/*metodo quicksort*/
void orden_quicksort(Complejo_T vector[N], int primero, int ultimo)
{
	int central;
	Complejo_T pivote;
	central = (primero + ultimo) / 2;
	pivote = vector[central];
	int i = primero;
	int j = ultimo;
	do
	{
		while (modulo_calc(vector[i]) < modulo_calc(pivote))
			i++;
		while (modulo_calc(vector[j]) > modulo_calc(pivote))
			j--;
		if (i <= j)
		{
			swap(&vector[i], &vector[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (primero < j)
		orden_quicksort(vector, primero, j); /* llamada recursiva con sublista izquierda */

	if (i < ultimo)
		orden_quicksort(vector, i, ultimo); /* llamada recursiva con sublista izquierda */
}

/* busqueda secuencial */
int busqueda_secuencial(Complejo_T vector[N], Complejo_T x, int size)
{
	int i = 0;
	int resultado = 0;
	do
	{
		if (iguales(vector[i], x) == 1)
			resultado = 1;
		else
			i++;

	}while (!resultado && (i < size));

	return resultado;
}

/* funcion que retorna 1 si los complejos son iguales y 0 caso contrario*/
int iguales(Complejo_T a, Complejo_T b)
{
	return ((a.real == b.real && a.imag == b.imag) ? 1 : 0);
}

/*busqueda binaria*/
int busqueda_binaria(Complejo_T vector[N], Complejo_T x, int size)
{
	Complejo_T valorCentral;
	int central;
	int bajo = 0;
	int alto = size - 1;
	while (bajo <= alto)
	{
		central = (bajo + alto) / 2;
		valorCentral = vector[central];

		if(iguales(x, valorCentral) == 1)
			return 1;
		else if(esMenor(x, valorCentral) == 1)
			alto = central - 1;
		else
			bajo = central + 1;
	}
	return 0;
}