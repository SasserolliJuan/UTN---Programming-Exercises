#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int i=0, j=0, valor=0, value=0;
    Pila uni0n, dada, dada2, aux, basura;
    inicpila(&uni0n);
    inicpila(&aux);
    inicpila(&dada);
    inicpila(&dada2);
    inicpila(&basura);
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
    apilar(&uni0n, desapilar(&dada2));
    while ((!pilavacia(&dada)) || (!pilavacia(&dada2)))
    {
        if ((!pilavacia(&dada)) && (!pilavacia(&dada2)))  //si ambas pilas tienen elementos todavia
        {
            while ((tope(&dada)!=tope(&uni0n)) && (!pilavacia(&uni0n)))
            {
                apilar(&aux, desapilar(&uni0n));
            }
            if (pilavacia(&uni0n))
            {
                while (!pilavacia(&aux))
                {
                    apilar(&uni0n, desapilar(&aux));
                }
                apilar(&uni0n, desapilar(&dada));
            } else
            {
                while (!pilavacia(&aux))
                {
                    apilar(&uni0n, desapilar(&aux));
                }
                apilar(&basura, desapilar(&dada));
            } ///////
            while ((tope(&dada2)!=tope(&uni0n)) && (!pilavacia(&uni0n)))
            {
                apilar(&aux, desapilar(&uni0n));
            }
            if (pilavacia(&uni0n))
            {
                while (!pilavacia(&aux))
                {
                    apilar(&uni0n, desapilar(&aux));
                }
                apilar(&uni0n, desapilar(&dada2));
            } else
            {
                while (!pilavacia(&aux))
                {
                    apilar(&uni0n, desapilar(&aux));
                }
                apilar(&basura, desapilar(&dada2));
            }
        } else
        {
            if (pilavacia(&dada2))  //si solo quedan elementos de la pila dada
            {
                while ((tope(&dada)!=tope(&uni0n)) && (!pilavacia(&uni0n)))
                {
                    apilar(&aux, desapilar(&uni0n));
                }
                if (pilavacia(&uni0n))
                {
                    while (!pilavacia(&aux))
                    {
                        apilar(&uni0n, desapilar(&aux));
                    }
                    apilar(&uni0n, desapilar(&dada));
                } else
                {
                    while (!pilavacia(&aux))
                    {
                        apilar(&uni0n, desapilar(&aux));
                    }
                    apilar(&basura, desapilar(&dada));
                }
            } else
            {
                if (pilavacia(&dada))  //si solo quedan elementos de la pila dada2
                {
                    while ((tope(&dada2)!=tope(&uni0n)) && (!pilavacia(&uni0n)))
                    {
                        apilar(&aux, desapilar(&uni0n));
                    }
                    if (pilavacia(&uni0n))
                    {
                        while (!pilavacia(&aux))
                        {
                            apilar(&uni0n, desapilar(&aux));
                        }
                        apilar(&uni0n, desapilar(&dada2));
                    } else
                    {
                        while (!pilavacia(&aux))
                        {
                            apilar(&uni0n, desapilar(&aux));
                        }
                        apilar(&basura, desapilar(&dada2));
                    }
                }
            }
        }
    }
    printf("La pila union queda: \n");
    mostrar(&uni0n);
    return 0;
}
