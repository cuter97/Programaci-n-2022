#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "UserABB.h"

int idRandom();
int main ()
{
    srand(time(NULL));
    User_T a = NULL;

    int user1 = idRandom();
    int user2 = idRandom();
    int user3 = idRandom();
    int user4 = idRandom();

    InsertarUser(&a, "pepe", 1234, user1);
    InsertarUser(&a, "cuter", 4567, user2);
    InsertarUser(&a, "juan", 2342, user3);
    InsertarUser(&a, "carlos", 2342, user4);
    InOrder(a);

    char *user;
    int clave;
    printf("ingrese usuario \n");
    scanf("%c\n", &user);
    printf("ingrese contraseña \n");
    scanf("%d\n", &clave);
    buscar(a, clave, user);

    return 0;
}

int idRandom(){
    return rand()%100;
}
