/*13) Escribir una función que tenga como argumento dos colas del
mismo tipo y devuelva True si las colas son
idénticas, False caso contrario. NO acceder a la estructura,
usar funciones del TAD.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// tad cola con punteros
#include "../TadCola/ColaP.h"

int llenarCola(Cola_T *cola);
void mostrar(Cola_T cola);
int identicas(Cola_T C1, Cola_T C2);

int main()
{
    Cola_T cola1, cola2;
    cola1 = CrearCola();
    cola2 = CrearCola();
    srand(time(NULL));

    llenarCola(&cola1);
    llenarCola(&cola2);

    mostrar(cola1);
    printf("\n");
    mostrar(cola2);
    printf("\n");

    (identicas(cola1, cola2) == 0) ? printf("es true") : printf("es false");


    return 0;
}

int llenarCola(Cola_T *cola)
{
    int n;
    while (LongitudCola(*cola) < 3)
    {
        n = rand() % 2;
        QPush(cola, n);
    }
    return 0;
}
void mostrar(Cola_T cola)
{
    while (!ColaVacia(cola))
        printf("%d ", QPop(&cola));
}

int identicas(Cola_T C1, Cola_T C2)
{
    if (LongitudCola(C1) == LongitudCola(C2))
    {
        while (!ColaVacia(C1))
        {
            if ((QPop(&C1) != QPop(&C2)))
                return 1;
            
        }
        return 0;
    }
    else
        return 1;
}