#include "Pila_Con_Listas_Dobles_PD.h"

int main()
{
    Pila *miPila;
    inicpila(&miPila);

    leer(&miPila);
    leer(&miPila);
    leer(&miPila);

    printf("Elementos apilados:\n");
    mostrar(&miPila);

    printf("Desapilando elementos:\n");

    while (!pilavacia(&miPila))
    {
        int valor = desapilar(&miPila);
        printf("%i\n", valor);
    }

    mostrar(&miPila);
    printf("Pila Vacia \n");

    return 0;
}
