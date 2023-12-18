#include <stdio.h>
#include <stdlib.h>

int sumaarreglo(int[], int);
int muestraarreglo(int[], int);

int main()
{
    int arreglo[100], validos=0;
    srand(time(NULL));
    carga(&arreglo, &validos);
    muestraarreglo(arreglo, validos);
    sumaarreglo(arreglo, validos);
    return 0;
}

void carga (int arreglo[], int *validos)
{
    int i=0;
    *validos=10;
    for (i=0; i<*validos; i++)
    {
        arreglo[i]=(rand() % 100);
    }
}

int muestraarreglo(int arreglo[], int validos)
{
    int i=0;
    for (i=0; i<validos; i++)
    {
        printf("| %i |", arreglo[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}

int sumaarreglo(int arreglo[], int validos)
{
    int i=0, suma=0;
    for (i=0; i<validos; i++)
    {
        suma=suma+arreglo[i];
    }
    printf("La suma de los elementos ingresados da: %i \n", suma);
    system("pause");
    return 0;
}
