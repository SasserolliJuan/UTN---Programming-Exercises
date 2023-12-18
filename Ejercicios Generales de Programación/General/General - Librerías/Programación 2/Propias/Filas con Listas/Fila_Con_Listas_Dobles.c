#include "Fila_Con_Listas_Dobles.h"

// Inicializar lista doble:
nodo_lista_doble *inic_lista_doble()
{
    return NULL;
}

// Inicializar fila:
void inicFila(Fila *fila)
{
    fila->primero = inic_lista_doble();
    fila->ultimo = inic_lista_doble();
}

// Agregar un elemento a la fila:
nodo_lista_doble *crear_nodo_lista_doble(int dato)
{
    nodo_lista_doble *aux = (nodo_lista_doble *)malloc(sizeof(nodo_lista_doble));
    aux->anterior = inic_lista_doble();
    aux->siguiente = inic_lista_doble();
    aux->dato = dato;
    return aux;
}

nodo_lista_doble *ultimo_nodo_lista_doble(nodo_lista_doble *lista)
{
    nodo_lista_doble *aux = NULL;
    if (lista)
    {
        aux = lista;
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
    }
    return aux;
}

nodo_lista_doble *insertar_nodo_lista_doble_al_final(nodo_lista_doble *lista, nodo_lista_doble *nuevo_nodo)
{
    if (lista)
    {
        nodo_lista_doble *aux = ultimo_nodo_lista_doble(lista);
        aux->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = aux;
    }
    return lista;
}

void agregar(Fila *fila, int dato)
{
    nodo_lista_doble *nuevo = crear_nodo_lista_doble(dato);

    if (fila->primero == NULL)
    {
        fila->primero = nuevo;
        fila->ultimo = nuevo;
    }
    else
    {
        fila->primero = insertar_nodo_lista_doble_al_final(fila->primero, nuevo);
        fila->ultimo = nuevo;
    }
}

// Extraer un elemento de la fila:
int verPrimero(nodo_lista_doble *lista)
{
    int rta = 0;

    if (lista != NULL)
    {
        rta = lista->dato;
    }

    return rta;
}

nodo_lista_doble *borrar_primer_nodo_lista_doble(nodo_lista_doble *lista)
{
    if (lista)
    {
        nodo_lista_doble *borrar = lista;
        lista = lista->siguiente;
        lista->anterior = NULL;
        borrar->siguiente = NULL;
        free(borrar);
    }
    return lista;
}

int extraer(Fila *fila)
{
    int resp;

    if (fila->primero != NULL)
    {
        resp = verPrimero(fila->primero);

        fila->primero = borrar_primer_nodo_lista_doble(fila->primero);

        if (fila->primero == NULL)
        {
            fila->ultimo = inic_lista_doble();
        }
    }

    return resp;
}

void mostrar_fila(Fila *fila)
{
    nodo_lista_doble *actual = fila->primero;

    while (actual != NULL)
    {
        printf("%i \n", actual->dato);
        actual = actual->siguiente;
    }
}

int filaVacia(Fila *fila)
{
    return (fila->primero == NULL);
}
