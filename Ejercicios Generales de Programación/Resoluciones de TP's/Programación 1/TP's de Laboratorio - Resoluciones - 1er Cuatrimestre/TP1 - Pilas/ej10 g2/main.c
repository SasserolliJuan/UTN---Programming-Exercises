#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila p1, p2, aux1, aux2;
    inicpila(&p1);
    inicpila(&p2);
    inicpila(&aux1);
    inicpila(&aux2);
    // empiezo a apilar PILA 1
    printf("ingrese 9999 para salir: \n");
    printf("PILA 1: \n");
    while (tope(&p1)>9999 || tope(&p1)<9999) {
        leer(&p1);
    }
    desapilar(&p1);
    // empiezo a apilar PILA 2
    printf("PILA 2: \n");
    while (tope(&p2)>9999 || tope(&p2)<9999) {
        leer(&p2);
    }
    desapilar(&p2);
    printf("muestra pila 1:");
    mostrar(&p1);
    printf("muestra pila 2:");
    mostrar(&p2);
    //pasar a pilas auxiliares
    while (!pilavacia(&p1))
    {
        apilar(&aux1,desapilar(&p1));
    }
    while (!pilavacia(&p2))
    {
        apilar(&aux2,desapilar(&p2));
    }
    // COMPARACIONES
    while (!pilavacia(&aux1) && !pilavacia(&aux2))
    {
            printf("elemento de pila 1 a mostrar: %i \n", tope(&aux1));
            printf("elemento de pila 2 a mostrar: %i \n", tope(&aux2));
            if (tope(&aux1)==tope(&aux2))
            {
                printf("Son iguales\n");
            } else
            {
                printf("Son distintos\n");
            }
            desapilar(&aux1);
            desapilar(&aux2);
    }
    if (pilavacia(&aux1) && pilavacia(&aux2))
    {
        printf("Tienen igual cantidad de elementos. \n");
    } else
    {
        if (pilavacia(&aux1))
        {
            printf("La pila 1 tiene menor cantidad de elementos que la pila 2. \n");
        } else
        {
            if (pilavacia(&aux2))
            {
                printf("La pila 2 tiene menor cantidad de elementos que la pila 1. \n");
            } else
            {
                printf("error");
            }
        }
    }
    return 0;
}
