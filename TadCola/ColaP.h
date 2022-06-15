#include <stdio.h>
#include <stdlib.h>
typedef int Tipo_Dato;

struct NodoC
{
    Tipo_Dato dato;
    struct NodoC *sig;
};
typedef struct
{
    struct NodoC *frente;
    struct NodoC *final;
    int size;
} Cola_T;

Cola_T CrearCola();
/* crea la cola pasada como parámetro: con 0 elementos y asignando el valor correcto al resto de los
campos (frente = final = NULL).*/
int QPush(Cola_T *cola, Tipo_Dato x);
// Añade x a la cola.
Tipo_Dato QPop(Cola_T *cola);
// Saca un elemento de la cola si la cola no está vacía. La función retorna dicho dato.
int ColaVacia(Cola_T cola);
// retorna True si la cola está vacía. False caso contrario.
Tipo_Dato QTop(Cola_T cola);
// Retorna el dato que está en el tope de la cola, pero sin sacarlo (no modifica la cola)
int LongitudCola(Cola_T cola);
// Retorna la longitud de la cola.
int VaciarCola(Cola_T *cola);
// Vacia la cola pasada como parámetro.
