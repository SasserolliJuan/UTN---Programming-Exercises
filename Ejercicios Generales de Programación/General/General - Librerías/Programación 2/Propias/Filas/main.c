#include "filas.h"

int main()
{
    fila filinha;
    inicFila(&filinha);
    agregarFila(&filinha, 4);
    extraerFila(&filinha);
    mostrarFila(filinha);
    int tope = primeroFila(filinha);

    return 0;
}
