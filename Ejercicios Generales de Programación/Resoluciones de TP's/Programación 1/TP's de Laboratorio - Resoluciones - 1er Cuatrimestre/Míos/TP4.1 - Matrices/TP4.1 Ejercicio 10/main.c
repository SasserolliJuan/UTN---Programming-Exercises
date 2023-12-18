#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIL 20
#define LONG 30

void cargaArregloStrings(char[][LONG],int*);
void muestraArregloStrings(char[][LONG],int);
void insercionOrdenada(char[][LONG],char[],int);


int main()
{

    char arregloStr[FIL][LONG];
    int validos = 0;
    cargaArregloStrings(arregloStr, &validos);
    muestraArregloStrings(arregloStr, validos);

    return 0;
}

void cargaArregloStrings(char arregloStr[][LONG], int* validos)
{
    int i = 0;
    char continuar;
    char nombre[LONG];

    do
    {
        printf("Ingrese un string para el arreglo: \n");
        fflush(stdin);
        gets(nombre);
        i++;
        insercionOrdenada(arregloStr,nombre,i);

        printf("Desea continuar?: s/n \n");
        fflush(stdin);
        scanf("%c",&continuar);

    }while (i < FIL && (continuar == 's' || continuar == 'S'));

    *validos = i;

}

void insercionOrdenada(char arregloStr[][LONG], char nombre[], int validos)
{
    int i = validos - 1;
    while (i >= 0 && strcmp(arregloStr[i],nombre) > 0)
    {
        strcpy(arregloStr[i+1], arregloStr[i]);
        i--;
    }

    strcpy(arregloStr[i+1],nombre);

}

void muestraArregloStrings(char arregloStr[][LONG], int validos)
{
    for (int i = 0 ; i < validos+1 ; i++)
    {
        puts(arregloStr[i]);
    }

}






