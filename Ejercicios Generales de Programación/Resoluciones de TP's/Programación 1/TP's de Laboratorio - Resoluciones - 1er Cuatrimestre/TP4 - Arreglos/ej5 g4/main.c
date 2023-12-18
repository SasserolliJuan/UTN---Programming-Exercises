#include <stdio.h>
#include <stdlib.h>

float muestraarreglo(float[], int);
float sumaarreglo(float[], int);


int main()
{
    float sumado=0, arreglo[100];
    int validos=0;
    srand(time(NULL));
    carga(&arreglo, &validos);
    muestraarreglo(arreglo, validos);
    sumado=sumaarreglo(arreglo, validos);
    printf("La suma de los elementos del arreglo da: %.2f \n", sumado);
    system("pause");
    return 0;
}

void carga (float arreglo[], int *validos)
{
    int i=0;
    *validos=10;
    for (i=0; i<*validos; i++)
    {
        arreglo[i]=(float) (rand() % 100)/5;
    }
}

float muestraarreglo(float arreglo[], int validos)
{
    int i=0;
    for (i=0; i<validos; i++)
    {
        printf("| %.2f |", arreglo[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}

float sumaarreglo(float arreglo[], int validos)
{
    int i=0;
    float suma=0;
    for (i=0; i<validos; i++)
    {
        suma+=arreglo[i];
    }
    return suma;
}
