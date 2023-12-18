#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50

void cargaArreglo(int[],int*);
void impresionArreglo(int[],int);

int main()
{
    int arreglo[TAM_MAX];
    int validos = 0;
    cargaArreglo(arreglo,&validos);
    impresionArreglo(arreglo, validos);


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

        printf("Desea seguir?: \n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    *validos = i;

}

void impresionArreglo(int arreglo[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%i", arreglo[i]);
        printf("\n");
    }
}
