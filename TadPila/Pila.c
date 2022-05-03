#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

Pila_T Crear_Pila(){
  Pila_T pila;
  pila.indice = -1;
  pila.max = TamMax;
  return pila;
}

int S_Push(Pila_T *pila, TipoDato x ){
  if (!Pila_Llena(*pila)) {
    pila->indice = pila->indice + 1;
    pila->pila[pila->indice] = x;
  }
  else
    printf("Error: pila llena\n");
  return 0;
}

TipoDato S_Pop(Pila_T *pila){
  if (!Pila_Vacia(*pila)) {
    TipoDato dato;
    dato = pila->pila[pila->indice];
    pila->indice = pila->indice - 1;
    return dato;
  }
  else{
    printf("Error pop: pila vacia\n");
    exit (-1);
  }
}

int Pila_Llena(Pila_T pila){
  return (pila.indice == pila.max - 1);
}

int Pila_Vacia(Pila_T pila){
  return (pila.indice == -1);
}

TipoDato S_Top(Pila_T pila){
  if (!Pila_Vacia(pila)) {
    return pila.pila[pila.indice];
  }
  else
  printf("Error: pila vacia\n");
  exit(-1);
}

int Longitud_Pila(Pila_T pila){
  return pila.indice;
}

int Vaciar_Pila(Pila_T *pila){
    pila->indice == -1;
    return 0;
}
