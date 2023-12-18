#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50

void cargaArreglo(char[],int*);
void mostrarArreglo(char[],int);
void encontrarElemento(char[],int);

int main()
{
    char arreglo[TAM_MAX];
    int validos = 0;
    cargaArreglo(arreglo,&validos);
    mostrarArreglo(arreglo,validos);
    encontrarElemento(arreglo,validos);

}

void cargaArreglo(char arreglo[],int* validos)
{
    char continuar;
    int i = 0;

    do
    {
        printf("Ingrese los elementos: \n");
        fflush(stdin);
        scanf("%c", &arreglo[i]);
        i++;

        printf("Desea continuar?: \n");
        fflush(stdin);
        scanf("%c",&continuar);

    }while((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    *validos = i;
}

void mostrarArreglo(char arreglo[],int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%c", arreglo[i]);
        printf("\n");
    }
}

void encontrarElemento(char arreglo[],int validos)
{
    char letra;
    int i = 0;
    printf("Ingrese el elemento a encontrar: \n");
    fflush(stdin);
    scanf("%c", &letra);

    while(i < validos && arreglo[i] != letra)
    {
        i++;
    }

    if(i == validos)
    {
        printf("El elemento no se encuentra en el arreglo. \n");
    }
    else
    {
        printf("El elemento %c se encuentra en la posicion %i del arreglo. \n", letra, i);
    }

}
