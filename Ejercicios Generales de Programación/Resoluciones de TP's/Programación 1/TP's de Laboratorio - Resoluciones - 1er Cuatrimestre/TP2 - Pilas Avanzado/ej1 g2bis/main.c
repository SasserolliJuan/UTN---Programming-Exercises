#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila dada;
    int suma=0;
    inicpila(&dada);
    char caracter='s';
    // empiezo a apilar
    printf("DADA:\n");
    while (caracter=='s') {
        leer(&dada);
        suma+=tope(&dada);
        printf("otro valor? s/n: \n");
        fflush(stdin);
        scanf("%c", &caracter);
    }
    mostrar(&dada);
    printf("la suma de los valores apilados es: %i \n", suma);
    return 0;
}
