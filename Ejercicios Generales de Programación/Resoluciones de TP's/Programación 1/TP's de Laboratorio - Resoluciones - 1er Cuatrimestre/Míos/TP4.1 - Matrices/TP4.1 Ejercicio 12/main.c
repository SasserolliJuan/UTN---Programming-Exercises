#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 2
#define COL 2

void cargarMatriz(int[FIL][COL]);
void mostrarMatriz(int[FIL][COL]);
int calculoDet(int[FIL][COL]);
void verificacionInversa(int[FIL][COL],int);

int main()
{
    int matriz[FIL][COL];
    int det = 0;
    srand(time(NULL));

    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    det = calculoDet(matriz);
    printf("La determinante de la matriz es: %i \n", det);
    verificacionInversa(matriz,det);
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

int calculoDet(int matriz[FIL][COL])
{
    int i = 0, j = 0;
    int res1 = 0, res2 = 0, calc = 0;
    int dato1 = 0, dato2 = 0, dato3 = 0, dato4 = 0;

    for(i = 0; i < FIL; i++)
    {
        for(j = 0; j < COL; j++)
        {
            if(i == 0 && j == 0)
            {
                dato1 = matriz[i][j];
        }
        else if(i == 0 && j == 1)
        {
            dato2 = matriz[i][j];
        }
        else if(i == 1 && j == 0)
        {
            dato3 = matriz[i][j];
        }
        else if(i == 1 && j == 1)
        {
            dato4 = matriz[i][j];
        }
    }
    res1 = dato1 * dato4;
    res2 = dato2 * dato3;
    calc = res1 - res2;
}

    return calc;
}

void verificacionInversa(int matriz[FIL][COL],int det)
{
    if(det != 0)
    {
        printf("La matriz tiene inversa. \n");
    }
    else if(det == 0)
    {
        printf("La matriz no tiene inversa. \n");
    }
}
