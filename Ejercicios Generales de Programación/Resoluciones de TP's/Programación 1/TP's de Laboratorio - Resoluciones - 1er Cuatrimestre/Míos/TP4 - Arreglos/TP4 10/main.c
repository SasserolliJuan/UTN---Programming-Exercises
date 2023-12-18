#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50

void cargaArreglo(int[],int*);
void mostrarArreglo(int[],int);
void invertirElementos(int[],int*);


int main()
{
   int arreglo[TAM_MAX];
   int validos;
   cargaArreglo(arreglo,&validos);
   mostrarArreglo(arreglo,validos);
   printf("\n");
   invertirElementos(arreglo,&validos);
   mostrarArreglo(arreglo,validos);

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

void invertirElementos(int arreglo[],int* validos)
{
    (*validos) + 1;
    int aux = 0;
    int i = 0;
    int j = *validos - 1;

    while((i != j) || (i == *validos) )
    {
        if(arreglo[i] != arreglo[j])
          {
            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;

            i++;
            j--;

          }

    }

}
