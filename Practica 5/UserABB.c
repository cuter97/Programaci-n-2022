#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UserABB.h"

User_T CrearArbol(char *usuario, int clave, int identificador)
{
    User_T a;
    a = (User_T)malloc(sizeof(struct Nodo));
    a->izq = NULL;
    a->der = NULL;
    a->user = usuario;
    a->claveNum = clave;
    a->id = identificador;
    return (a);
}

void InsertarUser(User_T *a, char *usuario ,int clave, int identificador)
{
    if ((*a) == NULL)
        *a = CrearArbol(usuario, clave, identificador);
    else if (clave < (*a)->claveNum)
        InsertarUser(&((*a)->izq), usuario, clave, identificador);
    else
        InsertarUser(&((*a)->der), usuario, clave, identificador);
}

int Existe(User_T a, int x)
{
    if (a == NULL)
        return 0;
    else if (a->claveNum == x)
        return 1;
    else if (x < a->id)
        return Existe(a->izq, x);
    else
        return Existe(a->der, x);
}

void InOrder(User_T a)
{ /*I V D*/
    if (a != NULL)
    {
        if (a->izq != NULL)
            InOrder(a->izq);

        for (int i = 0; i < strlen(a->user); i++)
            printf("%c",a->user[i]); 
        
        printf(" %d ,id: %d \n", a->claveNum, a->id);

        if (a->der != NULL)
            InOrder(a->der);
    }
}
int buscar(User_T a, int clave, char *usuario){

    if (Existe(a, clave) == 1 && usuario == a->user){
        // if (usuario == a->user)
        // {
            printf("bienvenido");
            for (int i = 0; i < strlen(a->user); i++)
                printf("%c",a->user[i]); 
        // }
        // else
        //     printf("usuario o contrasena incorrecto");
        
    }
    else
        printf("el usuarion no existe");
    return 0;  
}


