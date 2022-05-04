/*3) Usando una pila de caracteres, indicar si una palabra es un palíndromo
(que se lee igual en ambos sentidos).
Ayuda: leer la palabra caracter a caracter, armando a la vez un string y una pila.
Luego, utilizar la pila y el string para comparar los caracteres.
Puede utilizar la función getchar() para leer los caracteres hasta el fin de línea.*/

//uso pila con punteros
#include <stdio.h>
#include "../TadPila/PilaPuntero.h"
typedef char TipoDato;

int LlenarPilaOriginal(Pila_T *pila);
Pila_T LlenarPilaInversa(Pila_T pila);
int Palindromo(Pila_T p1, Pila_T p2);

int main()
{
    Pila_T pilaOr, pilaIn;
    pilaOr = CrearPila();

    LlenarPilaOriginal(&pilaOr);

    pilaIn = LlenarPilaInversa(pilaOr);

    (Palindromo(pilaOr, pilaIn)) ? printf(" es Palindromo\n") : printf("no es Palindromo\n");

    return 0;
}

int LlenarPilaOriginal(Pila_T *pila)
{
    do
    {
        SPush(pila, getchar());

        if (STop(*pila) == ' ') // no ingresa los espacios
            SPop(pila);

    } while (STop(*pila) != '\n');

    SPop(pila);

    return 0;
}

Pila_T LlenarPilaInversa(Pila_T pila)
{
    Pila_T aux;
    aux = CrearPila();

    while (!PilaVacia(pila))
        SPush(&aux, SPop(&pila));

    return aux;
}

int Palindromo(Pila_T p1, Pila_T p2)
{
    while (!PilaVacia(p1)){
        return ( (SPop(&p1) != SPop(&p2)) ? 0 : 1);
    }
}