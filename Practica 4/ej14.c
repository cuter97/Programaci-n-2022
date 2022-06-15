/*14) Encontrar un número capicúa leído del dispositivo estándar de
entrada (usando pilas o colas o ambas). NO
acceder a la estructura, usar funciones del TAD.*/

//pila con punteros
#include "../TadPila/PilaPuntero.h"

int LlenarPilaOriginal(Pila_T *pila1, Pila_T *pila2);
int capicua(Pila_T pila1, Pila_T pila2);

void mostrarpila(Pila_T pila)
{
    while (!PilaVacia(pila))
        printf("%d ", SPop(&pila));
}

int main()
{
    Pila_T pila1;
    Pila_T pila2;
    pila1 = CrearPila();
    pila2 = CrearPila();

    LlenarPilaOriginal(&pila1, &pila2);

    mostrarpila(pila1);
    printf("\n");
    mostrarpila(pila2);
    printf("\n");

    (capicua(pila1, pila2) == 0) ? printf("es capicua") : printf("no es capicua");

    return 0;
}
int LlenarPilaOriginal(Pila_T *pila1, Pila_T *pila2)
{
    int aux;
    Pila_T Paux;
    Paux = CrearPila();

    do
    {
        scanf("%d", &aux);
        SPush(&Paux, aux);
        SPush(pila1, aux);
        
    } while (aux != -1);
    SPop(&Paux);
    SPop(pila1);

    while (!PilaVacia(Paux))
        SPush(pila2, SPop(&Paux));

    return 0;
}
int capicua(Pila_T pila1, Pila_T pila2 )
{
    while (!PilaVacia(pila1))
    {
        if (SPop(&pila1) != SPop(&pila2))
            return 1;
    }
    return 0;
}