#include <stdio.h>
#include <stdlib.h>
#define FIL 5
#define COL 5

void cargarMatriz(int[FIL][COL]);
void mostrarMatriz(int[FIL][COL]);
void generarMatrizTraspuesta(int[FIL][COL],int[FIL][COL]);
void mostrarMatrizTraspuesta(int[FIL][COL]);


int main()
{
    int matriz[FIL][COL];
    int matrizT[FIL][COL];

    srand(time(NULL));
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    generarMatrizTraspuesta(matriz,matrizT);
    mostrarMatrizTraspuesta(matrizT);


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

void generarMatrizTraspuesta(int matriz[FIL][COL],int matrizT[FIL][COL])
{
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            matrizT[j][i] = matriz[i][j];

        }
    }
}

void mostrarMatrizTraspuesta(int matrizT[FIL][COL])
{
    printf("Matriz T: \n");
    for(int i = 0; i < FIL; i ++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%i  ",matrizT[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
