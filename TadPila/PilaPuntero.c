#include <stdio.h>
#include <stdlib.h>
#include "PilaPuntero.h"
typedef int TipoDato;

Pila_T CrearPila(){
  Pila_T stack;
  stack.dim = 0;
  stack.pila = NULL;
  return stack;
}

int SPush(Pila_T *stack, TipoDato x ){
  struct Nodo *nuevo;
  nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
  if(!nuevo){
    printf("no se aloco memoria\n");
    exit (-1);
  }
  nuevo->dato = x;
  nuevo->sig = stack->pila;
  stack->pila = nuevo;
  (stack->dim)++;

  return 0;
}

TipoDato SPop(Pila_T *stack){
  TipoDato dato;
  struct Nodo *aux;
  if (!PilaVacia(*stack)) {
    dato = stack->pila->dato;
    aux = stack->pila;
    stack->pila = aux->sig;
    free(aux);
    (stack->dim)--;
    return dato;
  }
  else{
    printf("se intenta sacar un elemento de una pila vacia\n");
    exit(-1);
  }
}

int PilaVacia(Pila_T stack){
  return(stack.dim == 0);
}

TipoDato STop(Pila_T stack){
  if (!PilaVacia(stack)) {
    return (stack.pila->dato);
  }
  else{
    printf("Error: pila vacia\n");
    exit(-1);
  }
}

int LongitudPila(Pila_T stack){
  return stack.dim;
}

int VaciarPila(Pila_T *stack){
  while(!PilaVacia(*stack)){
    SPop(stack);
  }
}
