#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED
#include "listas.h"

typedef struct
{
    nodo* principio;
    nodo* ultimo;
} fila;

void inicFila(fila*);
void agregarFila(fila*, int);
void leerFila(fila*);
int primeroFila(fila);
int filaVacia(fila);
void mostrarFila(fila);
int extraerFila(fila*);

#endif // FILAS_H_INCLUDED
