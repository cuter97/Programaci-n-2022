/*1) Reescribir el ejercicio 3) para descubrir si una frase es palíndroma.
Esta vez, utilizar pilas y colas de caracteres. NO acceder a la estructura,
usar funciones del/los TAD/s.*/
#include <stdio.h>
#include <stdlib.h>
// tad de pila y cola con arreglos
#include "../TadCola/ColaP.h"
#include "../TadPila/Pila.h"

int LlenarPilaOriginal(Pila_T *pila, Cola_T *cola);
int Palindromo(Pila_T pila, Cola_T cola);

int main()
{
    Pila_T pilita;
    Cola_T colita;
    pilita = Crear_Pila();
    colita = CrearCola();

    LlenarPilaOriginal(&pilita, &colita);

    if (Palindromo(pilita, colita))
        printf("es palindromo");
    else
        printf("no es palindromo");

    return 0;
}
int LlenarPilaOriginal(Pila_T *pila, Cola_T *cola)
{
    char aux;
    do
    {
        aux = getchar();
        if (aux != ' ' && aux != '\n')
        {
            QPush(cola, aux);
            S_Push(pila, aux);
        }
    } while (aux != '\n');

    return 0;
}
int Palindromo(Pila_T pila, Cola_T cola)
{
    while (!Pila_Vacia(pila) && !ColaVacia(cola))
        if (QPop(&cola) != S_Pop(&pila))
            return 0;
    return 1;
}