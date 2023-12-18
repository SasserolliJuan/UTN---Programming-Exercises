#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 2
#define COL 2

void cargarMatriz(int[FIL][COL]);
void mostrarMatriz(int[FIL][COL]);
int buscarDato(int[FIL][COL],int);


int main()
{
    int matriz[FIL][COL];
    srand(time(NULL));
    int dato = rand()%10;
    int validacion = 0;
    printf("El dato a buscar es: %i \n", dato);
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    validacion = buscarDato(matriz,dato);
    if(validacion == 1)
    {
        printf("Se ha encontrado el dato en la matriz. \n");
    }
    else
    {
        printf("No se ha encontrado el dato en la matriz. \n");
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
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%i  ", matriz[i][j]);
        }
        printf("\n");
    }
}

int buscarDato(int matriz[FIL][COL],int dato)
{
    int validacion = 0;
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(matriz[i][j] == dato)
            {
                validacion = 1;
            }
        }
    }

    return validacion;
}
