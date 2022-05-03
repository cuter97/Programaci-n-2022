#include <stdio.h>
#include <stdlib.h>
typedef int TipoDato;
#define TamMax 5

typedef struct{
  int indice;
  TipoDato pila[TamMax];
  int max;
}Pila_T;

// Crea una pila vacía
Pila_T Crear_Pila();

// Añade x a la pila, si la misma no está llena. Si está llena determinar el valor retornado.
int S_Push(Pila_T *pila, TipoDato x );

// Saca un elemento de la pila si la pila no está vacía. La función retorna dicho dato. Determinar valor
//Determinar valor retornado si la pila está vacía.
TipoDato S_Pop(Pila_T *pila);

// Retorna True si la pila está llena. False caso contrario.
int Pila_Llena(Pila_T pila);

// retorna True si la pila está vacía. False caso contrario.
int Pila_Vacia(Pila_T pila);

// Retorna el dato que está en el tope de la pila, pero sin sacarlo (no modifica la pila)
TipoDato S_Top(Pila_T pila);

// Retorna la longitud de la pila.
int Longitud_Pila(Pila_T pila);

// Vacia la pila pasada como parámetro.
int Vaciar_Pila(Pila_T *pila);
