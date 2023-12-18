#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include "string.h"
#include <time.h>

typedef struct
{
    int dato;
    struct nodo* anterior;
    struct nodo* siguiente;
} nodo;

nodo* inicLista();
nodo* crearNodo(int);
nodo* agregarAlFinal(nodo*, nodo*);
nodo* borrarPrimerNodo(nodo*);
nodo* ultimoNodo(nodo*);
void mostrarLista(nodo*);


#endif // LISTAS_H_INCLUDED
