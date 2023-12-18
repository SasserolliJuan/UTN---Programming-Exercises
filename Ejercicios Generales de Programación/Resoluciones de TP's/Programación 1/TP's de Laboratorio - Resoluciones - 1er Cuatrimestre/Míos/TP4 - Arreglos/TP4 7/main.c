#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50

void cargaArreglo(char[],int*);
void mostrarArreglo(char[],int);
void insertarElemento(char[],int*,char);

int main()
{
   char arreglo[TAM_MAX];
   int validos = 0;
   char letra;
   cargaArreglo(arreglo,&validos);
   mostrarArreglo(arreglo,validos);
   insertarElemento(arreglo,&validos,letra);
   mostrarArreglo(arreglo,validos+1);
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
        printf("%c |", arreglo[i]);

    }
}

void insertarElemento(char arreglo[],int* validos, char letra)
{
    int i = (*validos)-1;

    printf("\nIngrese la letra a insertar: \n");
    fflush(stdin);
    scanf("%c",&letra);

    while((i >= 0) && (arreglo[i] > letra))
    {
        arreglo[i+1] = arreglo[i];
        i--;
    }

    arreglo[i+1] = letra;
    (*validos)+1;

}

