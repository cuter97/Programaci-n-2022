#include <stdio.h>
#include <stdlib.h>
#include "ColaP.h"

int imprimir(Cola_T cola)
{
    while (!ColaVacia(cola))
        printf("%d ", QPop(&cola));

    printf("\n");
    return 0;
    
}

int main()
{
    Cola_T cola;
    cola = CrearCola();

    QPush(&cola, 1);
    QPush(&cola, 4);
    QPush(&cola, 3);
    QPush(&cola, 2);
    QPush(&cola, 2);
    QPush(&cola, 2);
    QPush(&cola, 2);
    QPush(&cola, 2);
    QPush(&cola, 2);

    imprimir(cola);
    return 0;
}