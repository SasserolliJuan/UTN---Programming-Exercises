#include "libreria_listas_simples.h"

nodoEntrada *inicLista()
{
    return NULL;
}

nodoEntrada *crearNodoEntrada(stEntrada datos)
{
    nodoEntrada *aux = (nodoEntrada *)malloc(sizeof(nodoEntrada));

    aux->unaEntrada = datos;
    aux->sig = NULL;

    return aux;
}

nodoEntrada *agregarAlPpio(nodoEntrada *lista, nodoEntrada *nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->sig = lista;
        lista = nuevo;
    }
    return lista;
}

void inicFila(fila *fila)
{
    fila->primero = NULL;
    fila->ultimo = NULL;
}