#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int i=0, valor=0;
    Pila dada, aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);
    inicpila(&dada);
    // empiezo a apilar
    srand(time(NULL)); //PARA RESETEAR VALORES RANDOM
    valor=3+(rand() % 10); //cantidad de elementos de pila DADA
    printf("La cantidad de elementos de la pila DADA es: %i \n", valor);
    for (i=0; i<valor; i++)    // apila DADA
    {
        apilar(&dada, (rand() % 20));
    }
    printf("PILA DADA:\n");
    mostrar(&dada);
    system("pause");
    apilar(&aux, desapilar(&dada));     // Mueve el elemento del tope de DADA para comparar con el siguiente.
    while (!pilavacia(&dada))
    {
        if (tope(&dada)<=tope(&aux))    //Apila si el elemento siguiente es menor o igual al de arriba.
        {
            apilar(&aux, desapilar(&dada));
        } else
        {
            while (tope(&dada)>tope(&aux))  //Si es mayor al tope de aux, busca el lugar que le corresponde dentro de AUX.
            {
                apilar(&aux2, desapilar(&aux)); //Para hacerlo, va desapilando AUX dentro de AUX2.
            }
            apilar(&aux, desapilar(&dada)); //Encuentra su lugar y se apila en AUX.
            while (!pilavacia(&aux2))       //Devuelve los restantes valores a la pila AUX.
            {
                apilar(&aux, desapilar(&aux2));
            }
        }
    }               // Continua hasta que se vacia la pila DADA.
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux)); //Ordena de forma ascendente desde la base, y devuelve a la pila de origen a la vez.
    }
    printf("PILA ORDENADA POR INSERCION:\n");
    mostrar(&dada);
    return 0;
}
