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
    //apilar las nuevas pilas
    while (!pilavacia(&origen))
    {
        apilar(&destino1, desapilar(&origen));
    }
    while (!pilavacia(&destino1))
    {
        apilar(&destino2, desapilar(&destino1));
    }
    //muestra pila destino

    int dato = tope(&destino2);
    printf("%i", dato);
    mostrar(&destino2);

    return 0;
}
