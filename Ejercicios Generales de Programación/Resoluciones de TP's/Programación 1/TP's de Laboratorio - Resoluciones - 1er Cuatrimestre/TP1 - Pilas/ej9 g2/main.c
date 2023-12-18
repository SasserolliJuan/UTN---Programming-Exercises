#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila pila1, pila2;
    inicpila(&pila1);
    inicpila(&pila2);
    // empiezo a apilar
    printf("ingrese 999 para salir: \n");
    printf("PILA 1:\n");
    while (tope(&pila1)>999 || tope(&pila1)<999) {
        leer(&pila1);
    }
    //quita el ultimo valor que es 999
    desapilar(&pila1);
    printf("PILA 2:\n");
    while (tope(&pila2)>999 || tope(&pila2)<999) {
        leer(&pila2);
    }
    //quita el ultimo valor que es 999
    desapilar(&pila2);
    mostrar(&pila1);
    mostrar(&pila2);
    while (!pilavacia(&pila1) && !pilavacia(&pila2))
    {
        desapilar(&pila1);
        desapilar(&pila2);
    }
    if (pilavacia(&pila1)&&pilavacia(&pila2))
    {
        printf("Tienen igual cantidad de elementos.");
    } else
    {
        if (pilavacia(&pila1))
        {
            printf("La pila 2 tiene mayor cantidad de elementos.");
        } else
        {
            printf("La pila 1 tiene mayor cantidad de elementos.");
        }
    }
    return 0;
}
