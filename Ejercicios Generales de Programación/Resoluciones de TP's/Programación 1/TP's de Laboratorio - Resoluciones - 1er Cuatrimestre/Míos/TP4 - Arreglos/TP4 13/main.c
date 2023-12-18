#include <stdio.h>
#include <stdlib.h>

void mostrarArreglo(int[],int);
void sumaElementos(int[],int);

int main()
{
   int arreglo[] = {1,5,6,7,8};
   int validos = 5;

   sumaElementos(arreglo,validos);
   mostrarArreglo(arreglo,validos);
}

void mostrarArreglo(int arreglo[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%i", arreglo[i]);
        printf("\n");
    }
}

void sumaElementos(int arreglo[],int validos)
{
    int suma = 0;
    for(int i = 0; i < validos; i++)
    {
        arreglo[i] = arreglo[i] + arreglo[i - 1];
    }
}
