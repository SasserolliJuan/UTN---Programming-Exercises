#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIL 5
#define LONG 5

int cargarArregloStr(char[FIL][LONG],int*);

int main()
{
    char arregloStr[FIL][LONG];
    int validos = 0;
    validos = cargarArregloStr(arregloStr,&validos);
    printf("Se han cargado %i strings", validos);
}

int cargarArregloStr(char arregloStr[FIL][LONG],int* validos)
{
    int i = 0;
    char continuar;
    char palabra[LONG];

    do
    {
        printf("Ingrese un string para la matriz: \n");
        fflush(stdin);
        gets(arreglo[i]);
        i++;

        printf("Desea continuar?: s/n \n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while((continuar == 's' || continuar == 'S') && i < FIL);

    *validos = i;

    return *validos;
}
