#include "Fila_Con_Listas_Dobles.h"

int main()
{
    Fila miFila;
    inicFila(&miFila);

    agregar(&miFila, 1);
    agregar(&miFila, 2);
    agregar(&miFila, 3);

    printf("Elementos de la fila:\n");
    mostrar_fila(&miFila);

    int elementoExtraido = extraer(&miFila);
    printf("Elemento extraido: %i\n", elementoExtraido);

    printf("Elementos de la fila despues de extraer:\n");
    mostrar_fila(&miFila);

    system("pause");

    return 0;
}
