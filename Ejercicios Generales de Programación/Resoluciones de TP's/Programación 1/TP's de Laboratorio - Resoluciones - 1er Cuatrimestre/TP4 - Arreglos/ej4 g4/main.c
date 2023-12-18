#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int copiaapila(int[], int, Pila);
int muestraarreglo(int[], int);

int main()
{
    Pila dada;
    inicpila(&dada);
    int arreglo[100], validos=0;
    srand(time(NULL));
    carga(&arreglo, &validos);
    muestraarreglo(arreglo, validos);
    copiaapila(arreglo, validos, dada);
    return 0;
}

void carga (int arreglo[], int *validos)
{
    int i=0;
    *validos=10;
    for (i=0; i<*validos; i++)
    {
        arreglo[i]=(rand() % 100);
    }
}

int muestraarreglo(int arreglo[], int validos)
{
    int i=0;
    for (i=0; i<validos; i++)
    {
        printf("| %i |", arreglo[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}

int copiaapila(int arreglo[], int validos, Pila dada)
{
    int i=0, suma=0;
    for (i=0; i<validos; i++)
    {
        apilar(&dada, arreglo[i]);
    }
    printf("Pila dada \n");
    mostrar(&dada);
    system("pause");
    return 0;
}
