#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
// no hace nada
// es un ejemplo
int BusquedaBin(int *lista, int clave)
{
    int central;
    int valorCentral;
    int bajo = 0;
    int alto = N - 1;
    while (bajo <= alto)
    {
        central = (bajo + alto) / 2;
        valorCentral = lista[central];
        if (clave == valorCentral)
            return central;
        else if (clave < valorCentral)
            alto = central - 1;
        else
            bajo = central + 1;
    }
    return 0;
}
