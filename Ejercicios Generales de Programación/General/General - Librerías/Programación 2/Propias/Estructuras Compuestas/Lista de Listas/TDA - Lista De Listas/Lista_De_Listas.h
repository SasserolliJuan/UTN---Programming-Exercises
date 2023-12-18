#ifndef LISTA_DE_LISTAS_H_INCLUDED
#define LISTA_DE_LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct persona
{
    int nroCliente;
    char nombre_apellido[30];
    int cantProductos;
} persona;

typedef struct nodo_lista_simple
{
    persona dato;
    struct nodo_lista_simple *siguiente;
} nodo_lista_simple;

typedef struct
{
    int nroCaja;
    char medio_Pago [30];
}caja;

typedef struct nodo_lista_simple_principal
{
    caja dato;
    nodo_lista_simple * listaClientes;
    struct nodo_lista_simple_principal * siguiente;

} nodo_lista_simple_principal;

nodo_lista_simple * inicSubLista();
nodo_lista_simple_principal * inicListaCaja();
nodo_lista_simple * crearNodoSublista(persona dato);
nodo_lista_simple_principal * crearNodoCaja(caja c);
nodo_lista_simple_principal * buscarCaja(nodo_lista_simple_principal * lista, int nroCaja);
caja ingresarCaja(int nroCaja);
nodo_lista_simple_principal * agregarPpioCaja(nodo_lista_simple_principal * lista, nodo_lista_simple_principal * nuevoNodo);
nodo_lista_simple * agregarFinal(nodo_lista_simple * lista, nodo_lista_simple * nuevoNodo);
nodo_lista_simple_principal * alta (nodo_lista_simple_principal *listaCajas, nodo_lista_simple * nuevoCliente, int nroCaja);
nodo_lista_simple_principal *ingresarCajas(nodo_lista_simple_principal *lista);
void recorrerYmostrarCajasClientes(nodo_lista_simple_principal *lista);


#endif // LISTA_DE_LISTAS_H_INCLUDED
