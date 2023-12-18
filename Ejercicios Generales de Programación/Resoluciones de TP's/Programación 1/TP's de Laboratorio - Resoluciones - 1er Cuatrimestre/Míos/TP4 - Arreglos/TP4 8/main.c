#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50

void cargaArreglo(char[],int*);
void mostrarArreglo(char[],int);
char obtencionMaximoCaracter(char[],int);


int main()
{
    char arreglo[TAM_MAX];
    int validos;
    char mayor;
    cargaArreglo(arreglo,&validos);
    mostrarArreglo(arreglo,validos);
    mayor = obtencionMaximoCaracter(arreglo,validos);
    printf("\nEl mayor caracter es: %c", mayor);

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

char obtencionMaximoCaracter(char arreglo[],int validos)
{
    char mayor;
    for(int i = 0; i < validos; i++)
    {
        if(arreglo[i] >= mayor)
        {
            mayor = arreglo[i];
        }


    }
    return mayor;
}
