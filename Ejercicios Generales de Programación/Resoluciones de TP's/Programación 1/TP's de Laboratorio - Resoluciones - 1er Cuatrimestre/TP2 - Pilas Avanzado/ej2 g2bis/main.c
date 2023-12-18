#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila dada;
    int i=0;
    inicpila(&dada);
    char caracter='s';
    // empiezo a apilar
    printf("DADA:\n");
    while (caracter=='s') {
        leer(&dada);
        i++;
        printf("otro valor? s/n: \n");
        fflush(stdin);
        scanf("%c", &caracter);
    }
    mostrar(&dada);
    printf("la cantidad de valores apilados es: %i \n", i);
    return 0;
}
