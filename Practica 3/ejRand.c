/*Se leen numeros del teclado hasta el valor 0. No se sabe cuantos valores seran leidos. Almacenarlos de
forma eficiente. Una vez leidos todos los numeros, primero, imprimir los pares de forma inversa a como
se han leido desde el teclado y luego los impares en el mismo orden en que fueron leidos. Utilice
TADs, asumiendo que estan implementados. No puede modificar funciones de los TADs ni acceder a las
estructuras de los mismos.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../Tadlista/listaDE.h"

int mostrarparesinverso(ListaDE_T l);
int mostrarimparesenorden(ListaDE_T l);

int main()
{
    int x = 1;
    ListaDE_T libros;
    libros = CrearLista();

    while (x != 0)
    {
        scanf("%d", &x);
        InsertarPrimero(&libros, x);
    }
    SuprimirDato(&libros, 0);
    printf("\n");
    RecorrerListaEnOrden(libros);
    printf("\n");
    mostrarimparesenorden(libros);
    printf("\n");
    mostrarparesinverso(libros);
    return 0;
}
int mostrarparesinverso(ListaDE_T l)
{
    ListaDE_T aux;
    aux = CrearLista();
    int x;
    for (int i = 1; i <= LongitudLista(l); i++)
    {
        x = DevolverDatoPosicion(l, i);
        if (x % 2 == 0)
        {
           InsertarUltimo(&aux, x);
        }
    }
    RecorrerListaEnOrden(aux);
    return 0;
}
int mostrarimparesenorden(ListaDE_T l)
{
    ListaDE_T aux;
    aux = CrearLista();
    int x;
    for (int i = 1; i <= LongitudLista(l); i++)
    {
        x = DevolverDatoPosicion(l, i);
        if (x % 2 == 1)
        {
            InsertarPrimero(&aux, x);
        }
    }
    RecorrerListaEnOrden(aux);
    return 0;
}