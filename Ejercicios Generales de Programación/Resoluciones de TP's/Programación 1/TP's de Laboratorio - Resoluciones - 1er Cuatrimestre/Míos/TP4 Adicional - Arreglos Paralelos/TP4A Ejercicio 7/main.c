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
    cargados = cargaDeArreglos(notasParcial1,notasParcial2,dnis,validos);
    mostrarArreglos(notasParcial1,notasParcial2,dnis,cargados);
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

void mostrarArreglos(float notasParcial1[], float notasParcial2[], int dnis[], int cargados)
{
    int i = 0;
    float promedio = 0;

    while(i < cargados)
    {
        printf("DNI: %i \n", dnis[i]);
        promedio = (notasParcial1[i] + notasParcial2[i]) / 2;
        printf("Nota promedio: %.2f \n", promedio);

         if ((promedio == 8 || promedio > 8) && (notasParcial1[i] > 6 && notasParcial2[i] > 6))
    {
        printf("DNI: %i promociona la materia. \n", dnis[i]);

    }
    else
    {
        printf("DNI: %i NO promociona la materia. \n", dnis[i]);
    }
        i++;
    }

}

