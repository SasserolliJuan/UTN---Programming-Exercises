#include <stdio.h>
#include <stdlib.h>

char muestraarreglo(char[], int);
char insertadato(char[], int);

int main()
{
    char arreglo[100];
    int validos=0;
    carga(&arreglo, &validos);
    muestraarreglo(arreglo, validos);
    insertadato(arreglo, validos);
    muestraarreglo(arreglo, validos+1);
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

char insertadato(char arreglo[], int validos)
{
    int i=0, j=0;
    char letra;
    printf("ingrese letra a insertar:\n");
    scanf("%c", &letra);
    while ((letra>arreglo[i]) && (i<=validos))
    {
        i++;
    }
    if (i==validos)
    {
        arreglo[i+1]=letra;
    } else
    {
        for (j=(validos+1); j>i; j--)
        {
            arreglo[j]=arreglo[j-1];
        }
        arreglo[i]=letra;
    }
    system("pause");
    return 0;
}
