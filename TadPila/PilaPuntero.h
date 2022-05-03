#include <stdio.h>
typedef int TipoDato;

struct Nodo{
  TipoDato dato;
  struct Nodo *sig;
};
typedef struct{
  int dim;// cantidad de datos de la pila
  struct Nodo *pila; // puntero a la pila
}Pila_T;

// Crea una pila vacía
Pila_T CrearPila();

// Añade x a la pila, si la misma no está llena. Si está llena determinar el valor retornado.
int SPush(Pila_T *stack, TipoDato x );

// Saca un elemento de la pila si la pila no está vacía. La función retorna dicho dato. Determinar valor
//Determinar valor retornado si la pila está vacía.
TipoDato SPop(Pila_T *stack);

// retorna True si la pila está vacía. False caso contrario.
int PilaVacia(Pila_T stack);

// Retorna el dato que está en el tope de la pila, pero sin sacarlo (no modifica la pila)
TipoDato STop(Pila_T stack);

// Retorna la longitud de la pila.
int LongitudPila(Pila_T stack);

// Vacia la pila pasada como parámetro.
int VaciarPila(Pila_T *stack);
