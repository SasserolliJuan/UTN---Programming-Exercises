#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIL 6
#define LONG 6

int cargarArregloStr(char[FIL][LONG],int*);
void mostrarArreglo(char[FIL][LONG],int);
int busquedaDePalabra(char[][LONG],int);
int buscarPalabra(char[FIL][LONG],char[],int);

int main()
{
    char arregloStr[FIL][LONG];
    int validos = 0;
    char palabra[LONG];
    int validacion = 0;

    cargarArregloStr(arregloStr,&validos);
    mostrarArreglo(arregloStr,validos);


    validacion = busquedaDePalabra(arregloStr,validos);
    if(validacion == 0)
    {
        printf("\nSe ha encontrado la palabra en el arreglo. \n");
    }
    else
    {
        printf("\nNo se ha encontrado la palabra en el arreglo. \n");
    }
}

int cargarArregloStr(char arregloStr[FIL][LONG],int* validos)
{
    int i = 0;
    char continuar;

    do
    {
        printf("Ingrese un string para el arreglo: \n");
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
    printf("\n");
}

int busquedaDePalabra(char arregloStr[][LONG], int validos)
{
    int valorBusqueda = 0;
    char palabra[30];
    printf("Ingrese el string que desea buscar: \n");
    fflush(stdin);
    gets(palabra);

    valorBusqueda = buscarPalabra(arregloStr, palabra, validos);

    return valorBusqueda;
}
int buscarPalabra(char arregloStr[][LONG], char palabra[], int validos)
{
    int i = 0, validacion = -1;
    while(i < validos && strcmp(arregloStr[i], palabra) != 0)
    {
        i++;
    }

    if(i == validos)
    {
        validacion = i;
    }else
    {
        validacion = 0;
    }

    return validacion;
}
