#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50

int cargaValores(int[],int*);

int main()
{
    int arreglo[TAM_MAX];
    int validos = 0;
    int cantElementos = 0;
    cantElementos = cargaValores(arreglo,&validos);
    printf("Se han cargado %i elementos. \n");

}

int cargaValores(int arreglo[], int* validos)
{
    char continuar;
    int i = 0;

    do
    {
        printf("Ingrese un valor al arreglo: \n");
        scanf("%i", &arreglo[i]);
        i++;

        printf("Desea contimuar?: s/S = Si, n = No\n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    *validos = i;

    return *validos;
}
