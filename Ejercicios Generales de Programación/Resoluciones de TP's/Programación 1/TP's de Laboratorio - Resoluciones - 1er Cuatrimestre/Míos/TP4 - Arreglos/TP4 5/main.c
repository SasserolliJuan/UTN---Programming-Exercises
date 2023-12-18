#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100

void cargaArreglo(float[],int*);
void mostrarArreglo(float[],int);
float sumaElementosArreglo(float[],int);

int main()
{
    float arreglo[TAM_MAX];
    int validos = 0;
    cargaArreglo(arreglo,&validos);
    mostrarArreglo(arreglo,validos);

    float suma = 0;
    suma = sumaElementosArreglo(arreglo,validos);
    printf("La suma de los elementos es de: %f \n", suma);

}

void cargaArreglo(float arreglo[],int* validos)
{
    char continuar;
    int i = 0;

    do
    {
        printf("Ingrese los elementos: \n");
        scanf("%f",&arreglo[i]);
        i++;

        printf("Desea continuar?: \n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    *validos = i;
}

void mostrarArreglo(float arreglo[],int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%f", arreglo[i]);
        printf("\n");
    }
}

float sumaElementosArreglo(float arreglo[],int validos)
{
    float suma = 0;
    for(int i = 0; i < validos; i++)
    {
        suma += arreglo[i];
    }
    return suma;
}
