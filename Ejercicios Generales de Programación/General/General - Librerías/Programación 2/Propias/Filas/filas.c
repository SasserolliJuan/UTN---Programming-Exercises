#include "filas.h"

void inicFila(fila *f)
{
    f->principio = inicLista();
    f->ultimo = inicLista();
}

void agregarFila(fila *f, int elemento)
{
    nodo *nuevoNodo = crearNodo(elemento);
    if (f->principio == NULL)
    {
        f->principio = nuevoNodo;
        f->ultimo = nuevoNodo;
    }
    else
    {
        f->principio = agregarAlFinal(f->principio, nuevoNodo);
        f->ultimo = nuevoNodo;
    }
}

void leerFila(fila *f)
{
    printf("Ingresa un numero: ");
    int aux;
    scanf("%d", &aux);
    nodo *nuevoNodo = crearNodo(aux);

    if (f->principio == NULL)
    {
        f->principio = nuevoNodo;
        f->ultimo = nuevoNodo;
    }
    else
    {
        f->principio = agregarAlFinal(f->principio, nuevoNodo);
        f->ultimo = nuevoNodo;
    }
}

int primeroFila(fila f)
{
    int retorno = 0;
    if (f.principio == NULL)
    {
        printf("Fila vacia. \n");
    }
    else
    {
        retorno = f.principio->dato;
    }
    return retorno;
}

int filaVacia(fila f)
{
    int rta = 1;
    if (f.principio != NULL)
    {
        rta = 0;
    }
    return rta;
}

void mostrarFila(fila f)
{
    if (f.principio != NULL)
    {
        nodo *seg = f.principio;
        while (seg != NULL)
        {
            printf("%d ", seg->dato);
            seg = seg->siguiente;
        }
    }
    else
        printf("Fila vacia. \n");
}

int extraerFila(fila *f)
{
    int rta = f->principio->dato;
    f->principio = borrarPrimerNodo(f->principio);
    return rta;
}
