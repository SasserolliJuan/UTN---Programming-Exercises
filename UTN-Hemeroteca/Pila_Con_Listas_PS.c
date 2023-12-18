#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "animaciones.h"
#include "arboles.h"
#include "archivos.h"
#include "Filas.h"
#include "Lista_De_Listas.h"
#include "menuAdministrador.h"
#include "menuPrincipal.h"
#include "menuUsuario.h"
#include "Pila_Con_Listas_PS.h"
#include "publicacionMusical.h"
#include "usuarios.h"

#define RESET_COLOR "\x1b[0m"
#define CYAN_F "\x1b[46m"
#define NEGRO_T "\x1b[30m"
#define ROJO_F "\x1b[41m"

void inicializarPila(Pila *pila)
{
    pila->tope = NULL;
}

void apilar(Pila *pila, datosCadaPublicacion valor)
{
    nodo_lista_simple_en_pila_PS *nuevo = (nodo_lista_simple_en_pila_PS *)malloc(sizeof(nodo_lista_simple_en_pila_PS));

    nuevo->dato = valor;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
}

int pilavacia(Pila *pila)
{
    return pila->tope == NULL;
}

datosCadaPublicacion desapilar(Pila *pila)
{
    datosCadaPublicacion valor;

    if (pilavacia(pila))
    {
        printf("La pila esta vacia. \n");
    }
    else
    {
        valor = pila->tope->dato;
        nodo_lista_simple_en_pila_PS *temp = pila->tope;
        pila->tope = pila->tope->siguiente;
        free(temp);
    }

    return valor;
}

// Funcion para mostrar las publicaciones mas populares usando una pila
void mostrarPublicacionesPopulares(lista_de_listas *listaPublicaciones, Pila *pila)
{
    Pila aux;
    inicializarPila(&aux);

    lista_de_listas *seg = listaPublicaciones;

    while (seg != NULL)
    {
        nodo_sublista_simple *nodoActual = seg->listaDatosPublicaciones;

        while (nodoActual != NULL)
        {
            if (pilavacia(pila) || (nodoActual->miRegistro.cantVecesLeida >= pila->tope->dato.cantVecesLeida))
            {
                // Si la pila est vacia o la publicacion actual tiene mas lecturas que la superior de la pila, se apila
                apilar(pila, nodoActual->miRegistro);
            }
            else
            {
                // Se desapilan las publicaciones con mejor calificacion a la pila auxiliar
                while (!pilavacia(pila) && (nodoActual->miRegistro.cantVecesLeida < pila->tope->dato.cantVecesLeida))
                {
                    datosCadaPublicacion temp = desapilar(pila);
                    apilar(&aux, temp);
                }

                // Se apila la nueva publicacion en la pila principal
                apilar(pila, nodoActual->miRegistro);

                // Se devuelven las publicaciones a la pila principal desde la pila auxiliar
                while (!pilavacia(&aux))
                {
                    datosCadaPublicacion temp = desapilar(&aux);
                    apilar(pila, temp);
                }
            }

            nodoActual = nodoActual->siguiente;
        }

        seg = seg->siguiente;
    }

    int i = 0;
    printf(" " CYAN_F " RANKING DE PUBLICACIONES\n\n" RESET_COLOR);

    while (!pilavacia(pila))
    {
        printf("Puesto %i\n", i + 1);
        datosCadaPublicacion temp = desapilar(pila);
        mostrarUnaPublicacion2(temp);
        i++;
    }
}
