#include <stdio.h>
#include <stdlib.h>

int cargaDeArreglos(float[],float[],int[],int);
int calculoPromedios(float[],float[],int[],float[],int);

int main()
{
    float notasParcial1[20];
    float notasParcial2[20];
    float promedios[20];
    int dnis[20];
    int validos = 20;
    int cargados = 0;
    int posicionMP = 0;
    cargados = cargaDeArreglos(notasParcial1,notasParcial2,dnis,validos);
    posicionMP = calculoPromedios(notasParcial1,notasParcial2,dnis,promedios,cargados);
    printf("El maximo promedio es del DNI %i", dnis[posicionMP]);


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

int calculoPromedios(float notasParcial1[], float notasParcial2[], int dnis[], float promedios[], int cargados)
{
    int i = 0;
    float promedio = 0;
    float maximoPromedio = 0;
    int posicionMP = 0;

    while(i < cargados)
    {
        printf("DNI: %i \n", dnis[i]);
        promedio = (notasParcial1[i] + notasParcial2[i]) / 2;
        printf("Nota promedio: %.2f \n", promedio);
        promedios[i] = promedio;
        i++;
    }
    int j = 0;

    while(j < cargados)
    {

        if(promedios[j] > promedios[j-1])
        {
           maximoPromedio = promedios[j];
           posicionMP = j;
        }

           j++;
    }

    return posicionMP;

}
