#include <stdio.h>
#include <stdlib.h>
#include "pila.c"


int main()
{
    int valor1=0, valor2=0, valor3=0, valor4=0, valor5=0;
    Pila origen, p1, p2;
    inicpila(&origen);
    inicpila(&p1);
    inicpila(&p2);
    // empiezo a apilar
    printf("ingrese valor a apliar del 1 al 100 en origen: ");
    scanf("%i", &valor1);
    apilar(&origen, valor1);
    printf("ingrese valor a apliar del 1 al 100 en origen: ");
    scanf("%i", &valor2);
    apilar(&origen, valor2);
    printf("ingrese valor a apliar del 1 al 100 en origen: ");
    scanf("%i", &valor3);
    apilar(&origen, valor3);
    printf("ingrese valor a apliar del 1 al 100 en origen: ");
    scanf("%i", &valor4);
    apilar(&origen, valor4);
    printf("ingrese valor a apliar del 1 al 100 en origen: ");
    scanf("%i", &valor5);
    apilar(&origen, valor5);
    //muestra pila cargada origen
    mostrar(&origen);
    //apilar las nuevas pilas
    apilar(&p1, desapilar(&origen));
    apilar(&p1, desapilar(&origen));
    apilar(&p1, desapilar(&origen));
    apilar(&p2, desapilar(&origen));
    apilar(&p2, desapilar(&origen));
    //muestra pilas p1 y p2
    mostrar(&p1);
    mostrar(&p2);
    return 0;
}
