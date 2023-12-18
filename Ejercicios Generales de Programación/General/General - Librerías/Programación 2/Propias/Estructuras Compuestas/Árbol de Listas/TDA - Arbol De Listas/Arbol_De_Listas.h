#ifndef ARBOL_DE_LISTAS_H_INCLUDED
#define ARBOL_DE_LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

// Definición de la estructra de persona
typedef struct persona
{
    char nombre[30];
    int edad;
    int dni;

} persona;

// Definición de la estructura del nodo de la lista
typedef struct nodo_lista_simple
{
    persona dato;
    struct nodo_lista_simple *siguiente;

} nodo_lista_simple;

// Definición de la estructura del nodo del árbol de listas
typedef struct nodo_arbol_lista
{
    int valor;
    nodo_lista_simple *lista;
    struct nodo_arbol_lista *izquierda;
    struct nodo_arbol_lista *derecha;

} nodo_arbol_lista;

nodo_arbol_lista *inicArbol();
nodo_arbol_lista *cargarDatosEnArbolDeListas(nodo_arbol_lista *arbol);
nodo_lista_simple *crearNodoLista(persona dato);
nodo_arbol_lista *insertarArbolLista(nodo_arbol_lista *arbol, int valor, persona datosLista);
void imprimirLista(nodo_lista_simple *lista);
void imprimirArbolEnOrden(nodo_arbol_lista *arbol);

#endif // ARBOL_DE_LISTAS_H_INCLUDED
