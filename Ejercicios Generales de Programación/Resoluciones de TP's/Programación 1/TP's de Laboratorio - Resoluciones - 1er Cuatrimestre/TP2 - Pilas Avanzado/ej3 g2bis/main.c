#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila dada;
    float promedio=0, suma=0, i=0;
    inicpila(&dada);
    // empiezo a apilar
    printf("DADA:\n");
    while (tope(&dada)>9999 || tope(&dada)<9999) {
        leer(&dada);
        if (tope(&dada)>9999 || tope(&dada)<9999) {
        suma+=tope(&dada);
        i++;
        }
    }
    desapilar(&dada);
    mostrar(&dada);
    if (i>0)
    {
        promedio=suma/i;
        printf("el promedio de valores es: %.2f", promedio);
    } else
    {
        printf("no hay valores!");
    }
    return 0;
}
