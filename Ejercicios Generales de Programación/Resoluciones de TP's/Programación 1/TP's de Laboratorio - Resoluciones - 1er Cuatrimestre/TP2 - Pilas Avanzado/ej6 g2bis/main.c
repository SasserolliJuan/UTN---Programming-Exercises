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
    printf("Se procede a ordenar la pila de menor (base) a mayor (tope)...\n");
    system("pause");
    apilar(&aux, desapilar(&dada));
    while (!pilavacia(&dada)) //este ciclo es para que repita el colocar
    {                    //el valor minimo uno sobre el otro en pila AUX.
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
        while (!pilavacia(&aux2)) //para devolver los valores restantes a
        {                         //a la pila DADA.
            apilar(&dada, desapilar(&aux2));
        }
        apilar(&aux, desapilar(&dada));
    }
    printf("Pila ordenada de menor (base) a mayor (tope): \n");
    mostrar(&aux);
    return 0;
}
