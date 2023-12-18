#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);
    printf("ingrese 999 para salir: \n");
    printf("ORIGEN:\n");
    while (tope(&origen)>999 || tope(&origen)<999) {
        leer(&origen);
    }
    //quita el ultimo valor que es 999
    desapilar(&origen);
    mostrar(&origen);
    if (!pilavacia(&origen))
    {
        while (!(tope(&origen)==5))
        {
            apilar(&destino, desapilar(&origen));
        }
        printf("DESTINO:\n");
        mostrar(&destino);
    }
    return 0;
}
