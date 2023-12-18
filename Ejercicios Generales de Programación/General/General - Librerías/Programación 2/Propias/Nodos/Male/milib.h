#ifndef MILIB_H_INCLUDED
#define MILIB_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    int dato;
    struct nodo *siguiente;
}nodo;

nodo *inicLista();
nodo *crearNodo(int dato);
nodo *agregarPpio(nodo *lista, nodo *nuevoNodo);
void mostrarLista(nodo *lista);
nodo *agregarOrden(nodo *lista, nodo *nuevoNodo);
nodo *agregarFinal(nodo *lista, nodo *nuevoNodo);
nodo *buscarUltimo(nodo *lista);
nodo *buscarNodo(nodo *lista, int dato);

#endif // MILIB_H_INCLUDED
