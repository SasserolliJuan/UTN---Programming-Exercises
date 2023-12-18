#include <stdio.h>
#include <stdlib.h>
#include "nodoAlumno.h"

int main()
{

    nodo*lista=iniclista();
    char continuar;
    int dato;
    do
	{
		nodo*nA=crearnodoAlumno();
		lista=agregarppio(lista,nA);
		printf("Desea continuar?\n");
		fflush(stdin);
		scanf("%c", &continuar);

	}while(continuar=='s');
	printf("Que alumno desea buscar\n?");
	scanf("%i", &dato);
	nodo*aux=buscarnodo(dato,lista);


    return 0;
}
