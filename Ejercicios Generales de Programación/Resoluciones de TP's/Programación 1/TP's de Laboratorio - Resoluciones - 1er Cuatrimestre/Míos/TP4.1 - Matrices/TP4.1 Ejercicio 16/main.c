#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 2
#define COL 2

void cargarMatriz(int[FIL][COL]);
void mostrarMatriz(int[FIL][COL]);
int comparacionMatrices(int[FIL][COL]);


int main()
{
    int matriz[FIL][COL];
    int validacion = 0;
    srand(time(NULL));
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    validacion = comparacionMatrices(matriz);
    if(validacion == 1)
    {
        printf("La matriz es simetrica. \n");
    }
    else
    {
        printf("La matriz no es simetrica. \n");
    }

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
    for(int i = 0; i < FIL; i ++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%i  ",matriz[i][j]);
        }
        printf("\n");
    }
}


int comparacionMatrices(int matriz[FIL][COL])
{
    int validacion = 0;
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(matriz[i+1][j] == matriz[i][j+1])
            {
                validacion = 1;
            }
        }
    }
    return validacion;
}
