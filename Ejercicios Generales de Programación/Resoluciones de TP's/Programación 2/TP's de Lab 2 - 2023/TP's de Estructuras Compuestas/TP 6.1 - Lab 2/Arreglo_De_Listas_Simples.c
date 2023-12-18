#include "Arreglo_De_Listas_Simples.h"

// INICIALIZAR LISTA
nodo_lista_simple *inic_lista_simple()
{
    return NULL;
}

// CARGAR DATOS AL ARREGLO DE LISTAS
nodo_lista_simple *crear_nodo_lista_simple(notaAlumno datos)
{
    nodo_lista_simple *aux = (nodo_lista_simple *)malloc(sizeof(nodo_lista_simple));

    aux->dato = datos;
    aux->siguiente = NULL;

    return aux;
}

int buscar_pos_materia(celda arregloDeListas[], char materia[], int validos)
{
    int rta = -1;
    int i = 0;

    while ((i < validos) && (rta == -1))
    {
        if (strcmp(arregloDeListas[i].materia, materia) == 0)
        {
            rta = i;
        }

        i++;
    }

    return rta;
}

int agregar_materia(celda arregloDeListas[], char materia[], int validos)
{
    strcpy(arregloDeListas[validos].materia, materia);

    arregloDeListas[validos].listaDeNotas = inic_lista_simple();

    validos++;

    return validos;
}

nodo_lista_simple *insertar_nodo_lista_simple_al_principio(nodo_lista_simple *lista, nodo_lista_simple *nuevo_nodo)
{
    if (lista == NULL)
    {
        lista = nuevo_nodo;
    }
    else
    {
        nuevo_nodo->siguiente = lista;
        lista = nuevo_nodo;
    }

    return lista;
}

int alta_de_materias(celda arregloDeListas[], notaAlumno datos, int validos)
{
    nodo_lista_simple *aux = crear_nodo_lista_simple(datos);

    int pos = buscar_pos_materia(arregloDeListas, datos.materia, validos);

    if (pos == -1)
    {
        validos = agregar_materia(arregloDeListas, datos.materia, validos);
        pos = validos - 1;
    }

    arregloDeListas[pos].listaDeNotas = insertar_nodo_lista_simple_al_principio(arregloDeListas[pos].listaDeNotas, aux);

    return validos;
}

int ingresar_notas_al_arreglo(celda arregloDeListas[], notaAlumno datos, int validosAct)
{
    int validos = validosAct;

    validos = alta_de_materias(arregloDeListas, datos, validos);

    printf("Alumno cargado. \n");

    return validos;
}
