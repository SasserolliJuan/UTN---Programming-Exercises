#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int i=0, j=0, valor=0, value=0;
    Pila dada, dada2, aux, resultado, aux2;
    inicpila(&aux);
    inicpila(&aux2);
    inicpila(&dada);
    inicpila(&dada2);
    inicpila(&resultado);
    // empiezo a apilar
    srand(time(NULL)); //PARA RESETEAR VALORES RANDOM
    valor=3+(rand() % 5); //cantidad de elementos de pila DADA
    value=3+(rand() % 5); // cantidad de elementos de pila DADA2
    printf("La cantidad de elementos de la pila DADA es: %i \n", valor);
    for (i=0; i<valor; i++)    // apila DADA
    {
        leer(&dada);
    }
    printf("PILA DADA:\n");
    mostrar(&dada);
    system("pause");
    printf("La cantidad de elementos de la pila DADA2 es: %i \n", value);
    for (j=0; j<value; j++)    // apila DADA2
    {
        leer(&dada2);
    }
    printf("PILA DADA2:\n");
    mostrar(&dada2);
    system("pause");
    while (!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
    }
    while (!pilavacia(&dada2))
    {
        apilar(&aux2, desapilar(&dada2));
    }
    while ((!pilavacia(&aux)) || (!pilavacia(&aux2)))
    {
        if (pilavacia(&aux))
        {
            apilar(&resultado, desapilar(&aux2));
        } else
        {
            if (pilavacia(&aux2))
            {
                apilar(&resultado, desapilar(&aux));
            } else
            {
                if (tope(&aux)<tope(&aux2))
                {
                    apilar(&resultado, desapilar(&aux));
                } else
                {
                    if (tope(&aux)>tope(&aux2))
                    {
                        apilar(&resultado, desapilar(&aux2));
                    } else
                    {
                        apilar(&resultado, desapilar(&aux));
                        apilar(&resultado, desapilar(&aux2));
                    }
                }
            }
        }
    }
    printf("PILA RESULTADO: \n");
    mostrar(&resultado);
    return 0;
}
