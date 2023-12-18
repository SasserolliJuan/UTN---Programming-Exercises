#ifndef LISTA_DE_ARBOLES_H_INCLUDED
#define LISTA_DE_ARBOLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona
{
    int dni;
    char nombre[30];

}persona;

typedef struct nodo_arbol
{
    persona p;
    struct nodo_arbol *izq;
    struct nodo_arbol *der;

} nodo_arbol;

typedef struct nodo_lista_arbol
{
    int anioNacimiento;
    nodo_arbol *arbolPersonas;
    struct nodo_lista_arbol *sig;

} nodo_lista_arbol;

nodo_lista_arbol *inicLista();
nodo_lista_arbol *crearNodoLista(int anio);
nodo_arbol *crearNodoArbol(persona p);
persona cargarPersona();
nodo_lista_arbol *buscarNodoAnio(nodo_lista_arbol *lista, int anio);
nodo_lista_arbol *agregarEnOrdenEnLista(nodo_lista_arbol *lista, nodo_lista_arbol *nuevo);
nodo_arbol *insertarEnArbol(nodo_arbol *arbol, nodo_arbol *nuevo);
nodo_lista_arbol *cargarDatosEnListaDeArboles(nodo_lista_arbol *lista);
void mostrarPersona(persona mostrar);
void mostrarArbol(nodo_arbol *arbol);
void mostrarListaDeArboles(nodo_lista_arbol*lista);

#endif // LISTA_DE_ARBOLES_H_INCLUDED
