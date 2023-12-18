#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 50

void cargaArreglo(int[],int*);
void mostrarArreglo(int[],int);
void ordenacionInsercion(int[],int);
void ordenacionSeleccion(int[],int);
int menu();
void menuEjecucion(int[],int);

int main()
{
    int arreglo[TAM_MAX];
    int validos;

    menuEjecucion(arreglo,validos);

}

int menu()
{
    int respuesta = 0;
    printf("1. Ordenar por Insercion. \n");
    printf("2. Ordenar por Seleccion. \n");
    printf("3. Salir. \n");
    scanf("%i",&respuesta);
    return respuesta;
}

void menuEjecucion(int arreglo[],int validos)
{
    int respuesta = 0;
    do
    {
        respuesta = menu();
        switch(respuesta)
        {
        case 1:
            cargaArreglo(arreglo,&validos);
            mostrarArreglo(arreglo,validos);
            printf("\n");
            printf("\n\nOrdenacion por Insercion: \n");
            ordenacionInsercion(arreglo,validos);
            printf("\n");
            mostrarArreglo(arreglo,validos);
            printf("\n");
            break;

        case 2:
            cargaArreglo(arreglo,&validos);
            mostrarArreglo(arreglo,validos);
            printf("\n");
            printf("\n\nOrdenacion por Seleccion: \n");
            ordenacionSeleccion(arreglo,validos);
            printf("\n");
            mostrarArreglo(arreglo,validos);
            printf("\n");
            break;

        default:
            break;

        }
    }while(respuesta != 3);
}

void cargaArreglo(int arreglo[],int* validos)
{
    char continuar;
    int i = 0;

    do
    {
        printf("Ingrese los elementos: \n");
        scanf("%i", &arreglo[i]);
        i++;

        printf("Desea continuar?: \n");
        fflush(stdin);
        scanf("%c",&continuar);

    }while((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    *validos = i;
}

void mostrarArreglo(int arreglo[],int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%i |", arreglo[i]);

    }
}

void ordenacionInsercion(int arreglo[],int validos)
{
    int aux = 0;

    for(int i = 0; i < validos; i++)
    {
        aux = arreglo[i];

        while(i > 0 && arreglo[i-1] > aux){     /// mientras i sea mayor a 0 y arreglo[i-1] (el anterior) sea mayor al elemento
            arreglo[i] = arreglo[i-1]; ///corro los elementos de izq a der
            i--;
        } /// cuando termina tengo el hueco
        arreglo[i] = aux; ///inserto en el hueco

}
}

void ordenacionSeleccion(int arreglo[],int validos)
{
    int posicionMenor = 0;
    int aux = 0;
    int j = 0;

    for(int i = 0; i < validos; i++)
    {
        posicionMenor = i;   ///Asigno la posicion I como la menor posicion.

        for(int j = i + 1; j < validos; j++) ///J va a ir recorreindo, a partir de la siguiente celda (j = i + 1) todo el arreglo buscando el próximo menor de todos los elementos.
        {
            if(arreglo[j] < arreglo[i])   ///Si el elemento que se encuentra en la posicion J es menor que el elemento que se encuntra en la posicion I (el que es considerado como el menor hasta ahora), va a reemplzar al elemento de I como el menor de todos.
            {
                posicionMenor = j;
            }
        }

        aux = arreglo[i];    ///Hago el pasaje de elementos.
        arreglo[i] = arreglo[posicionMenor];
        arreglo[posicionMenor] = aux;

    }

}

