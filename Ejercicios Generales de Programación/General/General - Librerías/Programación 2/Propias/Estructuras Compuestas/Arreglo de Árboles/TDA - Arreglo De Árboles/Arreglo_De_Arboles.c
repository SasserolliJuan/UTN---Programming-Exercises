#include "Arreglo_De_Arboles.h"

// INICIALZIAR ARBOL
nodoArbol *inic_arbol()
{
    return NULL;
}

// CARGAR DATOS AL ARREGLO DE ARBOLES
nodoArbol *crear_nodo_arbol(animal datos)
{
    nodoArbol *aux = (nodoArbol *)malloc(sizeof(nodoArbol));

    aux->dato = datos;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbol *insertar_nodo_arbol(nodoArbol *arbol, nodoArbol *nuevoNodo)
{
    if (arbol == NULL)
    {
        arbol = nuevoNodo;
    }
    else
    {
        if (nuevoNodo->dato.cantidad < arbol->dato.cantidad)
        {
            arbol->izq = insertar_nodo_arbol(arbol->izq, nuevoNodo);
        }
        else
        {
            arbol->der = insertar_nodo_arbol(arbol->der, nuevoNodo);
        }
    }

    return arbol;
}

int buscar_pos_especie(celdaEspecie arregloDeArboles[], char especie[], int validos)
{
    int rta = -1;
    int i = 0;

    while ((i < validos) && (rta == -1))
    {
        if (strcmp(arregloDeArboles[i].especie, especie) == 0)
        {
            rta = i;
        }

        i++;
    }

    return rta;
}

int agregar_animal(celdaEspecie arregloDeArboles[], char especie[], int validos)
{
    strcpy(arregloDeArboles[validos].especie, especie);

    arregloDeArboles[validos].arbolDeAnimales = inic_arbol();

    validos++;

    return validos;
}

int alta_de_animales(celdaEspecie arregloDeArboles[], animal datos, int validos)
{
    nodoArbol *aux = crear_nodo_arbol(datos);

    int pos = buscar_pos_especie(arregloDeArboles, datos.especie, validos);

    if (pos == -1)
    {
        validos = agregar_animal(arregloDeArboles, datos.especie, validos);
        pos = validos - 1;
    }

    arregloDeArboles[pos].arbolDeAnimales = insertar_nodo_arbol(arregloDeArboles[pos].arbolDeAnimales, aux);

    return validos;
}

int ingresar_animales_al_arreglo(celdaEspecie arregloDeArboles[], animal datos, int validosAct)
{
    int validos = validosAct;

    validos = alta_de_animales(arregloDeArboles, datos, validos);

    return validos;
}
