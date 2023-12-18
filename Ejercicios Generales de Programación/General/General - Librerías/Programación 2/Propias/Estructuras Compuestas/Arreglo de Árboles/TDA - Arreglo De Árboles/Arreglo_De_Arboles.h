#ifndef ARREGLO_DE_ARBOLES_H_INCLUDED
#define ARREGLO_DE_ARBOLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    char nombreAnimal[30];
    int cantidad;
    int habitat; // 1 - selva, 2- savana, 3-bosque, 4-mar
    int idEspecie;
    char especie[20];

} animal;

typedef struct nodoArbol
{
    animal dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;

} nodoArbol;

typedef struct
{
    int idEspecie;
    char especie[20]; // "Mamiferos", "Aves", "Reptiles", "Peces"
    nodoArbol *arbolDeAnimales;

} celdaEspecie;

nodoArbol *inic_arbol();
nodoArbol *crear_nodo_arbol(animal datos);
nodoArbol *insertar_nodo_arbol(nodoArbol *arbol, nodoArbol *nuevoNodo);
int buscar_pos_especie(celdaEspecie arregloDeArboles[], char especie[], int validos);
int agregar_animal(celdaEspecie arregloDeArboles[], char especie[], int validos);
int alta_de_animales(celdaEspecie arregloDeArboles[], animal datos, int validos);
int ingresar_animales_al_arreglo(celdaEspecie arregloDeArboles[], animal datos, int validosAct);

#endif // ARREGLO_DE_ARBOLES_H_INCLUDED