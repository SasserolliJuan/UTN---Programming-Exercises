#ifndef ST_LISTA_DOBLE_H_INCLUDED
#define ST_LISTA_DOBLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

typedef struct nodo_lista_doble
{
    int dato;
    struct nodo_lista_doble * anterior;
    struct nodo_lista_doble * siguiente;

} nodo_lista_doble;

nodo_lista_doble * inic_lista_doble();
nodo_lista_doble * crear_nodo_lista_doble(int);
nodo_lista_doble * insertar_nodo_lista_doble_al_principio(nodo_lista_doble*, nodo_lista_doble*);
nodo_lista_doble * cargar_lista_doble(nodo_lista_doble*);
nodo_lista_doble * ultimo_nodo_lista_doble(nodo_lista_doble *);
nodo_lista_doble * insertar_nodo_lista_doble_al_final(nodo_lista_doble*, nodo_lista_doble*);
nodo_lista_doble * insertar_nodo_lista_doble_manteniendo_orden(nodo_lista_doble*, nodo_lista_doble*);
void mostrar_nodo_lista_doble(nodo_lista_doble*);
void mostrar_lista_doble(nodo_lista_doble*);
nodo_lista_doble * buscar_nodo_lista_doble(nodo_lista_doble*, int);
nodo_lista_doble * borrar_primer_nodo_lista_doble(nodo_lista_doble*);
nodo_lista_doble * borrar_ultimo_nodo_lista_doble(nodo_lista_doble*);
nodo_lista_doble * borrar_nodo_lista_doble_por_dato(nodo_lista_doble*, int);

#endif // ST_LISTA_DOBLE_H_INCLUDED
