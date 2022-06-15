#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo
{
    struct Nodo *izq;
    struct Nodo *der;
    int claveNum;
    char *user;
    int id;
};
typedef struct Nodo *User_T;

/*Prototipos*/

User_T CrearArbol(char *usuario, int clave, int identificador);
void InsertarUser(User_T *a, char *usuario, int clave, int identificador);
// void EliminarElemento(User_T *a, int identificador);
int Existe(User_T a, int identificador);
void InOrder(User_T a);
int buscar(User_T a, int clave, char *usuario);
