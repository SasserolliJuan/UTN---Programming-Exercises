#include <stdio.h>
#include <stdlib.h>
#define FIL 5
#define COL 5

void cargarMatriz(int[FIL][COL]);
void mostrarMatriz(int[FIL][COL]);
void generarMatrizIdentidad(int[FIL][COL],int[FIL][COL]);
void mostrarMatrizIdentidad(int[FIL][COL]);


int main()
{
    int matriz[FIL][COL];
    int matrizI[FIL][COL];

    srand(time(NULL));
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    generarMatrizIdentidad(matriz,matrizI);
    mostrarMatrizIdentidad(matrizI);

}

void cargarMatriz(int matriz[FIL][COL])
{
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            matriz[i][j] = rand()%10;
            printf("Matriz[%i][%i] = %i \n",i,j,matriz[i][j]);
        }
        printf("\n");
    }
}
void mostrarMatriz(int matriz[FIL][COL])
{
    printf("Matriz 1: \n");
    for(int i = 0; i < FIL; i ++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%i  ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void generarMatrizIdentidad(int matriz[FIL][COL],int matrizI[FIL][COL])
{
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(((i+j) % 2 == 0) && i == j)
            {
                matrizI[i][j] = matriz[i][j] / matriz[i][j];
            }
            else if ((((i+j) % 2 == 1) && i != j) || ((i+j) % 2 == 0) && i != j)
            {
                matrizI[i][j] = matriz[i][j] * 0;
            }
        }
    }
}

void mostrarMatrizIdentidad(int matrizI[FIL][COL])
{
    printf("Matriz Identidad: \n");
    for(int i = 0; i < FIL; i ++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%i  ",matrizI[i][j]);
        }
        printf("\n");
    }
}
