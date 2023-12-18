#ifndef ARREGLO_DE_LISTAS_SIMPLES_H_INCLUDED
#define ARREGLO_DE_LISTAS_SIMPLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct nodo_lista_simple
{
    int nota;
    char alumno[20];
    struct nodo_lista_simple *siguiente;

} nodo_lista_simple;

typedef struct
{
    char materia[40];
    nodo_lista_simple *lista;

} celda;

nodo_lista_simple * inic_lista_simple();
nodo_lista_simple *crear_nodo_lista_simple(int nota, char alumno[]);
int buscar_pos_materia(celda arregloDeListas[], char materia[], int validos);
int agregar_materia(celda arregloDeListas[], char materia[], int validos);
nodo_lista_simple *insertar_nodo_lista_simple_al_principio(nodo_lista_simple *lista, nodo_lista_simple *nuevo_nodo);
int alta_de_materias(celda arregloDeListas[], char materia[], char alumno[], int nota, int validos);
int ingresar_notas_al_arreglo(celda arregloDeListas[], int dimension);
void mostrar_lista_simple(nodo_lista_simple *lista);

#endif // ARREGLO_DE_LISTAS_SIMPLES_H_INCLUDED
