#ifndef LISTAS_SIMPLES_CON_RECURSION_H_INCLUDED
#define LISTAS_SIMPLES_CON_RECURSION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

typedef struct nodo_lista_simple
{
    int dato;
    struct nodo_lista_simple * siguiente;

} nodo_lista_simple;

// Funciones Normales
nodo_lista_simple * inic_lista_simple();
nodo_lista_simple * crear_nodo_lista_simple(int);
nodo_lista_simple * insertar_nodo_lista_simple_al_principio(nodo_lista_simple*, nodo_lista_simple*);
nodo_lista_simple * cargar_lista_simple_al_principio(nodo_lista_simple*);
nodo_lista_simple * ultimo_nodo_lista_simple(nodo_lista_simple*);
nodo_lista_simple * insertar_nodo_lista_simple_al_final(nodo_lista_simple*, nodo_lista_simple*);
nodo_lista_simple *cargar_lista_simple_al_final(nodo_lista_simple*);
nodo_lista_simple * insertar_nodo_lista_simple_manteniendo_orden(nodo_lista_simple*, nodo_lista_simple*);
void mostrar_lista_simple(nodo_lista_simple*);
nodo_lista_simple * borrar_nodo_lista_simple_por_dato(nodo_lista_simple*, int);
nodo_lista_simple * borrar_toda_la_lista_simple(nodo_lista_simple*);
nodo_lista_simple * buscar_nodo_lista_simple(nodo_lista_simple*, int);
nodo_lista_simple * devolver_primer_nodo(nodo_lista_simple*);
int sumar_contenido_lista_simple(nodo_lista_simple*);
nodo_lista_simple * ordenar_lista_seleccion(nodo_lista_simple*);
nodo_lista_simple * ordenar_lista_insercion(nodo_lista_simple*);
nodo_lista_simple * intercalarListasOrdenadas(nodo_lista_simple*, nodo_lista_simple*);
nodo_lista_simple * invertirListaSimple(nodo_lista_simple*);

// Funciones Recursivas
void mostrarListaInvertidaR(nodo_lista_simple*);
int sumaContenidoListaR(nodo_lista_simple*);
void muestraPosParR (nodo_lista_simple*, int);
void otroMuestraPosPar(nodo_lista_simple*);
nodo_lista_simple * invertirRecursivo(nodo_lista_simple*);
nodo_lista_simple * borrarNodoR(nodo_lista_simple*, int);
nodo_lista_simple* insertarEnOrdenR(nodo_lista_simple*, nodo_lista_simple*);

#endif // LISTAS_SIMPLES_CON_RECURSION_H_INCLUDED
