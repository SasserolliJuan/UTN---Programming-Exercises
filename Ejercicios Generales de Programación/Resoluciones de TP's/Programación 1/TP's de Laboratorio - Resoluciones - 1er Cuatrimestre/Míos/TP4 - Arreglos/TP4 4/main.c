#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50
#include "pila.h"


void cargaArreglo(int[], int*);
void copiaElementosAPila(int[],int,Pila*);


int main()
{

    int arreglo[TAM_MAX];
    int validos = 0;
    cargaArreglo(arreglo,&validos);

    Pila a;
    inicpila(&a);
    copiaElementosAPila(arreglo,validos,&a);
    mostrar(&a);

}

void cargaArreglo(int arreglo[],int* validos)
{
    char continuar;
    int i = 0;

    do
    {
        printf("Ingrese los elementos: \n");
        scanf("%i", &arreglo[i]);
        i++;

        printf("Desea continuar?: \n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    *validos = i;
}

void copiaElementosAPila(int arreglo[],int validos, Pila* p)
{
    for(int i = 0; i < validos; i++)
    {
        apilar(p,*arreglo[i]);
    }
}
