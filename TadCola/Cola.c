#include <stdlib.h>
#include <stdio.h>
#include "Cola.h"

Cola_T Crear_Cola()
{
	Cola_T cola;
	cola.frente = 0;
	cola.final = TamMax - 1;
	return cola;
}

int Q_Push(Cola_T *cola, Tipo_Dato x)
{
	if (!Cola_Llena(*cola))
	{
		cola->final = (cola->final + 1) % TamMax;
		cola->cola[cola->final] = x;
	}
	else
	{
		printf("Error: cola llena");
		exit(-1);
	}
	return 0;
}

Tipo_Dato Q_Pop(Cola_T *cola)
{
	if (!Cola_Vacia(*cola))
	{
		Tipo_Dato dato;
		dato = cola->cola[cola->frente];
		cola->frente = (cola->frente + 1) % TamMax;
		return dato;
	}
	else
	{
		printf("cola vacia");
		exit(-1);
	}
}

int Cola_Llena(Cola_T cola)
{
	return ((cola.final + 2) % TamMax == cola.frente);
}

int Cola_Vacia(Cola_T cola)
{
	return ((cola.final + 1) % TamMax == cola.frente);
}

int Longitud_Cola(Cola_T cola)
{
	return cola.final;
}

Tipo_Dato Q_Top(Cola_T cola)
{
	if (Cola_Vacia(cola))
	{
		printf("Error: cola vacia\n");
		exit(-1);
	}
	else
	{
		Tipo_Dato dato;
		dato = cola.cola[cola.frente];
		return dato;
	}
}

int Vaciar_Cola(Cola_T *cola)
{
	cola->final = -1;
	return 0;
}
