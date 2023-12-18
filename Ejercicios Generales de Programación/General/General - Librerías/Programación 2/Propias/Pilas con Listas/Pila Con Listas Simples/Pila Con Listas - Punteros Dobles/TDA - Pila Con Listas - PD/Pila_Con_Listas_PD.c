#include"Pila_Con_Listas_PD.h"

void inicpila(nodo_lista_simple_en_pila_PD ** pila)
{
    *pila = NULL;
}

int pilaVacia(nodo_lista_simple_en_pila_PD ** pila)
{
    return *pila == NULL;
}

void apilar(nodo_lista_simple_en_pila_PD ** pila, int dato)
{
    nodo_lista_simple_en_pila_PD *nuevoNodo = (nodo_lista_simple_en_pila_PD *)malloc(sizeof(nodo_lista_simple_en_pila_PD));

    if (nuevoNodo == NULL)
    {
        printf("Error: no se pudo asignar memoria para el nuevo nodo. \n");

    }

    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

int desapilar(nodo_lista_simple_en_pila_PD ** pila)
{
    if (pilaVacia(pila))
    {
        printf("Error: la pila está vacía. \n");
    }

    int valor = (*pila)->dato;

    nodo_lista_simple_en_pila_PD * temp = *pila;
    *pila = (*pila)->siguiente;

    free(temp);

    return valor;
}

int tope(nodo_lista_simple_en_pila_PD ** pila)
{
    if (pilaVacia(pila))
    {
        printf("Error: la pila está vacía. \n");
    }

    return (*pila)->dato;
}

void mostrar(nodo_lista_simple_en_pila_PD ** pila)
{
    nodo_lista_simple_en_pila_PD * temp = *pila;

    printf("Contenido de la pila: \n");

    while (temp != NULL)
    {
        printf("%i \n", temp->dato);
        temp = temp->siguiente;
    }
}

