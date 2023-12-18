#ifndef PILA_CON_LISTAS_PD_H_INCLUDED
#define PILA_CON_LISTAS_PD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct nodo_lista_simple_en_pila_PD
{
    int dato;
    struct nodo_lista_simple * siguiente;

} nodo_lista_simple_en_pila_PD;

void inicpila(nodo_lista_simple_en_pila_PD **);
int pilaVacia(nodo_lista_simple_en_pila_PD **);
void apilar(nodo_lista_simple_en_pila_PD **, int);
int desapilar(nodo_lista_simple_en_pila_PD **);
int tope(nodo_lista_simple_en_pila_PD **);
void mostrar(nodo_lista_simple_en_pila_PD **);


#endif // PILA_CON_LISTAS_PD_H_INCLUDED
