/*7) El tipo de dato pila se puede utilizar para determinar si una expresión está “balanceada”.
Por ejemplo, tomando una expresión algebraica como: 7+[5 ∗ (3+8)]/(7+9) se puede determinar
que la expresión está balanceada:
cada símbolo de apertura “{”, “[” o “(” tiene su símbolo de cierre “}”, “]” o “)”.
Escribir un programa que dada una secuencia de caracteres, determine si la secuencia está balanceada o no.
Puede utiizar la función getchar() para leer los caracteres hasta el fin de linea.*/

// uso pila con punteros
#include <stdio.h>
#include <stdlib.h>
#include "../TadPila/PilaPuntero.h"

int LlenarPila(Pila_T *pila);
int Balanceada(Pila_T pila);

int main()
{
    Pila_T simbolos;
    simbolos = CrearPila();

    //  7+[5 ∗ (3+8)]/(7+9)
    // LlenarPila(&simbolos);
    SPush(&simbolos, '7');
    SPush(&simbolos, '+');
    SPush(&simbolos, '['); //no esta balanceada por este caracter
    SPush(&simbolos, '[');
    SPush(&simbolos, '5');
    SPush(&simbolos, '*');
    SPush(&simbolos, '(');
    SPush(&simbolos, '3');
    SPush(&simbolos, '+');
    SPush(&simbolos, '8');
    SPush(&simbolos, ')');
    SPush(&simbolos, ']');
    SPush(&simbolos, '/');
    SPush(&simbolos, '(');
    SPush(&simbolos, '7');
    SPush(&simbolos, '+');
    SPush(&simbolos, '9');
    SPush(&simbolos, ')');

    Balanceada(simbolos) == 1 ? printf("expresion balanceada\n") : printf("no esta balanceada\n");

    return 0;
}

int LlenarPila(Pila_T *pila)
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

int Balanceada(Pila_T pila)
{
    Pila_T aux;
    aux = CrearPila();

    while (!PilaVacia(pila))
    {
        char dato = STop(pila);
        if (dato == ')' || dato == '}' || dato == ']')
            SPush(&aux, SPop(&pila));
        else 
        {
            if ((dato == '(' || dato == '{' || dato == '[') && PilaVacia(aux))
                return 0;
            else
                {
                    if(dato == '(' || dato == '{' || dato == '[')
                    {
                        SPop(&aux);
                        SPop(&pila);
                    }
                    else
                        SPop(&pila);
                }
        }
    }

    return((PilaVacia(aux)) ? 1 : 0);
}