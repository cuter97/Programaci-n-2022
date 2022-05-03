#include <stdio.h>

struct NodoDE
{
    int dato;
    struct NodoDE *sig;
    struct NodoDE *ant;
};
typedef struct
{
    int n;
    struct NodoDE *primero;
    struct NodoDE *ultimo;
} ListaDE_T;

// crea una lista del tipo ListaDE_T con 0 elementos y la retorna
ListaDE_T CrearLista();

// inserta el nodo con el dato x como primer elemento de la lista
int InsertarPrimero(ListaDE_T *l, int x);

// inserta el nodo con el dato x como el ultimo elemento de la lista
int InsertarUltimo(ListaDE_T *l, int x);

// recorre la lista en orden imprimiendo sus elementos
int RecorrerListaEnOrden(ListaDE_T l);

// recorre la lista en orden inverso imprimiendo sus elementos
int RecorrerListaEnOrdenInverso(ListaDE_T l);

// retorna si la lista esta vacia
int ListaVacia(ListaDE_T l);

// Elimina el dato con posición \texttt{pos} de la lista (liberando memoria). Determinar la acción a realizar en caso que la posición no exista en la lista. */
int SuprimirDatoPosicion(ListaDE_T *l, int pos);

// desaloca la memoria de cada nodo. Longitud de la lista = 0.
int VaciarLista(ListaDE_T *l);

// Elimina el nodo con el dato x de la lista.
int SuprimirDato(ListaDE_T *l, int x);

// retorna la longitud de la lista
int LongitudLista(ListaDE_T l);

// devuelve el dato de la posición pos.
int DevolverDatoPosicion(ListaDE_T l, int pos);

// se inserta el dato x en la pos deseada.
int InsertarPosicion(ListaDE_T *l, int pos, int x);
