#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50

void cargaArreglo(int[],int*);
void mostrarArreglo(int[],int);
void determinarCapicua(int[],int);

int main()
{
    int arreglo[TAM_MAX];
    int validos;
    cargaArreglo(arreglo,&validos);
    mostrarArreglo(arreglo,validos);
    determinarCapicua(arreglo,validos);
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
        scanf("%c",&continuar);

    }while((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    *validos = i;
}

void mostrarArreglo(int arreglo[],int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%i |", arreglo[i]);

    }
}

void determinarCapicua(int arreglo[],int validos)
{
    int i = 0;
    int j = validos - 1;

   while(arreglo[i] == arreglo[j])
   {
       i++;
       j--;
   }

   if(i == validos)
   {
       printf("\nEl arreglo es capicua. \n");
   }
   else
   {
       printf("\nEl arreglo no es capicua. \n");
   }
}
