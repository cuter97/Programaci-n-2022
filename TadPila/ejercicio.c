/*2) Usando los TADs que crea necesario, resolver los siguientes problemas (para simplificar puede elegir el tipo
de a usar, enteros, char, flotantes, etc.):
- Escribir una función para que, dadas las pilas A y B, determinar si A y B son iguales. Al finalizar la función
A y B deben quedar con sus valores originales.
- Escribir una función para que, dadas las pilas A y B, determinar si B es exactamente el reverso de A (valores
en orden inverso). Al finalizar la función A y B deben quedar con sus valores originales.
- Escribir una función para que, dada la pila Z y el elemento w, retorne verdadero si w no está Z. Al finalizar la
función Z debe quedar con sus valores originales.*/

#include <stdio.h>
#include "Pila.h"

//imprime por pantalla una pila sin modificar su valor
int mostrarPila(Pila_T p1)
{
    while (!Pila_Vacia(p1))
        printf("%d ", S_Pop(&p1));

    printf("\n");
    return 0;
}

//retorna 0 si las pilas a y b son iguales 1 caso contrario
int Iguales(Pila_T A, Pila_T B)
{
    if (Longitud_Pila(A) == Longitud_Pila(B))
    {
        while (!Pila_Vacia(A))
        {
            if (S_Pop(&A) != S_Pop(&B))
                return 1;
        }
        return 0;
    }
    else
        return 1;  
}

//retorna 0 si la pila a es el inverso de b, 0 caso contrario
int Inverso(Pila_T A, Pila_T B)
{
    if (Longitud_Pila(A) == Longitud_Pila(B))
    {
        Pila_T aux;
        aux = Crear_Pila();

        while (!Pila_Vacia(A))
            S_Push(&aux, S_Pop(&A));
        
        if (Iguales(B, aux) == 1) //si iguales retorna 1 significa que no es el inverso
            return 1;

        return 0;   
    }
    else
        return 1;
    
}

//retorna 1 si el elemento x existe 0 caso contrario
int Buscar(Pila_T pila, int x)
{
    int flag = 1, n;
    while (!Pila_Vacia(pila) && flag == 1)
    {
        n = S_Pop(&pila);
        if (n == x)
            flag = 0;
        
    }
    if (flag == 0)
        return 1;
    return 0;
}

int main()
{
    Pila_T A, B;
    A = Crear_Pila();
    B = Crear_Pila();

    S_Push(&A, 1);
    S_Push(&A, 2);
    S_Push(&A, 4);
    S_Push(&A, 5);
    mostrarPila(A);

    S_Push(&B, 5);
    S_Push(&B, 4);
    S_Push(&B, 2);
    S_Push(&B, 1);
    mostrarPila(B);
    
    (Iguales(A, B) == 1) ? printf("No son iguales\n") : printf("Son iguales\n");

    (Inverso(A, B) == 1) ? printf("No es el inverso\n") : printf("Es el inverso\n");

    (Buscar(A, 8) == 1) ? printf("Existe\n") : printf("No existe\n");

    mostrarPila(A);
    mostrarPila(B);
    return 0;
}
