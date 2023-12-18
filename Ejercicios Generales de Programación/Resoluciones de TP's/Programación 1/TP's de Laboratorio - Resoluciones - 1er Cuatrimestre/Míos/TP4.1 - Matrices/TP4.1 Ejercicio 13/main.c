#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL1 2
#define COL1 2
#define FIL2 2
#define COL2 5

void cargarMatriz1(int[FIL1][COL1]);
void cargarMatriz2(int[FIL2][COL2]);
void mostrarMatriz1(int[FIL1][COL1]);
void mostrarMatriz2(int[FIL2][COL2]);
void multiplicacion(int[FIL1][COL1],int[FIL2][COL2],int[FIL2][COL2]);

int main()
{
    int matriz1[FIL1][COL1];
    int matriz2[FIL2][COL2];
    int matrizDatos[FIL2][COL2];

    srand(time(NULL));

    cargarMatriz1(matriz1);
    mostrarMatriz1(matriz1);
    cargarMatriz2(matriz2);
    mostrarMatriz2(matriz2);
    multiplicacion(matriz1,matriz2,matrizDatos);
    mostrarMatrizDatos(matrizDatos);

}

void cargarMatriz1(int matriz1[FIL1][COL1])
{
    for(int i = 0; i < FIL1; i++)
    {
        for(int j = 0; j < COL1; j++)
        {
            matriz1[i][j] = rand()%10;
            printf("Matriz[%i][%i] = %i \n",i,j,matriz1[i][j]);
        }
        printf("\n");
    }
}
void mostrarMatriz1(int matriz1[FIL1][COL1])
{
    printf("Matriz 1: \n");
    for(int i = 0; i < FIL1; i ++)
    {
        for(int j = 0; j < COL1; j++)
        {

            printf("%i  ",matriz1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void cargarMatriz2(int matriz2[FIL2][COL2])
{
    for(int i = 0; i < FIL2; i++)
    {
        for(int j = 0; j < COL2; j++)
        {
            matriz2[i][j] = rand()%10;
            printf("Matriz[%i][%i] = %i \n",i,j,matriz2[i][j]);
        }
        printf("\n");
    }
}

void mostrarMatriz2(int matriz2[FIL2][COL2])
{
    printf("Matriz 2: \n");
    for(int i = 0; i < FIL2; i ++)
    {
        for(int j = 0; j < COL2; j++)
        {
            printf("%i  ",matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicacion(int matriz1[FIL1][COL1],int matriz2[FIL2][COL2],int matrizDatos[FIL2][COL2])
{

    for(int i = 0; i < FIL1; i++)
    {
        for(int j = 0; j < COL2; j++)
        {
           int suma = 0;

             for(int k = 0; k < COL1; k++)
             {
                 suma += matriz1[i][k] * matriz2[k][j];
             }
             matrizDatos[i][j] = suma;
        }
    }
}

void mostrarMatrizDatos(int matrizDatos[FIL2][COL2])
{
    printf("Matriz Datos: \n");
    for(int i = 0; i < FIL2; i ++)
    {
        for(int j = 0; j < COL2; j++)
        {
            printf("%i  ",matrizDatos[i][j]);
        }
        printf("\n");
    }
}
