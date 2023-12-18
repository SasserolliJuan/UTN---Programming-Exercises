#include "st_lista_simple.h"

int main()
{
    nodo_lista_simple * aux = inic_lista_simple();
    aux = cargar_lista_simple(aux);
    mostrar_lista_simple(aux);
    return 0;
}
