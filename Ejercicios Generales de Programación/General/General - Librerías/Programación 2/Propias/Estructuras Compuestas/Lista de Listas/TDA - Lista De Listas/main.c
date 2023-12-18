#include "Lista_De_Listas.h"

int main()
{
    nodo_lista_simple_principal *listaCajaClientes = inicListaCaja();
    listaCajaClientes = ingresarCajas(listaCajaClientes);
    recorrerYmostrarCajasClientes(listaCajaClientes);

    return 0;
}
