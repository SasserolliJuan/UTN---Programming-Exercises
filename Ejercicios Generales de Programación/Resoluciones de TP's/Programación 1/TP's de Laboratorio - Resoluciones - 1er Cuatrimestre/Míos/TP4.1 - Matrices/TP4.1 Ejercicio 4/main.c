#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 2
#define COL 2

void cargarMatriz(int[FIL][COL]);
int sumaMatriz(int[FIL][COL]);
void mostrarMatriz(int[FIL][COL]);


int main()
{
    int matriz[FIL][COL];
    int suma = 0;
    srand(time(NULL));
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    suma = sumaMatriz(matriz);
    printf("\nLa suma total de los elementos de la matriz es: %i  ", suma);

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
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%i  ", matriz[i][j]);
        }
        printf("\n");
    }
}

int sumaMatriz(int matriz[FIL][COL])
{
    int suma = 0;
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            suma += matriz[i][j];
        }
    }
    return suma;
}
