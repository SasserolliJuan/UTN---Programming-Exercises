#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"



//***********************************************************************************************
int main()
{
    Fila filita;
    inicFila(&filita);
    leer(&filita);
    leer(&filita);
    leer(&filita);
    leer(&filita);
    leer(&filita);
    leer(&filita);
    leer(&filita);

    int a=0;

    mostrar(&filita);

    if(!filaVacia(&filita))
        a = extraer(&filita);

    mostrar(&filita);

    return 0;
}






