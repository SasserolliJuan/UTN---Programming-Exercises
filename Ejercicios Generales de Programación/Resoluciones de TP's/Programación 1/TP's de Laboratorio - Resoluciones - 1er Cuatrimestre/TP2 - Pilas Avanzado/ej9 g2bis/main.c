#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int i=0, valor=0;
    Pila aux, dada, dada2;
    inicpila(&aux);
    inicpila(&dada);
    inicpila(&dada2);
    // empiezo a apilar
    srand(time(NULL)); //PARA RESETEAR VALORES RANDOM
    valor=3+(rand() % 8);
    printf("La cantidad de elementos de la pila dada es: %i \n", valor);
    for (i=0; i<valor; i++)    // apila DADA y DADA2
    {
        leer(&dada);
        apilar(&dada2, tope(&dada));
    }
    printf("PILA DADA:\n");
    mostrar(&dada);
    printf("Evaluo si esta pila es capicua o no. \n");
    system("pause");
    while (!pilavacia(&dada2)) // apila la AUX usando la pila DADA2
    {
        apilar(&aux, desapilar(&dada2));
    }
    while ((tope(&aux)==tope(&dada)) && (!pilavacia(&dada)))
    {
        desapilar(&dada);
        desapilar(&aux);
    }
    if ((tope(&aux)!=tope(&dada)) && (!pilavacia(&dada)))
    {
        printf("La pila DADA no es capicua.");
    }
    if (pilavacia(&dada))
    {
        printf("La pila DADA es capicua.");
    }
    return 0;
}
