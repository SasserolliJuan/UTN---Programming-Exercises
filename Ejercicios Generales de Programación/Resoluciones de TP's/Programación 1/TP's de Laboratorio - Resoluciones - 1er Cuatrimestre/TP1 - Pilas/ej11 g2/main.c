#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila modelo, dada, aux;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux);
    // empiezo a apilar
    printf("ingrese 999 para salir: \n");
    printf("MODELO:\n");
    while (tope(&modelo)>999 || tope(&modelo)<999) {
        leer(&modelo);
    }
    //quita el ultimo valor que es 999
    desapilar(&modelo);
    printf("DADA:\n");
    while (tope(&dada)>999 || tope(&dada)<999) {
        leer(&dada);
    }
    //quita el ultimo valor que es 999
    desapilar(&dada);
    mostrar(&modelo);
    mostrar(&dada);
    while (!pilavacia(&dada))
    {
        if (tope(&modelo)==tope(&dada))
        {
            desapilar(&dada);
        } else
        {
            apilar(&aux, desapilar(&dada));
        }
    }
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }
    mostrar(&dada);
    return 0;
}
