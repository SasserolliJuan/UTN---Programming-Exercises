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
    while (numerox!=1)
    {
        while (!pilavacia(&dada))
        {
            if (valor==tope(&dada))
            {
                if (numerox!=1)
                {
                    printf("El elemento buscado se encuentra en la pila.\n");
                    numerox=1; // SWITCH PARA CORTAR EL PROGRAMA
                }
                apilar(&aux, desapilar(&dada));
            } else
            {
                apilar(&aux, desapilar(&dada));
            }
        }
        if (numerox!=1)
        {
            printf("El elemento buscado NO esta en la pila.\n");
            printf("Ingrese otro valor a buscar (del 0 al 20):\n");
            scanf("%i", &valor);
        }
        while (!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }
    }
    printf("PILA DADA:\n");
    mostrar(&dada);

    return 0;
}
