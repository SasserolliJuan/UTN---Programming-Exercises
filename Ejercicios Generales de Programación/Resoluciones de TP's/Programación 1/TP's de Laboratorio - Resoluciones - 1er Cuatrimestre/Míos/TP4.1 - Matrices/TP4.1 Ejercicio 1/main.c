#include <stdio.h>
#include <stdlib.h>
#define FIL 5
#define COL 5

void cargarMatriz(int[][COL]);

int main()
{
    int matriz[FIL][COL];
    cargarMatriz(matriz);
}

void cargarMatriz(int matriz[FIL][COL])
{


    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("Matriz[%i%][i] = \n",i,j),
            scanf("%i", &matriz[i][j]);
        }
        printf("\n");
    }
}
