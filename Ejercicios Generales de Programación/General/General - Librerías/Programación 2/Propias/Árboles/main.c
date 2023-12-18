#include <stdio.h>
#include <stdlib.h>
#include "st_arbol.h"

nodo_arbol * arbol;

int main()
{
    arbol = inic_arbol();
    arbol = cargar_arbol(arbol);
    inOrder(arbol);
    return 0;
}
