#include "Arreglo_De_Listas_Simples.h"

// INICIALIZAR LISTA
nodo_lista_simple * inic_lista_simple()
{
    return NULL;
}

// CARGAR DATOS AL ARREGLO DE LISTAS
nodo_lista_simple *crear_nodo_lista_simple(int nota, char alumno[])
{
    nodo_lista_simple* aux = (nodo_lista_simple*)malloc(sizeof(nodo_lista_simple));

    aux->nota = nota;
    strcpy(aux->alumno, alumno);
    aux->siguiente = NULL;

    return aux;
}

int buscar_pos_materia(celda arregloDeListas[], char materia[], int validos)
{
    int rta = -1;
    int i = 0;

    while((i < validos) && (rta == -1))
    {
        if(strcmp(arregloDeListas[i].materia, materia) == 0)
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

    arregloDeListas[validos].lista = inic_lista_simple();

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

int alta_de_materias(celda arregloDeListas[], char materia[], char alumno[], int nota, int validos)
{
    nodo_lista_simple* aux = crear_nodo_lista_simple(nota, alumno);

    int pos = buscar_pos_materia(arregloDeListas, materia, validos);

    if(pos == -1)
    {
        validos = agregar_materia(arregloDeListas, materia, validos);
        pos = validos - 1;
    }

    arregloDeListas[pos].lista = insertar_nodo_lista_simple_al_principio(arregloDeListas[pos].lista, aux);

    return validos;
}

int ingresar_notas_al_arreglo(celda arregloDeListas[], int dimension)
{
    int nota;
    char alumno[20];
    char materia[30];
    char continuar = 's';
    int validos = 0;

    while((continuar == 's') || (continuar == 'S') && (validos < dimension))
    {
        printf("Ingrese la materia: ");
        fflush(stdin);
        scanf("%s", &materia);

        printf("Ingrese la nota: ");
        fflush(stdin);
        scanf("%i", &nota);


        printf("Ingrese el nombre del alumno: ");
        fflush(stdin);
        scanf("%s", alumno);

        validos = alta_de_materias(arregloDeListas, materia, alumno, nota, validos);

        printf("Desea continuar?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    return validos;

}

void mostrar_lista_simple(nodo_lista_simple *lista)
{
    if (lista != NULL)
    {
        printf("NOTA: %i \n", lista->nota);
        printf("ALUMNO: %s \n", lista->alumno);
        mostrar_lista_simple(lista->siguiente);
    }
}
