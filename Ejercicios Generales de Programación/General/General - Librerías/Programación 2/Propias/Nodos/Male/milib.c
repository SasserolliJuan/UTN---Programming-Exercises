#include "stdio.h"
#include "stdlib.h"
#include "milib.h"

nodo *inicLista()
{
    return NULL;
}
nodo *crearNodo(int dato)
{
    nodo *aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente=NULL;
    return aux;
}
nodo *agregarPpio(nodo *lista, nodo *nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }else
    {
        nuevoNodo->siguiente =lista;
        lista=nuevoNodo;
    }
    return lista;
}
void mostrarLista(nodo *lista)
{
    nodo * seguir = lista;
    while(seguir != NULL)
    {
        printf("%d\n", seguir->dato);
        seguir = seguir ->siguiente;
    }
}
nodo *agregarOrden(nodo *lista, nodo *nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }else if(lista->dato > nuevoNodo->dato)
    {
        lista = agregarPpio(lista, nuevoNodo);
    }else
    {
        nodo *seguidora = lista;
        nodo *anterior = lista;
        while((seguidora != NULL)&& (seguidora->dato < nuevoNodo->dato))
        {
            anterior = seguidora;
            seguidora = seguidora->siguiente;
        }
        anterior->siguiente = nuevoNodo;
        nuevoNodo->siguiente = seguidora;
    }
    return lista;
}
nodo *agregarFinal(nodo *lista, nodo *nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }else
    {
        nodo *ultimo = buscarUltimo(lista);
        ultimo->siguiente= nuevoNodo;
    }
    return lista;
}
nodo *buscarUltimo(nodo *lista)
{
    nodo *seguidora = lista;
    if(lista != NULL)
    {
        while(seguidora->siguiente !=NULL)
        {
            seguidora = seguidora->siguiente;
        }
    }
    return seguidora;
}
nodo *buscarNodo(nodo *lista, int dato)
{
    nodo *seguidora = lista;
    if(lista != NULL)
    {
        while((seguidora->siguiente !=NULL) && (seguidora->dato != dato))
        {
            seguidora = seguidora->siguiente;
        }
    }
    return seguidora;
}
