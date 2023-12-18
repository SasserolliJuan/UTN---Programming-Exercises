#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila origen, destino1, destino2;
    inicpila(&origen);
    inicpila(&destino1);
    inicpila(&destino2);
    // empiezo a apilar
    printf("ingrese 999 para salir: \n");
    while (tope(&origen)>999 || tope(&origen)<999) {
        leer(&origen);
    }
    //quita el ultimo valor que es 999
    desapilar(&origen);
    //muestra pila cargada origen
    mostrar(&origen);
    while (!pilavacia(&origen))
    {
        apilar(&destino1, desapilar(&origen));
        if (!pilavacia(&origen))
        {
        apilar(&destino2, desapilar(&origen));
        }
    }
    printf("pila jugador 1:\n");
    mostrar(&destino1);
    printf("pila jugador 2:\n");
    mostrar(&destino2);
    return 0;
}
