#include <stdio.h>
#include <stdlib.h>

int cargaDeArreglos(float[],float[],int[],int);
void mostrarArreglos(float[],float[],int[],int);

int main()
{
    float notasParcial1[20];
    float notasParcial2[20];
    int dnis[20];
    int validos = 20;
    int cargados = 0;
    int posicionDni = 0;
    int posicionNota = 0;
    cargados = cargaDeArreglos(notasParcial1,notasParcial2,dnis,validos);
    posicionNota = busquedaMaximaNotaPrimerParcial(notasParcial1,cargados);
    printf("La maxima nota esta en la posicion %i \n", posicionNota);
    posicionDni = busquedaDni(dnis,cargados,posicionNota);
    printf("La maxima nota le corresponde al DNI %i", dnis[posicionDni]);
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

int busquedaMaximaNotaPrimerParcial(float notasParcial1[], int cargados)
{
    int i = 0;
    float maximaNota = 0;
    int posicionNota = 0;

    while(i < cargados)
    {
        if(notasParcial1[i] > notasParcial1[i-1])
        {
            maximaNota = notasParcial1[i];
            posicionNota = i;
        }

        i++;
    }

    return posicionNota;
}

int busquedaDni(int dnis[], int cargados, int posicionNota)
{
    int i = 0;
    int posicionDni = 0;

    while(i != posicionNota)
    {
        i++;

    }
    if (i == posicionNota)
    {
        posicionDni = i;
    }
    return posicionDni;
}

