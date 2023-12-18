#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargaDePilas(Pila*);     //Prototipado

int main()
{
    Pila A, B;            //Declaro las pilas.
    inicpila(&A);         //Inicializo las pilas.
    inicpila(&B);

    srand(time(NULL));

    cargaDePilas(&A);     //Llamo a la funci�n cargaDePilas. Uso la direcci�n de memoria de A para que losd atos cargados en la funci�n se guarden en la pila A.
    mostrar(&A);          //Muestro la pila A.
    cargaDePilas(&B);     //Llamo a la funci�n cargaDePilas. Uso la direcci�n de memoria de A para que losd atos cargados en la funci�n se guarden en la pila B.
    mostrar(&B);          //Muestro la pila B.


}

void cargaDePilas(Pila* p)    //Funci�n de tipo VOID porque no necesito que retorne nada. S�lo necesito que haga un bucle DO-WHILE.
{
    int x = 0;         //Declaro una variable de tipo INT x para asignarle el valor del l�mite de n�meros para generar elementos random.
    char continuar;    //Declaro variable de tipo CHAR para usar como condici�n en el DO-WHILE.

    printf("Hasta que numero quiere que se ingresen numeros al azar?: \n");  //Pregunto al usuario cu�l quiere que sea el l�mite.
    scanf("%i",&x);      //Ingresa el l�mite por teclado.

    do    //Ciclo DO-WHILE
    {

        apilar(p,rand()%x);                                               //Se generan n�meros random del 0 a x y se van apilando en la pila P.
        printf("Desea seguir cargando valores? s/S = Si, n = No \n");     //El usuario decide si sigue cargando valores o no.
        fflush(stdin);                                                    //Antes de asignar un valor a una variable de tipo CHAR, debo limpiar el compilador.
        scanf("%c",&continuar);                                           //Asigno la letra que se ingrese a la variable CHAR cntinuar.

    }while(continuar == 's' || continuar == 'S');     //Condici�n del DO-WHILE.
}

