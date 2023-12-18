#ifndef libreria_listas_simples_H_INCLUDED
#define libreria_listas_simples_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// ESTRUCTURAS
typedef struct // datos para el nodo de la lista de entradas
{
    int idTicket;
    int isVIP;
    char sector[50]; // palco, pullman, campo, platea.
} stEntrada;

typedef struct nodoEntrada // nodo de la lista de entradas
{
    stEntrada unaEntrada;
    struct nodoEntrada *sig;
} nodoEntrada;

typedef struct // Equivalente a celda. Es un arreglo.
{
    char categoria[20]; // clásica, premium, deluxe, estudiante.
    nodoEntrada *entradas;
} stBoleteria;

typedef struct nodoFila
{
    char nombreParticipante[50];
    stEntrada entradaAsignada;
    struct nodoFila *sig;
} nodoFila;

typedef struct fila
{
    nodoFila *ultimo;
    nodoFila *primero;
} fila;

nodoEntrada *inicLista();
nodoEntrada *crearNodoEntrada(stEntrada datos);
nodoEntrada *agregarAlPpio(nodoEntrada *lista, nodoEntrada *nuevo);
void inicFila(fila *fila);

#endif // libreria_listas_simples_H_INCLUDED