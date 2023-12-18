#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 5
#define COL 5

void cargarMatriz(int[FIL][COL]);
void mostrarMatriz(int[FIL][COL]);

int main()
{
   int matriz[FIL][COL];
   srand(time(NULL));
   cargarMatriz(matriz);
   mostrarMatriz(matriz);
}

void cargarMatriz(int matriz[FIL][COL])
{
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            matriz[i][j] = rand()%10;
            printf("Matriz[%i][%i] = %i \n", i,j,matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarMatriz(int matriz[FIL][COL])
{
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%i  ", matriz[i][j]);
        }
        printf("\n");
    }
}
