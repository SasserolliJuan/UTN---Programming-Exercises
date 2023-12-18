#include <stdio.h>
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

void inicializarFila(fila *fila)
{
    fila->inicio = NULL;
    fila->fin = NULL;
}

void agregarAFila(fila *fila, datosCadaPublicacion publicacion, time_t fechaReserva)
{
    nodo_fila *nuevoNodo = (nodo_fila *)malloc(sizeof(nodo_fila));

    // Copiar los datos de la publicacion al nuevo nodo fila
    nuevoNodo->datos = publicacion;
    nuevoNodo->fechaReserva = fechaReserva;
    nuevoNodo->siguiente = NULL;

    // Si la fila esta vacia, el nuevo nodo sera tanto el inicio como el fin
    if (fila->inicio == NULL)
    {
        fila->inicio = nuevoNodo;
        fila->fin = nuevoNodo;
    }
    else
    {
        // Agregar el nuevo nodo al final de la fila y actualizar el fin
        fila->fin->siguiente = nuevoNodo;
        fila->fin = nuevoNodo;
    }
}

void actualizarEstadoPrestado(lista_de_listas *listaPublicaciones, char genero[], char titulo[])
{
    lista_de_listas *genEncontrado = buscarNodoGenero(listaPublicaciones, genero);

    if (genEncontrado != NULL)
    {
        nodo_sublista_simple *pubEncontrada = buscarNodoTitulo(genEncontrado->listaDatosPublicaciones, titulo);

        if (pubEncontrada != NULL)
        {
            pubEncontrada->miRegistro.prestado = 0;
        }
    }
}

void verificarExpiracionPrestamos(fila *fila, lista_de_listas *listaPublicaciones)
{
    time_t tiempoActual = time(NULL);
    time_t tiempoExpiracion = 2 * 24 * 60 * 60; // 2 dias en segundos

    nodo_fila *actual = fila->inicio;
    nodo_fila *anterior = NULL;

    while (actual != NULL)
    {
        // Calcular la diferencia de tiempo desde la reserva
        time_t tiempoDiferencia = difftime(tiempoActual, actual->fechaReserva);

        // Verificar si ha pasado el tiempo de expiracion
        if (tiempoDiferencia >= tiempoExpiracion)
        {
            // Mostrar mensaje de aviso al usuario
            printf("La publicacion '%s' ha sido retirada, ha pasado el tiempo de prestamo.\n", actual->datos.datosPublicacion.titulo);

            // Actualizar el estado de "prestado" a 0 en la lista de listas
            actualizarEstadoPrestado(listaPublicaciones, actual->datos.datosPublicacion.genero, actual->datos.datosPublicacion.titulo);

            // Eliminar el nodo de la fila
            if (anterior == NULL)
            {
                // El nodo a eliminar es el primero
                fila->inicio = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }

            // Verificar si el nodo a eliminar es el ultimo
            if (actual == fila->fin)
            {
                fila->fin = anterior;
            }

            free(actual); // Liberar la memoria del nodo eliminado
            actual = (anterior == NULL) ? fila->inicio : anterior->siguiente;
        }
        else
        {
            // Avanzar al siguiente nodo
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}
