#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "string.h"

// ESTRUCTURAS
typedef struct stCancion
{
    int duracion;
    char artista[50];
    int cantidadReproducciones;
    char genero[50];
    char titulo[50];
    int idCancion;
    char album[50];
} stCancion;

typedef struct nodoCancion
{
    stCancion dato;
    struct nodoCancion *siguiente;
} nodoCancion;

typedef struct fila
{

    struct nodoListaReproduccion *primero;
    struct nodoListaReproduccion *ultimo;

} fila;

typedef struct nodoListaReproduccion
{
    int idCancion;
    struct nodoListaReproduccion *siguiente;
    struct nodoListaReproduccion *anterior;
} nodoListaReproduccion;

// PROTOTIPOS

// Funciones Auxiliares
nodoCancion *inic_lista_simple();
nodoListaReproduccion *inic_lista_doble();

// Ejercicio 1
nodoCancion *crear_nodo_lista_simple(stCancion dato);
nodoCancion *ultimo_nodo_lista_simple(nodoCancion *lista);
nodoCancion *insertar_nodo_lista_simple_al_final(nodoCancion *lista, nodoCancion *nuevoNodo);
nodoCancion *cargar_lista_simple(nodoCancion *lista);

// Ejercicio 2
nodoCancion *aBorrar(nodoCancion *lista, char aBorrar[]);

// Ejercicio 3
nodoCancion *escucharCancion(nodoCancion *lista, char aEsuchar[]);

// Ejercicio 4
nodoCancion *buscarCancion(nodoCancion *lista, char aBuscar[]);
void imprimir(nodoCancion *lista);

// Ejercicio 5
nodoCancion *buscarPorGenero(nodoCancion *lista, nodoCancion *sublista, char aBuscarXGen[]);

// Ejercicio 6
nodoCancion *buscarPorAlbum(nodoCancion *lista, nodoCancion *sublista, char aBuscarXAlb[]);

// Ejercicio 7
nodoCancion *buscarPorTitulo(nodoCancion *lista, nodoCancion *sublista, char aBuscarXTit[]);

// Ejercicio 8
void mostrar_lista_simple(nodoCancion *lista);

// Ejercicio 9
nodoListaReproduccion *crear_nodo_lista_doble(int dato);
nodoListaReproduccion *ultimo_nodo_lista_doble(nodoListaReproduccion *lista);
nodoListaReproduccion *insertar_nodo_lista_doble_al_final(nodoListaReproduccion *lista, nodoListaReproduccion *nuevoNodo);
int buscarPorTituloFila(nodoCancion *lista, char aBuscarXTit[]);
nodoListaReproduccion *cargar_lista_doble(nodoListaReproduccion *lista, nodoCancion *listaCan);
void mostrar_lista_doble(nodoListaReproduccion *lista);

// Ejercicio 10
nodoListaReproduccion *borrar_primer_nodo_lista_doble(nodoListaReproduccion *lista);

// Ejercicio 11
int calcularDuracionPlaylist(nodoCancion *lista);

// Ejercicio 12
int cantCancionesXGen(nodoCancion *lista, char genCriterio[]);

// Ejercicio 13
int escucharPlaylist(nodoCancion *lista);

int main()
{
    int opcion = 0;
    char continuar = 's';

    srand(time(NULL));
    nodoCancion *lista = inic_lista_simple();
    nodoListaReproduccion *listaID = inic_lista_doble();

    printf("Elija un ejercicio...\n");

    system("pause");
    system("cls");

    do
    {
        printf("1.  Agregar una cancion. \n");
        printf("2.  Borrar una cancion. \n");
        printf("3.  Escuchar una cancion. \n");
        printf("4.  Buscar por titulo. \n");
        printf("5.  Crear sublista por genero. \n");
        printf("6.  Crear sublista por album. \n");
        printf("7.  Crear sublista por titulo. \n");
        printf("8.  Mostrar todas las canciones. \n");
        printf("9.  Crear playlist de ID's. \n");
        printf("10. Borrar ID de la playlist. \n");
        printf("11. Calcular duracion de la playlist. \n");
        printf("12. Contar cantidad canciones por genero.\n");
        printf("13. Escuchar toda la playlist.\n");
        printf("");
        printf("\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%i", &opcion);

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            lista = cargar_lista_simple(lista);
            mostrar_lista_simple(lista);
            break;
        }
        case 2:
        {
            char nombreCanABorrar[20];

            printf("Ingrese el nombre de la cancion a borrar: ");
            fflush(stdin);
            scanf("%s", nombreCanABorrar);

            lista = aBorrar(lista, nombreCanABorrar);
            printf("Lista actualizada: \n");
            mostrar_lista_simple(lista);
            break;
        }
        case 3:
        {
            char nombreCanAEscuchar[20];

            printf("Ingrese el nombre de la cancion a escuchar: ");
            fflush(stdin);
            scanf("%s", nombreCanAEscuchar);

            lista = escucharCancion(lista, nombreCanAEscuchar);
            mostrar_lista_simple(lista);
            break;
        }
        case 4:
        {
            char nombreCanABuscar[20];

            printf("Ingrese el nombre de la cancion a buscar: ");
            fflush(stdin);
            scanf("%s", nombreCanABuscar);

            nodoCancion *canABuscar = buscarCancion(lista, nombreCanABuscar);
            imprimir(canABuscar);
            break;
        }
        case 5:
        {
            nodoCancion *sublistaGen = inic_lista_simple();
            char generoABuscar[20];

            printf("Ingrese el genero de canciones a buscar: ");
            fflush(stdin);
            scanf("%s", generoABuscar);

            sublistaGen = buscarPorGenero(lista, sublistaGen, generoABuscar);
            mostrar_lista_simple(sublistaGen);
            break;
        }
        case 6:
        {
            nodoCancion *sublistaAlb = inic_lista_simple();
            char albumABuscar[20];

            printf("Ingrese el album de canciones a buscar: ");
            fflush(stdin);
            scanf("%s", albumABuscar);

            sublistaAlb = buscarPorAlbum(lista, sublistaAlb, albumABuscar);
            mostrar_lista_simple(sublistaAlb);
            break;
        }
        case 7:
        {
            nodoCancion *sublistaTit = inic_lista_simple();
            char tituloABuscar[20];

            printf("Ingrese el titulo de canciones a buscar: ");
            fflush(stdin);
            scanf("%s", tituloABuscar);

            sublistaTit = buscarPorTitulo(lista, sublistaTit, tituloABuscar);
            mostrar_lista_simple(sublistaTit);
            break;
        }
        case 8:
        {
            mostrar_lista_simple(lista);
            break;
        }
        case 9:
        {
            listaID = cargar_lista_doble(listaID, lista);
            mostrar_lista_doble(listaID);
            break;
        }
        case 10:
        {
            listaID = borrar_primer_nodo_lista_doble(listaID);
            mostrar_lista_doble(listaID);
            break;
        }
        case 11:
        {
            int sumaPly = 0;
            sumaPly = calcularDuracionPlaylist(lista);
            printf("La playlist dura %i\n", sumaPly);
            break;
        }
        case 12:
        {
            int sumaCanXGen = 0;
            char genero[20];
            printf("Ingrese el genero que sera el criterio de suma: ");
            fflush(stdin);
            scanf("%s", genero);

            sumaCanXGen = cantCancionesXGen(lista, genero);
            printf("Hay %i canciones del genero %s\n", sumaCanXGen, genero);
            break;
        }
        case 13:
        {
            int cantRepro = 0;
            cantRepro = escucharPlaylist(lista);
            printf("Ha escuchado %i canciones.\n", cantRepro);
            break;
        }
        case 14:
        {
            printf("Saliendo...");
            break;
        }
        default:
        {
            printf("Opcion no valida. Saliendo...");
            break;
        }
        }

        system("pause");
        printf("Desea volver al menu principal?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        system("cls");

    } while ((continuar == 's' || continuar == 'S'));

    system("pause");
}

// FUNCIONES AUXILIARES
nodoCancion *inic_lista_simple()
{
    return NULL;
}

nodoListaReproduccion *inic_lista_doble()
{
    return NULL;
}

// EJERCICIOS DE LISTA SIMPLE

// EJERCICIO 1
nodoCancion *
crear_nodo_lista_simple(stCancion dato)
{
    nodoCancion *aux = (nodoCancion *)malloc(sizeof(nodoCancion));
    aux->dato = dato;
    aux->siguiente = inic_lista_simple();
    return aux;
}

nodoCancion *ultimo_nodo_lista_simple(nodoCancion *lista)
{
    nodoCancion *aux = lista;

    if (aux != NULL)
    {
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
    }
    return aux;
}

nodoCancion *insertar_nodo_lista_simple_al_final(nodoCancion *lista, nodoCancion *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoCancion *aux = ultimo_nodo_lista_simple(lista);
        aux->siguiente = nuevoNodo;
    }
    return lista;
}

nodoCancion *ordenar_lista_seleccion_por_duracion(nodoCancion *lista)
{
    nodoCancion *actual;
    nodoCancion *minimo;
    stCancion temp;

    for (actual = lista; actual != NULL; actual = actual->siguiente)
    {
        minimo = actual;

        for (nodoCancion *siguiente = actual->siguiente; siguiente != NULL; siguiente = siguiente->siguiente)
        {
            if (siguiente->dato.duracion < minimo->dato.duracion)
            {
                minimo = siguiente;
            }
        }

        if (minimo != actual)
        {
            temp = actual->dato;
            actual->dato = minimo->dato;
            minimo->dato = temp;
        }
    }

    return lista;
}

nodoCancion *cargar_lista_simple(nodoCancion *lista)
{
    char continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        stCancion aux_dato;
        printf("Ingrese el titulo de la cancion: ");
        fflush(stdin);
        scanf("%s", aux_dato.titulo);

        printf("Ingrese el nombre del artista: ");
        fflush(stdin);
        scanf("%s", aux_dato.artista);

        printf("Ingrese el genero al que pertenece: ");
        fflush(stdin);
        scanf("%s", aux_dato.genero);

        printf("Ingrese el album: ");
        fflush(stdin);
        scanf("%s", aux_dato.album);

        printf("Duracion (en segundos): ");
        fflush(stdin);
        aux_dato.duracion = (rand() % 500) + 59;
        printf("%i", aux_dato.duracion);
        printf("\n");

        printf("Cantidad de reproducciones: ");
        fflush(stdin);
        aux_dato.cantidadReproducciones = 0;
        printf("%i", aux_dato.cantidadReproducciones);
        printf("\n");

        printf("ID: ");
        fflush(stdin);
        aux_dato.idCancion = (rand() % 99) + 1;
        printf("%i", aux_dato.idCancion);
        printf("\n");

        nodoCancion *aux = crear_nodo_lista_simple(aux_dato);
        lista = insertar_nodo_lista_simple_al_final(lista, aux);
        lista = ordenar_lista_seleccion_por_duracion(lista);

        printf("Presiona 's' o 'S' para continuar: ");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n");
    }

    return lista;
}

// EJERCICIO 2
nodoCancion *aBorrar(nodoCancion *lista, char nombreCanABorrar[])
{
    nodoCancion *ante;
    nodoCancion *seg;

    if ((lista != NULL) && (strcmp(lista->dato.titulo, nombreCanABorrar) == 0))
    {
        nodoCancion *aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;

        while ((seg != NULL) && (strcmp(lista->dato.titulo, nombreCanABorrar) == 0))
        {
            ante = seg;
            seg = seg->siguiente;
        }

        if (seg != NULL)
        {
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }

    return lista;
}

// EJERCICIO 3
nodoCancion *escucharCancion(nodoCancion *lista, char nombreCanAEsuchar[])
{
    char continuar = 's';
    nodoCancion *seg = lista;

    if (seg != NULL)
    {
        while (continuar == 's')
        {
            if (strcmp(seg->dato.titulo, nombreCanAEsuchar) == 0)
            {
                seg->dato.cantidadReproducciones++;
            }
            else
            {
                seg = seg->siguiente;
            }

            printf("Escuchar de nuevo?: s/n\n");
            fflush(stdin);
            scanf("%c", &continuar);
        }
    }
    else
    {
        printf("Error: la lista esta vacia. \n");
    }

    return lista;
}

// EJERCICIO 4
nodoCancion *buscarCancion(nodoCancion *lista, char nombreCanABuscar[])
{
    nodoCancion *aux = NULL;

    if (lista != NULL)
    {
        if (strcmp(lista->dato.titulo, nombreCanABuscar) == 0)
        {
            aux = lista;
        }
        else
        {
            aux = buscarCancion(lista->siguiente, nombreCanABuscar);
        }
    }
    else
    {
        printf("La cancion no se encuntra en la lista.\n");
    }

    return aux;
}

void imprimir(nodoCancion *lista)
{
    printf("TITULO: %s\n", lista->dato.titulo);

    printf("ARTISTA: %s\n", lista->dato.artista);

    printf("GENERO: %s\n", lista->dato.genero);

    printf("ALBUM: %s\n", lista->dato.album);

    printf("DURACION: %i\n", lista->dato.duracion);

    printf("CANT. DE REPRODUCCIONES: %i\n", lista->dato.cantidadReproducciones);

    printf("ID: %i\n", lista->dato.idCancion);
}

// EJERCICIO 5
nodoCancion *buscarPorGenero(nodoCancion *lista, nodoCancion *sublista, char aBuscarXGen[])
{
    nodoCancion *seg = lista;

    while (seg != NULL)
    {
        if (strcmp(seg->dato.genero, aBuscarXGen) == 0)
        {
            stCancion dato;
            dato = seg->dato;
            nodoCancion *nuevoNodo = crear_nodo_lista_simple(dato);
            sublista = insertar_nodo_lista_simple_al_final(sublista, seg);
        }
        seg = seg->siguiente;
    }

    return sublista;
}

// EJERCICIO 6
nodoCancion *buscarPorAlbum(nodoCancion *lista, nodoCancion *sublista, char aBuscarXAlb[])
{
    nodoCancion *seg = lista;

    while (seg != NULL)
    {
        if (strcmp(seg->dato.album, aBuscarXAlb) == 0)
        {
            stCancion dato;
            dato = seg->dato;
            nodoCancion *nuevoNodo = crear_nodo_lista_simple(dato);
            sublista = insertar_nodo_lista_simple_al_final(sublista, seg);
        }
        seg = seg->siguiente;
    }

    return sublista;
}

// EJERCICIO 7
nodoCancion *buscarPorTitulo(nodoCancion *lista, nodoCancion *sublista, char aBuscarXTit[])
{
    nodoCancion *seg = lista;

    while (seg != NULL)
    {
        if (strcmp(seg->dato.titulo, aBuscarXTit) == 0)
        {
            stCancion dato;
            dato = seg->dato;
            nodoCancion *nuevoNodo = crear_nodo_lista_simple(dato);
            sublista = insertar_nodo_lista_simple_al_final(sublista, seg);
        }
        seg = seg->siguiente;
    }

    return sublista;
}

// EJERCICIO 8
void mostrar_lista_simple(nodoCancion *lista)
{
    nodoCancion *aux = lista;
    while (aux != NULL)
    {
        imprimir(aux);
        aux = aux->siguiente;
        printf("\n"); // Agregar salto de línea para separar las canciones.
    }
}

// EJERCICIOS DE "FILA" (lista doble con comportamienot de fila)

// EJERCICIO 1
nodoListaReproduccion *crear_nodo_lista_doble(int dato)
{
    nodoListaReproduccion *aux = (nodoListaReproduccion *)malloc(sizeof(nodoListaReproduccion));
    aux->anterior = inic_lista_doble();
    aux->siguiente = inic_lista_doble();
    aux->idCancion = dato;
    return aux;
}

nodoListaReproduccion *insertar_nodo_lista_doble_al_final(nodoListaReproduccion *lista, nodoListaReproduccion *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoListaReproduccion *aux = lista;

        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }

        aux->siguiente = nuevoNodo;
        nuevoNodo->anterior = aux;
    }
    return lista;
}

int buscarPorTituloFila(nodoCancion *lista, char aBuscarXTit[])
{
    nodoCancion *seg = lista;
    int idCan = 0;

    while (seg != NULL)
    {
        if (strcmp(seg->dato.titulo, aBuscarXTit) == 0)
        {
            idCan = seg->dato.idCancion;
        }
        seg = seg->siguiente;
    }

    return idCan;
}

nodoListaReproduccion *cargar_lista_doble(nodoListaReproduccion *lista, nodoCancion *listaCan)
{
    char continuar = 's';

    while ((continuar == 's') || (continuar == 'S'))
    {
        int idCan = 0;
        char nomCan[20];
        printf("Ingrese la cancion a buscar: ");
        fflush(stdin);
        scanf("%s", nomCan);

        idCan = buscarPorTituloFila(listaCan, nomCan);
        nodoListaReproduccion *aux = crear_nodo_lista_doble(idCan);
        lista = insertar_nodo_lista_doble_al_final(lista, aux);

        printf("Desea continuar?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n");
    }
    return lista;
}

void mostrar_lista_doble(nodoListaReproduccion *lista)
{
    nodoListaReproduccion *aux = lista;
    while (aux != NULL)
    {
        printf("ID: %i\n", aux->idCancion);
        aux = aux->siguiente;
    }
}

// EJERCICIO 2
nodoListaReproduccion *borrar_primer_nodo_lista_doble(nodoListaReproduccion *lista)
{
    if (lista)
    {
        nodoListaReproduccion *borrar = lista;
        lista = lista->siguiente;
        lista->anterior = NULL;
        borrar->siguiente = NULL;
        free(borrar);
    }
    return lista;
}

// EJERCICIO 3
int calcularDuracionPlaylist(nodoCancion *lista)
{
    int suma = 0;
    nodoCancion *seg = lista;

    while (seg != NULL)
    {
        suma += seg->dato.duracion;
        seg = seg->siguiente;
    }

    return suma;
}

// EJERCICIO 4
int cantCancionesXGen(nodoCancion *lista, char genCriterio[])
{
    int suma = 0;
    nodoCancion *seg = lista;

    while (seg != NULL)
    {
        if (strcmp(seg->dato.genero, genCriterio) == 0)
        {
            suma++;
        }

        seg = seg->siguiente;
    }

    return suma;
}

// EJERCICIO 5
int escucharPlaylist(nodoCancion *lista)
{
    int cantReproducciones = 0;
    nodoCancion *ante;
    nodoCancion *seg = lista;

    if (seg != NULL)
    {
        while (seg != NULL)
        {
            printf("\nEscuchando: \n");
            imprimir(seg);
            seg->dato.idCancion = 0;
            seg->dato.cantidadReproducciones++;
            cantReproducciones++;
            nodoCancion *aux = seg;
            seg = seg->siguiente;
            aux->siguiente = NULL;
            free(aux);
        }

        printf("La lista ha finalizado. Volviendo al menu.\n");
    }

    return cantReproducciones;
}