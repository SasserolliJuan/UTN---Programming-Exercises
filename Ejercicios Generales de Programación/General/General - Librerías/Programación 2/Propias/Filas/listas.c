#include "listas.h"

nodo* inicLista()
{
    return NULL;
}

nodo* crearNodo(int elemento)
{
    nodo* aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = elemento;
    aux->anterior = NULL;
    aux->siguiente = NULL;
    return aux;
}

nodo* ultimoNodo(nodo* lista)
{
    nodo* seg = lista;
    if (lista == NULL)
    {
    }
    else
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo)
{
    if (lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo* ultimo = ultimoNodo(lista);
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
    }
    return lista;
}

nodo* borrarPrimerNodo(nodo* lista)
{
    if (lista == NULL)
    {

    }
    else
    {
        if (lista->siguiente == NULL) //hay 1 solo nodo.
        {
            lista = NULL;
        }
        else //hay 2 o mas nodos.
        {
            nodo* borrar = lista;
            lista = lista->siguiente;
            lista->anterior = NULL;
            free(borrar);
        }
    }
    return lista;
}

void mostrarLista(nodo* lista)
{
    nodo* seg = lista;
    while (seg != NULL)
    {
        printf("%d\n", seg->dato);
        seg = seg->siguiente;
    }
    printf("no quedan datos restantes...\n\n");
}

