#include "Lista_De_Arboles.h"

int main()
{
    nodo_lista_arbol *lista = inicLista();
    lista = cargarDatosEnListaDeArboles(lista);
    mostrarListaDeArboles(lista);

    return 0;
}
