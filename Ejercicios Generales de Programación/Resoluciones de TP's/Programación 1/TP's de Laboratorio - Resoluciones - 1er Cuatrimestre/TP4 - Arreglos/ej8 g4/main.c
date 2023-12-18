#include <stdio.h>
#include <stdlib.h>

char muestraarreglo(char[], int);
char buscamaximo(char[], int);

int main()
{
    char arreglo[100];
    int validos=0;
    carga(&arreglo, &validos);
    muestraarreglo(arreglo, validos);
    buscamaximo(arreglo, validos);
    return 0;
}

void carga (char arreglo[], int *validos)
{
    int i=0;
    *validos=8;
    for (i=0; i<*validos; i++)
    {
        printf("ingrese elemento numero %i del arreglo: \n", i);
        scanf("%c", &arreglo[i]);
        getchar();
    }
}

char muestraarreglo(char arreglo[], int validos)
{
    int i=0;
    for (i=0; i<validos; i++)
    {
        printf("%c", arreglo[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}

char buscamaximo(char arreglo[], int validos)
{
    int i=0;
    char letra;
    letra=arreglo[0];
    for (i=1; i<validos+1; i++)
    {
        if (letra<arreglo[i])
        {
            letra=arreglo[i];
        }
    }
    printf("El maximo caracter en el arreglo es: %c \n", letra);
    system("pause");
    return 0;
}
