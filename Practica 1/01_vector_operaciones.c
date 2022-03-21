#include <stdio.h>
#include <stdlib.h>
#define MAX 100


/**************************************************************/
/*       PROTOTIPO DE FUNCIONES                               */
/**************************************************************/
// inicializa los primeros dim elementos del vector v con valor 0 (dim = dimension logica)
int vector_inicializar_ceros(int v[MAX], int dim);

// inicializa los primeros dim elementos del vector v con valores aleatorios entre 0 y 99
int vector_inicializar_rnd(int v[MAX], int dim);

// imprime los valores del vector v, hasta la dimension logica dim
int vector_imprimir(int v[MAX], int dim);

// suma inplace de vectores: vA = vA + vB. Dimension dimaA y dimB deben ser iguales 
int vector_suma(int vA[MAX], int dimA, int vB[MAX], int dimB);

// resta inplace de vectores: vA = vA - vB. Dimension dimaA y dimB deben ser iguales 
int vector_resta(int vA[MAX], int dimA, int vB[MAX], int dimB);

// producto punto de vectores (o producto escalar de vectores). Las dimensiones de los vectores debe coincidir
int vector_producto_punto(int vA[MAX], int dimA, int vB[MAX], int dimB);

// retorna VERDADERO si todos los valores de vA son iguales a los valores de vB. 
// retorna FALSO caso contrario. Las dimensiones de los vectores deben ser iguales
int vector_son_iguales(int vA[MAX], int dimA, int vB[MAX], int dimB);

// imprime los valores del vector v que estan en posicion par, desde 0 hasta dim-1
int vector_imprimir_posicion_pares(int v[MAX], int dim);

// imprime los valores del vector v que estan en posicion impar, desde 0 hasta dim-1
int vector_imprimir_posicion_impares(int v[MAX], int dim);

// suma los valores del vector v, hasta dim
int vector_sumar_elementos(int v[MAX], int dim);

// retorna VERDADERO si existe el valor "elemento" en el vector v (dimensión lógica dim). 
// retorna FALSO caso contrario. 
int vector_buscar_elemento(int v[MAX], int dim, int elemento);




int main()
{
  int dim;
  int vector[MAX];

  printf("Ingrese la dimension del vector \n");
  scanf("%d", &dim);

  // si la dimension es correcta, se inicializa y trabaja con el vector
  if (dim > MAX) {

      printf("La dimension logica debe ser menor a la fisica \n");
      exit (-1);
  }
  else {

      vector_inicializar_rnd(vector, dim);
      // ...completar
      printf("\nTamano vector: %lu tamano int: %lu \n", sizeof(vector), sizeof(int));
   }
  
   return(0);
}


/**************************************************************/
/*       IMPLEMENTACION DE FUNCIONES                          */
/**************************************************************/

// inicializa los primeros dim elementos del vector v con valor 0 (dim = dimension logica)
int vector_inicializar_ceros(int v[MAX], int dim){

  //completar

  return 0;
}


// inicializa los primeros dim elementos del vector v con valores aleatorios entre 0 y 99
int vector_inicializar_rnd(int v[MAX], int dim){

  //completar

  return 0;
}


// imprime los valores del vector v, hasta la dimension logica dim
int vector_imprimir(int v[MAX], int dim){

  //completar

  return 0;
}


// suma inplace de vectores: vA = vA + vB. Dimension dimaA y dimB deben ser iguales 
int vector_suma(int vA[MAX], int dimA, int vB[MAX], int dimB){

  //completar

  return 0;
}

// resta inplace de vectores: vA = vA - vB. Dimension dimaA y dimB deben ser iguales 
int vector_resta(int vA[MAX], int dimA, int vB[MAX], int dimB){

  //completar

  return 0;
}

// producto punto de vectores (o producto escalar de vectores). Las dimensiones de los vectores debe coincidir
int vector_producto_punto(int vA[MAX], int dimA, int vB[MAX], int dimB){

  //completar
  //return <valor calculado>;
}


// retorna VERDADERO si todos los valores de vA son iguales a los valores de vB. 
// retorna FALSO caso contrario. Las dimensiones de los vectores deben ser iguales
int vector_son_iguales(int vA[MAX], int dimA, int vB[MAX], int dimB){

  //completar

  //return <resultado>;
}


// imprime los valores del vector v que estan en posicion par, desde 0 hasta dim-1
int vector_imprimir_posicion_pares(int v[MAX], int dim){

  //completar
  return 0;
}

// imprime los valores del vector v que estan en posicion impar, desde 0 hasta dim-1
int vector_imprimir_posicion_impares(int v[MAX],int dim){

  //completar
  return 0;
}

// suma los valores del vector v, hasta dim
int vector_sumar_elementos(int v[MAX], int dim){

  //completar
  //return <suma calculada>;
}


// retorna VERDADERO si existe el valor "elemento" en el vector v (dimensión lógica dim). 
// retorna FALSO caso contrario. 
int vector_buscar_elemento(int v[MAX], int dim, int elemento){

  //completar
  //return <resultado>;
}
