#include <stdio.h>
#include <stdlib.h>

int muestraarreglo(int[], int);
int capicua(int[], int);

int main()
{
    int arreglo[100];
    int validos=0;
    carga(&arreglo, &validos);
    muestraarreglo(arreglo, validos);
    capicua(arreglo, validos);
    return 0;
}

void carga (int arreglo[], int *validos)
{
    int i=0;
    *validos=7;
    for (i=0; i<*validos; i++)
    {
        printf("ingrese elemento numero %i del arreglo: \n", i);
        scanf("%i", &arreglo[i]);
    }
}

int muestraarreglo(int arreglo[], int validos)
{
    int i=0;
    for (i=0; i<validos; i++)
    {
        printf("%i", arreglo[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}

int capicua(int arreglo[], int validos)
{
    int i=0, j=0, aux[100];
    for ((i=validos-1); i>-1; i--)
    {
        aux[j]=arreglo[i];
        j++;
    }
    i=0;
    while ((arreglo[i]==aux[i]) && (i!=validos))
    {
        i++;
    }
    if (i==(validos))
    {
        printf("El arreglo es capicua. \n");
    } else
    {
        printf("El arreglo NO es capicua. \n");
    }
    system("pause");
    return 0;
}
