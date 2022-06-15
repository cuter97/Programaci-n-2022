#include <stdio.h>
#define TamMax 5
typedef char Tipo_Dato;
typedef struct
{
    int frente;
    int final;
    Tipo_Dato cola[TamMax];
} Cola_T;

Cola_T Crear_Cola();

int Q_Push(Cola_T *cola, Tipo_Dato x);

Tipo_Dato Q_Pop(Cola_T *cola);

int Cola_Llena(Cola_T cola);

int Cola_Vacia(Cola_T cola);

Tipo_Dato Q_Top(Cola_T cola);

int Longitud_Cola(Cola_T cola);

int Vaciar_Cola(Cola_T *cola);
