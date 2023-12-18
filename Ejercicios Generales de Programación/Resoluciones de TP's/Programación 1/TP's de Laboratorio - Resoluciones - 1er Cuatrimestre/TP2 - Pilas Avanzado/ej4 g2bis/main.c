#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila aux, dada, aux2;
    inicpila(&aux);
    inicpila(&dada);
    inicpila(&aux2);
    // empiezo a apilar
    printf("ingrese 999 para salir: \n");
    printf("DADA:\n");
    while (tope(&dada)!=999) {
        leer(&dada);
    }
    //quita el ultimo valor que es 999
    desapilar(&dada);
    mostrar(&dada);
    printf("Se procede a calcular el elemento minimo en la pila dada...\n");
    system("pause");
    apilar(&aux, desapilar(&dada));
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
    printf("El minimo valor, que fue almacenado en la pila aux es: \n");
    mostrar(&aux);
    return 0;
}
