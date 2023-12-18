#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargaDeArreglos(float[],float[],int[],int);
void calculoPromedios(float[],float[],int[],float[],int);
void pasajeDeDnisAPila(int[],float[],int,Pila*);
void eliminacionDeElementosEnPila(Pila,int,Pila);

int main()
{
    float notasParcial1[20];
    float notasParcial2[20];
    float promedios[20];
    int dnis[20];

    Pila d,aux;
    inicpila(&d);
    inicpila(&aux);

    int validos = 20;
    int cargados = 0;

    cargados = cargaDeArreglos(notasParcial1,notasParcial2,dnis,validos);
    calculoPromedios(notasParcial1,notasParcial2,dnis,promedios,cargados);
    pasajeDeDnisAPila(dnis,promedios,cargados,&d);
    eliminacionDeElementosEnPila(d,cargados,aux);


}

int cargaDeArreglos(float notasParcial1[], float notasParcial2[], int dnis[], int validos)
{
    char continuar;
    int i = 0;
    int cargados = 0;
    int aux = 0;

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

void calculoPromedios(float notasParcial1[], float notasParcial2[], int dnis[], float promedios[], int cargados)
{
    int i = 0;
    float promedio = 0;

    while(i < cargados)
    {
        printf("DNI: %i \n", dnis[i]);
        promedio = (notasParcial1[i] + notasParcial2[i]) / 2;
        printf("Nota promedio: %.2f \n", promedio);
        promedios[i] = promedio;
        i++;
    }
}

void pasajeDeDnisAPila(int dnis[], float promedios[], int cargados, Pila* d)
{
    int i = 0;

    while(i < cargados)
    {
        if(promedios[i] > 7)
        {
            apilar(d,dnis[i]);
            i++;
        }
        else
        {
            i++;
        }
    }
    printf("La Pila Dnis ha quedado de la siguiente manera: \n");
    mostrar(d);
}


void eliminacionDeElementosEnPila(Pila d, int cargados,Pila aux)
{
    int i = 0;
    int basura = 0;

    while(!pilavacia(&d))
    {
        if(tope(&d) > 40000000)
        {
            apilar(&aux,desapilar(&d));

        }
        else if (tope(&d) < 40000000)
        {
            basura = desapilar(&d);
        }
    }

    while(!pilavacia(&aux))
    {
        apilar(&d,desapilar(&aux));
    }

    printf("La pila, al quitar los DNIS menores a 40000000, ha quedado asi: \n");
    mostrar(&d);
}
