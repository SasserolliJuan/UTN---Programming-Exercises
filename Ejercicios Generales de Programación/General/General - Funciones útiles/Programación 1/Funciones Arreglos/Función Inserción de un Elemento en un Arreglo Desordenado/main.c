#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void InsercionDesordenado(char arreglo[], int *validos, char letra)
{
    arreglo[*validos] = letra;
    (*validos)++;
}

