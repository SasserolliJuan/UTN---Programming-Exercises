#include "Arbol_De_Listas.h"

int main()
{
    nodo_arbol_lista *arbolDeListas = inicArbol();

    arbolDeListas = cargarDatosEnArbolDeListas(arbolDeListas);

    printf("Arbol de listas en orden:\n\n");
    imprimirArbolEnOrden(arbolDeListas);

    system("pause");
    return 0;
}
