/***************************************************/
/*  Trabajo práctico 3 - Programación y Algoritmos */
/*  TAD lista de números enteros                   */
/***************************************************/
#include <stdio.h>
struct Nodo
{
    int dato;
    struct Nodo *sig;
};

typedef struct
{
    int n;
    struct Nodo *lista;
} Lista_T;

/* Crea una lista con 0 elementos */
Lista_T Crear_Lista();

/* inserta nodo con elemento x como primer elemento de la lista. Retorna 1 si la operación se realiza con éxito, -1 caso contrario.  */
int Insertar_Primero(Lista_T *l, int x);

/* inserta nodo con elemento x como último elemento de la lista. Retorna 1 si la operación se realiza con éxito, -1 caso contrario. */
int Insertar_Ultimo(Lista_T *l, int x);

/* Inserta dato x en posición pos. Determinar la acción a realizar si pos no existe en la lista*/
int Insertar_Dato_Posicion(Lista_T *l, int pos, int x);

/* Recorre la lista "l" imprimiendo sus elementos. Retorna 1 si la operación se realiza con éxito, -1 caso contrario (la lista no tiene elementos). */
int Recorrer_Lista(Lista_T l);

/*  Retorna TRUE (1) si la lista está vacía, FALSE (0) caso contrario. */
int Lista_Vacia(Lista_T l);

/* Vacia (desaloca memoria) para cada elemento de la lista. Longitud de la lista = 0. Retorna 1 si la operación se realiza con éxito, -1 caso contrario.  */
int Vaciar_Lista(Lista_T *l);

/* Elimina el dato x de la lista (liberando memoria). Determinar la acción a realizar en caso que el dato no exista en la lista. */
int Suprimir_Dato(Lista_T *l, int x);

/* Elimina el dato con posición \texttt{pos} de la lista (liberando memoria). Determinar la acción a realizar en caso que la posición no exista en la lista. */
int Suprimir_Dato_Posicion(Lista_T *l, int pos);

/* Retorna la longitud de la lista. */
int Longitud_Lista(Lista_T l);

/* Devuelve el dato de la posición \texttt{pos}. Determinar la acción a realizar en caso que la posición no exista en la lista.*/
int Devolver_Dato_Posicion(Lista_T l, int pos);
