#include <stdio.h>
#include <stdlib.h>

int cargaDeArreglos(float[],float[],int[],int);
int busquedaDni(int[],int,int);
void mostrarNotas(float[],float[],int,int);

int main()
{
    float notasParcial1[20];
    float notasParcial2[20];
    int dnis[20];
    int validos = 20;
    int cargados = 0;
    int dni = 0;
    int posicion = 0;
    cargados = cargaDeArreglos(notasParcial1,notasParcial2,dnis,validos);
    printf("Cual DNI desea buscar?: \n");
    scanf("%i", &dni);
    posicion = busquedaDni(dnis,cargados,dni);
    if(posicion == -1)
    {
        printf("El DNI no se encuentra en el arreglo. \n");
    }
    else
    {
        printf("El DNi a buscar se encuentra en la posicion %i del arreglo. \n", posicion);
    }
    mostrarNotas(notasParcial1,notasParcial2,posicion,cargados);

}

int cargaDeArreglos(float notasParcial1[], float notasParcial2[], int dnis[], int validos)
{
    char continuar;
    int i = 0;
    int cargados = 0;
    int aux = 0;
    float auxN = 0;

    do
    {

        printf("Ingrese el DNI correspondiente: \n");
        scanf("%i", &dnis[i]);
        printf("Ingrese las notas por DNI: \n");
        scanf("%f", &notasParcial1[i]);
        scanf("%f", &notasParcial2[i]);
        i++;
        cargados++;

        printf("Desea continuar?: s/n \n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while((continuar == 's' || continuar == 'S') && i < validos);

    return cargados;
}

int busquedaDni(int dnis[], int cargados, int dni)
{
    int i = 0;
    int posicion = 0;

    while(i < cargados && dnis[i] != dni)
    {
        i++;
    }
    if (i == cargados)
    {
        posicion = -1;
    }
    else
    {
        posicion = i;
    }
    return posicion;
}



void mostrarNotas(float notasParcial1[], float notasParcial2[],int posicion, int cargados)
{
    int i = 0;

    while(i < cargados && i != posicion)
    {
        i++;
    }
    if(i == cargados)
    {
        printf("El DNI no existe. \n");
    }
    else
    {
        printf("DNI encontrado. Sus notas son: \n");
        printf("Nota del primer parcial: %.2f \n", notasParcial1[i]);
        printf("Nota del segundo parcial: %.2f \n", notasParcial2[i]);
    }
}

