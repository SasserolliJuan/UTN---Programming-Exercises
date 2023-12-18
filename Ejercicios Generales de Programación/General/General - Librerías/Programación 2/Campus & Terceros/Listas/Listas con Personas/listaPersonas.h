#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#ifndef LISTAPERSONAS_H_INCLUDED
#define LISTAPERSONAS_H_INCLUDED

typedef struct stPersona
{
    char nombre[30];
    int edad;
}stPersona;

typedef struct nodo
{
    stPersona datos;
    struct nodo* siguiente;
}nodo;

nodo* iniciarLista();
nodo* cargarLista(nodo* lista);
nodo* cargarListaOrdenada(nodo* lista);
nodo* crearNodo(stPersona persona);
nodo* addPrincipioLista(nodo* lista , nodo* nuevoNodo);
nodo* buscarUltimoNodo(nodo* lista);
nodo* addFinalLista(nodo* lista , nodo* nuevoNodo);
void mostrarLista(nodo* lista);
int verificaSiExistePersona(nodo* lista , char nombre[]);
stPersona buscarPersona(nodo* lista , char nombre[]);
nodo* insertarOrdenado(nodo* lista , nodo* nuevoNodo);
nodo* pasarArchivoToLista(char nombreArchivo[] , nodo* lista);
nodo* pasarArchivoToListaOrdenado(char nombreArchivo[] , nodo* lista);
nodo* intercalarListasOrdenadas(nodo* lista1 , nodo* lista2 , nodo* listaDestino);
nodo* borrarPersona(nodo* lista , char nombre[]);
nodo* borrarLista(nodo* lista);
nodo* invertirLista(nodo* lista);
nodo* modificarPersona(nodo* lista , char nombre[]);

/* ------------------------------ FUNCIONES AUXILIARES ------------------------------ */
stPersona cargarUnaPersona(stPersona persona);
void mostrarUnaPersona(stPersona persona);

#endif // LISTAPERSONAS_H_INCLUDED
