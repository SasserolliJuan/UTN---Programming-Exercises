#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

typedef struct nodo_fila
{
    datosCadaPublicacion datos;
    time_t fechaReserva;
    struct nodo_fila *siguiente;
} nodo_fila;

typedef struct
{
    nodo_fila *inicio;
    nodo_fila *fin;
} fila;

void inicializarFila(fila *fila);
void agregarAFila(fila *fila, datosCadaPublicacion publicacion, time_t fechaReserva);
void actualizarEstadoPrestado(lista_de_listas *listaPublicaciones, char genero[], char titulo[]);
void verificarExpiracionPrestamos(fila *fila, lista_de_listas *listaPublicaciones);

#endif