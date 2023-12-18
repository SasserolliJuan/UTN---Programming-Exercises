#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila limite, dada, mayor, menor;
    inicpila(&limite);
    inicpila(&dada);
    inicpila(&mayor);
    inicpila(&menor);
    // empiezo a apilar
    printf("ingrese 999 para salir: \n");
    printf("LIMITE:\n");
    while (tope(&limite)>999 || tope(&limite)<999) {
        leer(&limite);
    }
    //quita el ultimo valor que es 999
    desapilar(&limite);
    mostrar(&limite);
    printf("DADA:\n");
    while (tope(&dada)>999 || tope(&dada)<999) {
        leer(&dada);
    }
    //quita el ultimo valor que es 999
    desapilar(&dada);
    mostrar(&dada);
    while (!pilavacia(&dada))
    {
        if (tope(&limite)<=tope(&dada))
        {
            apilar(&mayor, desapilar(&dada));
        } else
        {
            apilar(&menor, desapilar(&dada));
        }
    }
    printf("pila MAYORES:\n");
    mostrar(&mayor);
    printf("pila MENORES:\n");
    mostrar(&menor);
    return 0;
}
