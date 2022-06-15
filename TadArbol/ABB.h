#include <stdio.h>
#include <stdlib.h>
typedef int Tipo_Dato;
struct Nodo
{
    struct Nodo *izq;
    Tipo_Dato dato;
    struct Nodo *der;
};
typedef struct Nodo *Arbol_T;

/*Prototipos*/

Arbol_T CrearArbol(int x);
int InsertarElemento(Arbol_T *a, int x);
void InOrder(Arbol_T a);   /*I V D*/
void PostOrder(Arbol_T a); /*I D V*/
void PreOrder(Arbol_T a);  /*V I D*/
void EliminarElemento(Arbol_T *a, int x);
int Existe(Arbol_T a, int x);
int ContarNodos(Arbol_T a);           /*Problema 11*/
int Profundidad(Arbol_T a);           /*Problema 12*/
void ImprimirPares(Arbol_T a);        /*Problema 13*/
int Minimo(Arbol_T a);                /*Problema 14*/
int Maximo(Arbol_T a);                /*Problema 15*/
void ImprimirNivel(Arbol_T a, int x); /*Problema 19*/
int ObtenerMaximo(int a, int b);      /*funcion auxiliar*/
