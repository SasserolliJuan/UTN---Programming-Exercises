#ifndef PILA_CON_LISTAS_PS_H_INCLUDED
#define PILA_CON_LISTAS_PS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct nodo_lista_simple_en_pila_PS
{
    int dato;
    struct nodo_lista_simple* siguiente;

} nodo_lista_simple_en_pila_PS;

typedef struct
{
    nodo_lista_simple_en_pila_PS * tope;

} Pila;

void inicpila(Pila *);
void apilar(Pila *, int valor);
void leer(Pila *);
int desapilar(Pila *);
int tope(Pila *);
int pilavacia(Pila *);
void mostrar(Pila *);

#endif // PILA_CON_LISTAS_PS_H_INCLUDED
