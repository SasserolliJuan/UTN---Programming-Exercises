#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila aux, aux2, aux3, aux4, dada;
    inicpila(&aux);
    inicpila(&dada);
    inicpila(&aux2);
    inicpila(&aux3);
    inicpila(&aux4);
    // empiezo a apilar
    printf("DADA:\n");
    srand(time(NULL)); //PARA RESETEAR VALORES RANDOM
    while (tope(&dada)!=12)
    {
        apilar(&dada,(rand() % 13));
    }
    mostrar(&dada);
    printf("Se procede a ordenar de menor a mayor los valores de la pila dada.\n");
    system("pause");
    apilar(&aux, desapilar(&dada));
    while (!pilavacia(&dada))
    {
        while (!pilavacia(&dada))
        {
            if (tope(&aux)>tope(&dada))
            {
                apilar(&aux2, desapilar(&aux));
                apilar(&aux, desapilar(&dada));
            } else
            {
                apilar(&aux2, desapilar(&dada));
            }
        }
        while (!pilavacia(&aux2))
        {
            apilar(&dada, desapilar(&aux2));
        }
        apilar(&aux, desapilar(&dada));
    }
    printf("Pila ordenada: \n");
    mostrar(&aux);
    apilar(&aux3, (rand() % 13));
    printf("Elemento a agregar: %i \n", tope(&aux3));
    printf("Se procede a ordenar la nueva pila... \n");
    system("pause");
    while (tope(&aux)!=tope(&aux3))
    {
        apilar(&aux4, desapilar(&aux));
    }
    apilar(&aux, tope(&aux3));
    while (!pilavacia(&aux4))
    {
        apilar(&aux, desapilar(&aux4));
    }
    printf("Pila nueva ordenada: \n");
    mostrar(&aux);
    return 0;
}
