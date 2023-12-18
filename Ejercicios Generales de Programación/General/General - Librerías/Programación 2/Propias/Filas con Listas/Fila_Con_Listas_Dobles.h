#ifndef FILA_CON_LISTAS_DOBLES_H_INCLUDED
#define FILA_CON_LISTAS_DOBLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_lista_doble
{
    int dato;
    struct nodo_lista_doble *anterior;
    struct nodo_lista_doble *siguiente;

} nodo_lista_doble;

typedef struct
{

    struct nodo_lista_doble *primero;
    struct nodo_lista_doble *ultimo;

} Fila;

nodo_lista_doble *inic_lista_doble();
void inicFila(Fila *);
nodo_lista_doble *crear_nodo_lista_doble(int);
nodo_lista_doble *ultimo_nodo_lista_doble(nodo_lista_doble *);
nodo_lista_doble *insertar_nodo_lista_doble_al_final(nodo_lista_doble *, nodo_lista_doble *);
void agregar(Fila *, int);
int verPrimero(nodo_lista_doble *);
nodo_lista_doble *borrar_primer_nodo_lista_doble(nodo_lista_doble *);
int extraer(Fila *);
void mostrar_fila(Fila *);
int filaVacia(Fila *);

#endif // FILA_CON_LISTAS_DOBLES_H_INCLUDED
