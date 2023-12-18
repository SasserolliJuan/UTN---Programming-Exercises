#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int i=0, numerox=0, valor=0;
    Pila aux, dada;
    inicpila(&aux);
    inicpila(&dada);
    // empiezo a apilar
    srand(time(NULL)); //PARA RESETEAR VALORES RANDOM
    for (i=0; i<20; i++)
    {
        apilar(&dada,(rand() % 21));
    }
    printf("Ingrese numero a buscar en la pila cargada (del 0 al 20):\n");
    scanf("%i", &valor);
    while (numerox==0)
    {
        if (valor==tope(&dada))
        {
            numerox=1;
            printf("El numero buscado se encuentra en la pila DADA.\n");
        } else
        {
            apilar(&aux, desapilar(&dada));
            if (pilavacia(&dada))
            {
                numerox=1;
                printf("El numero buscado no se encuentra en la pila.\n");
            }
        }
    }
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
        }
    printf("PILA DADA:\n");
    mostrar(&dada);
    return 0;
}
