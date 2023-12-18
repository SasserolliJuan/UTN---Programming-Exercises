#ifndef ST_ARBOL_H_INCLUDED
#define ST_ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

typedef struct nodo_arbol
{
    int dato;
    struct nodo_arbol *derecha;
    struct nodo_arbol *izquierda;
} nodo_arbol;

nodo_arbol *inic_arbol();
nodo_arbol *crear_nodo_arbol(int);
nodo_arbol *insertar_nodo_en_arbol(nodo_arbol *, nodo_arbol *);
nodo_arbol *cargar_arbol(nodo_arbol *);
int buscar(nodo_arbol *, int);
nodo_arbol *borrar_nodo(nodo_arbol *, int);
void preOrder(nodo_arbol *);
void inOrder(nodo_arbol *);
void postOrder(nodo_arbol *);
int es_hoja(nodo_arbol *);
nodo_arbol *nodo_mas_derecha(nodo_arbol *);
nodo_arbol *nodo_mas_izquierda(nodo_arbol *);
nodo_arbol *borrar_nodo_arbol(nodo_arbol *, int);

#endif // ST_ARBOL_H_INCLUDED
