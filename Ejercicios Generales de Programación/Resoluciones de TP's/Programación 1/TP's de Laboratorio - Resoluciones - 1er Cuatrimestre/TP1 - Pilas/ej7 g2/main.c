#include <stdio.h>
#include <stdlib.h>
#include "pila.c"

int main()
{
    int alfa=0;
    Pila origen, destino1;
    inicpila(&origen);
    inicpila(&destino1);
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
    }
    alfa=tope(&destino1);
    desapilar(&destino1);
    while (!pilavacia(&destino1))
    {
        apilar(&origen, desapilar(&destino1));
    }
    apilar(&origen, alfa);
    mostrar(&origen);
    return 0;
}
