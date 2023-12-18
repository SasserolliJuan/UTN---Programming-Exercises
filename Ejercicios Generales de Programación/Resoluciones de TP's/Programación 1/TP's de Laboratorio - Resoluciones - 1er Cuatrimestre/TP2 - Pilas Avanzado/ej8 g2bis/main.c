#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int i=0, j=0, numerox=0, valor=0, valor1=0;
    Pila aux, dada, aux2;
    inicpila(&aux);
    inicpila(&dada);
    inicpila(&aux2);
    // empiezo a apilar
    srand(time(NULL)); //PARA RESETEAR VALORES RANDOM
    for (i=0; i<20; i++)
    {
        apilar(&dada,(rand() % 100));
    }
    printf("PILA DADA:\n");
    mostrar(&dada);
    valor=(rand() % 21);
    valor1=21-valor;
    system("pause");
    printf("Se elimina el elemento %i desde la base.\n", valor1);
    system("pause");
    while (numerox==0)
    {
        j++;
        if (j==valor)
        {
            apilar(&aux2, desapilar(&dada));
            numerox=1; //flag
        } else
        {
            apilar(&aux, desapilar(&dada));
        }
    }
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }
    printf("PILA DADA sin elemento seleccionado:\n");
    mostrar(&dada);
    return 0;
}
