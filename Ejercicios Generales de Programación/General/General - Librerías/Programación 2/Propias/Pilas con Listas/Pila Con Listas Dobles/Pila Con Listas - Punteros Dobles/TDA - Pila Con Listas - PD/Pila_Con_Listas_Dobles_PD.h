#ifndef PILA_CON_LISTAS_DOBLES_PD_H_INCLUDED
#define PILA_CON_LISTAS_DOBLES_PD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct nodo_lista_doble_en_pila
{
    int dato;
    struct nodo_lista_doble_en_pila* siguiente;
    struct nodo_lista_doble_en_pila* anterior;

} nodo_lista_doble_en_pila;


typedef struct
{
    nodo_lista_doble_en_pila* tope;

} Pila;

void inicpila(Pila **);
void apilar(Pila **, int);
void leer(Pila **);
int desapilar(Pila **);
int tope(Pila **);
int pilavacia(Pila **);
void mostrar(Pila **);
void liberar(Pila **); //extra

#endif // PILA_CON_LISTAS_DOBLES_PD_H_INCLUDED
