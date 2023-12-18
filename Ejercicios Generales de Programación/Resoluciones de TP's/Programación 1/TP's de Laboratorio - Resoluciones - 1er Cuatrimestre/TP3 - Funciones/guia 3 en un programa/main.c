#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

    int suma (Pila);
    int contador (Pila);
    float divide (int,int);

int main()
{
    Pila dada;
    inicpila(&dada);
    srand(time(NULL));
    //funcion1(&dada); //Se usa en las funciones hasta la 9 inclusive (solo en la 10 no usar).
    //mostrar(&dada);  //Parte de la funcion 1.
    //funcion2(&dada);
    //funcion3(&dada);
    //funcion4(&dada);
    //funcion5(&dada);
    //funcion6(&dada);
    //funcion7(&dada);
    //funcion8(&dada);
    //funcion9(&dada);
    funcion10(&dada);
    return 0;
}

void funcion1(Pila *aux1)
{
    int i=0, elementos=0;
    printf("ingrese cantidad de elementos a apilar:\n");
    scanf("%i", &elementos);
    for (i=0; i<elementos; i++)
    {
        apilar(&*aux1, (rand() % 1000));
    }
}

void funcion2(Pila *aux2)
{
    Pila aux22;
    inicpila(&aux22);
    while (!pilavacia(&*aux2))
    {
        apilar(&aux22, desapilar(&*aux2));
    }
    mostrar(&aux22);
}

void funcion3(Pila *aux3)
{
    Pila aux33, aux333;
    inicpila(&aux33);
    inicpila(&aux333);
    while (!pilavacia(&*aux3))
    {
        apilar(&aux33, desapilar(&*aux3));
    }
    while (!pilavacia(&aux33))
    {
        apilar(&aux333, desapilar(&aux33));
    }
    mostrar(&aux333);
}

void funcion4(Pila *aux4)
{
    Pila aux44, aux444;
    inicpila(&aux44);
    inicpila(&aux444);
    apilar(&aux44, desapilar(&*aux4));
    while (!pilavacia(&*aux4))
    {
        if (tope(&aux44)>tope(&*aux4))
        {
            apilar(&aux444, desapilar(&aux44));
            apilar(&aux44, desapilar(&*aux4));
        } else
        {
            apilar(&aux444, desapilar(&*aux4));
        }
    }
    while (!pilavacia(&aux444))
    {
        apilar(&*aux4, desapilar(&aux444));
    }
    printf("El minimo valor, que fue eliminado de la pila dada es: \n");
    mostrar(&aux44);
}

void funcion5(Pila *aux5)
{
    Pila aux55, aux555;
    inicpila(&aux55);
    inicpila(&aux555);
    apilar(&aux55, desapilar(&*aux5));
    while (!pilavacia(&*aux5))
    {
        while (!pilavacia(&*aux5))
        {
            if (tope(&aux55)>tope(&*aux5))
            {
                apilar(&aux555, desapilar(&aux55));
                apilar(&aux55, desapilar(&*aux5));
            } else
            {
                apilar(&aux555, desapilar(&*aux5));
            }
        }
        while (!pilavacia(&aux555))
        {
            apilar(&*aux5, desapilar(&aux555));
        }
        apilar(&aux55, desapilar(&*aux5));
    }
    while (!pilavacia(&aux55))
    {
        apilar(&aux555, desapilar(&aux55));
    }
    while (!pilavacia(&aux555))
    {
        apilar(&*aux5, desapilar(&aux555));
    }
    printf("pila ordenada: \n");
    mostrar(&*aux5);
}

void funcion6(Pila *aux6)
{
    Pila aux66, aux666;
    inicpila(&aux66);
    inicpila(&aux666);
    printf("ingrese elemento nuevo a insertar:\n");
    leer(&aux666);
    while (tope(&*aux6)>tope(&aux666))
    {
        apilar(&aux66, desapilar(&*aux6));
    }
    apilar(&*aux6, desapilar(&aux666));
    while (!pilavacia(&aux66))
    {
        apilar(&*aux6, desapilar(&aux66));
    }
    printf("Pila nueva ordenada: \n");
    mostrar(&*aux6);
}

void funcion7(Pila *aux7)
{
    Pila aux77, aux777;
    inicpila(&aux77);
    inicpila(&aux777);
    apilar(&aux77, desapilar(&*aux7));     // Mueve el elemento del tope de DADA para comparar con el siguiente.
    while (!pilavacia(&*aux7))
    {
        if (tope(&*aux7)<=tope(&aux77))    //Apila si el elemento siguiente es menor o igual al de arriba.
        {
            apilar(&aux77, desapilar(&*aux7));
        } else
        {
            while (tope(&*aux7)>tope(&aux77))  //Si es mayor al tope de aux, busca el lugar que le corresponde dentro de AUX.
            {
                apilar(&aux777, desapilar(&aux77)); //Para hacerlo, va desapilando AUX dentro de AUX2.
            }
            apilar(&aux77, desapilar(&*aux7)); //Encuentra su lugar y se apila en AUX.
            while (!pilavacia(&aux777))       //Devuelve los restantes valores a la pila AUX.
            {
                apilar(&aux77, desapilar(&aux777));
            }
        }
    }               // Continua hasta que se vacia la pila DADA.
    while (!pilavacia(&aux77))
    {
        apilar(&*aux7, desapilar(&aux77)); //Ordena de forma ascendente desde la base, y devuelve a la pila de origen a la vez.
    }
    system("pause");
    printf("Pila ordenada por insercion:\n");
    mostrar(&*aux7);
}

void funcion8(Pila *aux8)
{
    int a=0, b=0, suma=0;
    Pila aux88;
    inicpila(&aux88);
    a=tope(&*aux8);
    apilar(&aux88, desapilar(&*aux8));
    b=tope(&*aux8);
    apilar(&*aux8, desapilar(&aux88));
    suma=a+b;
    printf("elemento de tope: %i \n", a);
    printf("elemento anterior: %i \n", b);
    printf("suma de ambos: %i \n", suma);
}

void funcion9(Pila *aux9)
{
    int sum=0, cont=0;
    float divi=0;
    sum=suma(*aux9);
    cont=contador(*aux9);
    divi=divide(sum, cont);
    printf("La suma de los valores da: %i \n", sum);
    printf("La cantidad de valores da: %i \n", cont);
    printf("El promedio de los valores da: %.2f \n", divi);
}

int suma (Pila ss)
{
    int sumaa=0;
    while (!pilavacia(&ss))
    {
        sumaa=sumaa+tope(&ss);
        desapilar(&ss);
    }
    return sumaa;
}

int contador (Pila cc)
{
    int i=0;
    while (!pilavacia(&cc))
    {
        i++;
        desapilar(&cc);
    }
    return i;
}

float divide (int sum, int cont)
{
    float div=0;
    if (cont>0)
    {
        div= (float) sum/cont;
    } else
    {
        div=0;
        printf("no hay valores a promediar \n");
    }
    return div;
}

void funcion10(Pila *aux10)
{
    int i=0, elementos=10, suma=0;
    printf("ingrese cantidad de elementos a apilar:\n");
    scanf("%i", &elementos);
    for (i=0; i<elementos; i++)
    {
        apilar(&*aux10, (rand() % 10));
    }
    mostrar(&*aux10);
    while (!pilavacia(&*aux10))
    {
        suma=tope(&*aux10)*10;
        desapilar(&*aux10);

    }
    printf("La pila escrita en decimal da: %i \n", suma);
}
