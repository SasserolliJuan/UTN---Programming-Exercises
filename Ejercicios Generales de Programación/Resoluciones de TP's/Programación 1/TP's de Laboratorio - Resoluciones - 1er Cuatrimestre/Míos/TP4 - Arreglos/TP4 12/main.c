#include <stdio.h>
#include <stdlib.h>


void mostrarArreglo1(char[],int);
void mostrarArreglo2(char[],int);
void intercalarArreglos(char[],int*,char[],int,char[],int);

int main()
{
   char arreglo1[] = {'a','c','e','g','i'};
   char arreglo2[] = {'b','d','f','h','j'};
   char arreglo3[10];
   int validos1 = 7;
   int validos2 = 5;
   int validos3 = 10;

   mostrarArreglo1(arreglo1,validos1);
   printf("\n");
   mostrarArreglo2(arreglo2,validos2);
   printf("\n");
   intercalarArreglos(arreglo3,&validos1,arreglo1,validos1,arreglo2,validos2);
   mostrarArreglo3(arreglo3,validos3);
   printf("\n");

}

void mostrarArreglo1(char arreglo1[],int validos1)
{
    for(int i = 0; i < validos1; i++)
    {
        printf("%c |", arreglo1[i]);

    }
}

void mostrarArreglo2(char arreglo2[],int validos2)
{
    for(int i = 0; i < validos2; i++)
    {
        printf("%c |", arreglo2[i]);

    }
}


void intercalarArreglos(char arreglo3[], int *validos, char arreglo1[], int validos1, char arreglo2[], int validos2)
{
    int i = 0, j = 0, x = 0;
    while (i < validos1 && j < validos2)
    {
        if (arreglo1[i] < arreglo2[j])
        {
            arreglo3[x] = arreglo1[i];
            x++;
            i++;
        }
        else
        {
            arreglo3[x] = arreglo2[j];
            x++;
            j++;
        }
    }
    if (i < validos1)
    {
        arreglo3[x] = arreglo1[i];
        x++;
        i++;
    }
    if (j < validos2)
    {
        arreglo3[x] = arreglo2[j];
        x++;
        j++;
    }
    *validos = x;
}

void mostrarArreglo3(char arreglo3[],int validos3)
{
    for(int i = 0; i < validos3; i++)
    {
        printf("%c |", arreglo3[i]);
    }
}
