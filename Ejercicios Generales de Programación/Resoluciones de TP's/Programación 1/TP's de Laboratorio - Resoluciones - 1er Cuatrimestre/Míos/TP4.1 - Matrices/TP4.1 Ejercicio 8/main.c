#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIL 6
#define LONG 6

int cargarArregloStr(char[FIL][LONG],int*);
void mostrarArreglo(char[FIL][LONG],int);

int main()
{
    char arregloStr[FIL][LONG];
    int validos = 0;
    cargarArregloStr(arregloStr,&validos);
    mostrarArreglo(arregloStr,validos);
}

int cargarArregloStr(char arregloStr[FIL][LONG],int* validos)
{
    int i = 0;
    char continuar;

    do
    {
        printf("Ingrese un string para la matriz: \n");
        fflush(stdin);
        gets(arregloStr[i]);
        i++;

        printf("Desea continuar?: s/n \n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while((continuar == 's' || continuar == 'S') && i < FIL);

    *validos = i;

     return *validos;
}

void mostrarArreglo(char arregloStr[FIL][LONG],int validos)
{
    for(int i = 0; i < validos; i++)
    {
        puts(arregloStr[i]);
    }
}
