#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 2
#define COL 2

void cargarMatriz(int[FIL][COL]);
int sumaMatriz(int[FIL][COL]);
int cantMatriz(int[FIL][COL]);
void mostrarMatriz(int[FIL][COL]);
float promedioMatriz(int[FIL][COL],int,int);


int main()
{
    int matriz[FIL][COL];
    int suma = 0;
    int cant = 0;
    float promedio = 0;
    srand(time(NULL));
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    suma = sumaMatriz(matriz);
    cant = cantMatriz(matriz);
    promedio = promedioMatriz(matriz,suma,cant);
    printf("\nEl promedio de los valores de la matriz es de: %f", promedio);

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

int cantMatriz(int matriz[FIL][COL])
{
    int cant = 0;

    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            cant++;
        }
    }
    return cant;
}

float promedioMatriz(int matriz[FIL][COL],int suma, int cant)
{
    float promedio;
    promedio = (float) suma / cant;
    return promedio;
}
