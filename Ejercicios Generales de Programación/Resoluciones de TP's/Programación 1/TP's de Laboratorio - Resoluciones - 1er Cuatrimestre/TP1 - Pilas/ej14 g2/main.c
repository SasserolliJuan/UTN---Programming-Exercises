#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila aux, dada, par, impar;
    inicpila(&aux);
    inicpila(&dada);
    inicpila(&par);
    inicpila(&impar);
    // empiezo a apilar
    printf("ingrese 999 para salir: \n");
    printf("DADA:\n");
    while (tope(&dada)>999 || tope(&dada)<999) {
        leer(&dada);
    }
    //quita el ultimo valor que es 999
    desapilar(&dada);
    mostrar(&dada);
    while (!pilavacia(&dada))
    {
        //cargas 1 valor a la pila auxiliar mientras descargas la DADA
        apilar(&aux, desapilar(&dada));
        if (pilavacia(&dada))
        {
            printf("es impar. \n");
            apilar(&impar, desapilar(&aux));
        } else
        {
            apilar(&aux, desapilar(&dada));
            if (pilavacia(&dada))
            {
                printf("es par. \n");
                apilar(&par, desapilar(&aux));
            }
        }
    }
    if (!pilavacia(&impar))
    {
        printf("pila impar:\n");
        mostrar(&impar);
    }
    if (!pilavacia(&par))
    {
        printf("pila par:\n");
        mostrar(&par);
    }
    return 0;
}
