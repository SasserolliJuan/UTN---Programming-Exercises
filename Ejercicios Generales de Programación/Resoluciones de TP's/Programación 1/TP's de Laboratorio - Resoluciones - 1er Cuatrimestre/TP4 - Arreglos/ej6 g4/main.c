#include <stdio.h>
#include <stdlib.h>

char muestraarreglo(char[], int);
char buscadato(char[], int);

int main()
{
    char arreglo[100];
    int validos=0;
    carga(&arreglo, &validos);
    muestraarreglo(arreglo, validos);
    buscadato(arreglo, validos);
    return 0;
}

void carga (char arreglo[], int *validos)
{
    int i=0;
    *validos=10;
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

char buscadato(char arreglo[], int validos)
{
    int i=0;
    char letra;
    printf("ingrese letra a buscar:\n");
    scanf("%c", &letra);
    for (i=0; i<validos; i++)
    {
        if (letra==arreglo[i])
        {
            printf("La letra ingresada se encuentra dentro del arreglo de letras.\n");
        }
    }
    system("pause");
    return 0;
}
