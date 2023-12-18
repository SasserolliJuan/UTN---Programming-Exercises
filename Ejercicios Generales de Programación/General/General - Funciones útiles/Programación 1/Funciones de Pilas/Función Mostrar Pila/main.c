#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void mostrarPila(Pila*);

int main()
{
    Pila A, B;            //Declaro las pilas.
    inicpila(&A);         //Inicializo las pilas.
    inicpila(&B);

    cargaDePilas(&A);
    mostrarPila(&A);

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

void mostrarPila(Pila *a)
{
    Pila aux;
    inicpila(&aux);

    int valor=0;

    printf("\nTope");

    while(!pilavacia(a))
    {
        valor = tope(a);
        printf(" %i -", valor);
        apilar(&aux, desapilar(a));
    }

    printf("Base\n\n");
                                 //Nota: A medida que se fueron cargando los valores, cada tope se fue pasando a una pila aux. En realidad estaría mostrando la pila AUX, pero como quiero mostrar la pila A, en los printf están al revéz el TOPE y la BASE.
    while(!pilavacia(&aux))
    {
        apilar(a, desapilar(&aux));
    }
}
