#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50

void cargaArreglo(int[],int*);
int sumaElementosArreglo(int[],int);
void mostrarArreglo(int[],int);

int main()
{
    int arreglo[TAM_MAX];
    int validos = 0;
    int suma = 0;
    cargaArreglo(arreglo,&validos);
    mostrarArreglo(arreglo,validos);
    suma = sumaElementosArreglo(arreglo,validos);
    printf("La suma de los elementos es igual a: %i", suma);
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

int sumaElementosArreglo(int arreglo[],int validos)
{
    int suma = 0;

    for(int i = 0; i < validos; i++)
    {
        suma += arreglo[i];
    }

    return suma;
}

void mostrarArreglo(int arreglo[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%i", arreglo[i]);
        printf("\n");
    }
}
