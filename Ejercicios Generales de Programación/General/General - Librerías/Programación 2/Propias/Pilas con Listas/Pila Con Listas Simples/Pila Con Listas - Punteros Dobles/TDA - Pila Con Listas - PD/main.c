#include "Pila_Con_Listas_PD.h"

int main()
{
    nodo_lista_simple_en_pila_PD * pila;
    int dato = 0;

    inicpila(&pila);

    apilar(&pila, 10);
    apilar(&pila, 20);
    apilar(&pila, 30);

    dato = tope(&pila);
    printf("Elemento en la parte superior de la pila: %i\n", dato);

    mostrar(&pila);

    desapilar(&pila);

    dato = tope(&pila);
    printf("Elemento en la parte superior de la pila despues de desapilar: %i\n", dato);

    mostrar(&pila);

    // Liberar la memoria al finalizar
    while (!pilaVacia(&pila))
    {
        desapilar(&pila);
    }

    return 0;
}
