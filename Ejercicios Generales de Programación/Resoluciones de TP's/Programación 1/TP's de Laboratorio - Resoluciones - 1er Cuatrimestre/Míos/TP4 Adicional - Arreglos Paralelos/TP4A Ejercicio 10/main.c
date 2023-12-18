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

    cargados = cargaDeArreglos(notasParcial1,notasParcial2,dnis,validos);
    calculoPromedios(notasParcial1,notasParcial2,dnis,promedios,cargados);

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
    int j = 0;
    float sumaNotasPrimerParcial = 0;
    int cantNotasPrimerParcial = 0;
    float sumaNotasSegundoParcial = 0;
    int cantNotasSegundoParcial = 0;
    float promedioTotal = 0;

    while(i < cargados)
    {

            sumaNotasPrimerParcial += notasParcial1[i];
            i++;
            cantNotasPrimerParcial++;

            sumaNotasSegundoParcial += notasParcial2[j];
            j++;
            cantNotasSegundoParcial++;
   }

    printf("Sumatoria de todas las notas del primer parcial: %f \n", sumaNotasPrimerParcial);
    printf("Sumatoria de todas las notas del segundo parcial: %f \n", sumaNotasSegundoParcial);
    printf("Cantidad de todas las notas del primer parcial: %i \n", cantNotasPrimerParcial);
    printf("Cantidad de todas las notas del segundo parcial: %i \n", cantNotasSegundoParcial);
    promedioTotal = (sumaNotasPrimerParcial + sumaNotasSegundoParcial) / (cantNotasPrimerParcial + cantNotasSegundoParcial);
    printf("Nota promedio total: %.2f \n", promedioTotal);

}
