#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);
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
        if (tope(&origen)==8){
            desapilar(&origen);
        } else
        {
            apilar(&destino, desapilar(&origen));
        }
    }

    //muestra pila destino
    mostrar(&destino);

    return 0;
}
