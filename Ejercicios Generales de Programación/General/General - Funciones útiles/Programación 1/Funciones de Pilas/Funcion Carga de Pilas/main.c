#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargaDePilas(Pila*);     //Prototipado

int main()
{
    Pila A, B;            //Declaro las pilas.
    inicpila(&A);         //Inicializo las pilas.
    inicpila(&B);

    cargaDePilas(&A);     //Llamo a la función cargaDePilas. Uso la dirección de memoria de A para que losd atos cargados en la función se guarden en la pila A.
    mostrar(&A);          //Muestro la pila A.
    cargaDePilas(&B);     //Llamo a la función cargaDePilas. Uso la dirección de memoria de A para que losd atos cargados en la función se guarden en la pila B.
    mostrar(&B);          //Muestro la pila B.


}

void cargaDePilas(Pila* p)    //Función de tipo VOID porque no necesito que retorne nada. Sólo necesito que haga un bucle DO-WHILE.
{
    char continuar;    //Declaro variable de tipo CHAR para usar como condición en el DO-WHILE.

    do    //Ciclo DO-WHILE
    {
        leer(p);                                                          //Ingreso por teclado los valores.
        printf("Desea seguir cargando valores? s/S = Si, n = No \n");     //El usuario decide si sigue cargando valores o no.
        fflush(stdin);                                                    //Antes de asignar un valor a una variable de tipo CHAR, debo limpiar el compilador.
        scanf("%c",&continuar);                                           //Asigno la letra que se ingrese a la variable CHAR cntinuar.

    }while(continuar == 's' || continuar == 'S');     //Condición del DO-WHILE.
}

