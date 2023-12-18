#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ESTRUCTURAS
typedef struct nodoArbol
{
    char nombreLibro[30];
    int cantPaginas;
    char genero[20];
    int Puntaje;
    char NombrePersona[20];
    struct nodoArbol *izq;
    struct nodoArbol *der;
} nodoArbol;

typedef struct nodoListaLibro
{
    char nombreLibro[30];
    int cantPaginas;
    char genero[20];
    int Puntaje;
    struct nodoListaLibro *sig;
} nodoListaLibro;

typedef struct celda
{
    char NombrePersona[20];
    struct nodoListaLibro *listaLibros;
} celda;

// PROTOTIPOS

// Ejercicio 1
nodoArbol *inicArbol();
nodoListaLibro *inicLista();
nodoArbol *insertarEnArbol(nodoArbol *arbol, nodoArbol *nuevo);
nodoArbol *cargarArbol(nodoArbol *arbol, int cantLibros);
void mostrarNodoArbol(nodoArbol *arbol);
void mostrarArbol(nodoArbol *arbol);

// Ejercicio 2
nodoListaLibro *crearNodoLista(nodoArbol *arbol);

// Ejercicio 3
nodoListaLibro *insertarNodoEnLista(nodoListaLibro *lista, nodoListaLibro *nuevo);

// Ejercicio 4
int buscarPosEnArreglo(celda A[], char autor[], int dimension);

// Ejercicio 5
int agregarAutor(celda A[], char autor[], int validos);
int pasarDeArbolToArregloDeListas(nodoArbol *arbol, celda A[], int dimension);

// Ejercicio 6
void imprimir(nodoListaLibro *lista);
void mostrarLista(nodoListaLibro *lista);

// Ejercicio 7
void mostrarArregloDeListas(celda A[], int validos);

// Ejercicio 8
int buscarPosEnArregloRec(celda A[], char autor[], int validos, int i);

// Ejercicio 9
int buscarEnListaRec(nodoListaLibro *lista, int puntaje);

int main()
{
    srand(time(NULL));
    nodoArbol *arbol = inicArbol();
    int cantLibros = 0;

    printf("Cuantos libros desea cargar?: ");
    fflush(stdin);
    scanf("%i", &cantLibros);

    arbol = cargarArbol(arbol, cantLibros);
    mostrarArbol(arbol);

    celda A[20];
    int validos = 0;

    validos = pasarDeArbolToArregloDeListas(arbol, A, validos);
    mostrarArregloDeListas(A, validos);

    int i = 0;
    char autorABuscarEnArr[20];

    printf("Ingrese el nombre del autor a buscar: ");
    fflush(stdin);
    scanf("%s", autorABuscarEnArr);

    int pos = buscarPosEnArregloRec(A, autorABuscarEnArr, validos, i);

    if (pos != -1)
    {
        printf("El autor %s se encuentra en la posicion %i\n", autorABuscarEnArr, pos);
    }
    else
    {
        printf("Error: el autor buscado no se encuentra. \n");
    }

    // RECURSION//
    int puntaje = 0;
    char autorABuscarEnLista[20];

    printf("Ingrese el nombre del autor a buscar: ");
    fflush(stdin);
    scanf("%s", autorABuscarEnLista);

    printf("Ingrese un puntaje a buscar: ");
    fflush(stdin);
    scanf("%i", &puntaje);

    int posAux = buscarPosEnArreglo(A, autorABuscarEnLista, validos);

    nodoListaLibro *seg = A[posAux].listaLibros;

    int pos3 = buscarEnListaRec(seg, puntaje);

    if (pos3 == 1)
    {
        printf("El libro del autor %s cuyo puntaje es %i ha sido encontrado.\n", autorABuscarEnLista, puntaje, pos3);
    }
    else
    {
        printf("Error: no se ha encontrado ningun libro con un puntaje de %i que haya sido escrito por %s.\n", puntaje, autorABuscarEnLista);
    }

    system("pause");
    return 0;
}

nodoArbol *inicArbol()
{
    return NULL;
}

nodoListaLibro *inicLista()
{
    return NULL;
}

// EJERCICIO 1
nodoArbol *insertarEnArbol(nodoArbol *arbol, nodoArbol *nuevo)
{
    if (arbol == NULL)
    {
        arbol = nuevo;
    }
    else
    {
        if (nuevo->cantPaginas < arbol->cantPaginas)
        {
            arbol->izq = insertarEnArbol(arbol->izq, nuevo);
        }
        else if (nuevo->cantPaginas > arbol->cantPaginas)
        {
            arbol->der = insertarEnArbol(arbol->der, nuevo);
        }
    }

    return arbol;
}

nodoArbol *cargarArbol(nodoArbol *arbol, int cantLibros)
{
    int i = 0;

    while (i < cantLibros)
    {
        nodoArbol *aux = (nodoArbol *)malloc(sizeof(nodoArbol));

        printf("Ingrese el nombre del libro: ");
        fflush(stdin);
        scanf("%s", aux->nombreLibro);

        fflush(stdin);
        aux->cantPaginas = (rand() % 1000) + 1;
        printf("Ingrese la cantidad de paginas: %i\n", aux->cantPaginas);

        printf("Ingrese el genero del libro: ");
        fflush(stdin);
        scanf("%s", aux->genero);

        fflush(stdin);
        aux->Puntaje = (rand() % 10) + 1;
        printf("Ingrese el puntaje del libro: %i\n", aux->Puntaje);

        printf("Ingrese el nombre del autor: ");
        fflush(stdin);
        scanf("%s", aux->NombrePersona);

        aux->izq = NULL;
        aux->der = NULL;

        arbol = insertarEnArbol(arbol, aux);

        i++;
    }

    return arbol;
}

void mostrarNodoArbol(nodoArbol *arbol)
{
    printf("Libro: %s\n", arbol->nombreLibro);
    printf("Cant. paginas: %i\n", arbol->cantPaginas);
    printf("Genero: %s\n", arbol->genero);
    printf("Puntaje: %i\n", arbol->Puntaje);
    printf("Nombre del Autor: %s\n", arbol->NombrePersona);
}

void mostrarArbol(nodoArbol *arbol)
{
    if (arbol != NULL)
    {
        mostrarArbol(arbol->izq);
        mostrarNodoArbol(arbol);
        printf("\n");
        mostrarArbol(arbol->der);
    }
}

// EJERCICIO 2
nodoListaLibro *crearNodoLista(nodoArbol *arbol)
{
    nodoListaLibro *aux = (nodoListaLibro *)malloc(sizeof(nodoListaLibro));

    strcpy(aux->nombreLibro, arbol->nombreLibro);
    aux->cantPaginas = arbol->cantPaginas;
    strcpy(aux->genero, arbol->genero);
    aux->Puntaje = arbol->Puntaje;
    aux->sig = NULL;

    return aux;
}

// EJERCICIO 3
nodoListaLibro *insertarNodoEnLista(nodoListaLibro *lista, nodoListaLibro *nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodoListaLibro *ante = lista;
        nodoListaLibro *seg = lista->sig;

        while (seg != NULL && nuevo->Puntaje < seg->Puntaje)
        {
            ante = seg;
            seg = seg->sig;
        }
        ante->sig = nuevo;
        nuevo->sig = seg;
    }

    return lista;
}

// EJERCICIO 4
int buscarPosEnArreglo(celda A[], char autor[], int validos)
{
    int rta = -1;
    int i = 0;

    while (i < validos && rta == -1)
    {
        if (strcmp(A[i].NombrePersona, autor) == 0)
        {
            rta = i;
        }
        i++;
    }

    return rta;
}

// EJERCICIO 5
int agregarAutor(celda A[], char autor[], int validos)
{
    strcpy(A[validos].NombrePersona, autor);

    A[validos].listaLibros = inicLista();

    validos++;

    return validos;
}

int pasarDeArbolToArregloDeListas(nodoArbol *arbol, celda A[], int validos)
{
    if (arbol != NULL)
    {
        validos = pasarDeArbolToArregloDeListas(arbol->izq, A, validos);

        nodoListaLibro *aux = crearNodoLista(arbol);

        int pos = buscarPosEnArreglo(A, arbol->NombrePersona, validos);

        if (pos == -1)
        {
            validos = agregarAutor(A, arbol->NombrePersona, validos);
            pos = validos - 1;
        }

        A[pos].listaLibros = insertarNodoEnLista(A[pos].listaLibros, aux);

        validos = pasarDeArbolToArregloDeListas(arbol->der, A, validos);
    }

    return validos;
}

// EJERCICIO 6
void imprimir(nodoListaLibro *lista)
{
    printf("Libro: %s\n", lista->nombreLibro);
    printf("Paginas: %i\n", lista->cantPaginas);
    printf("Genero: %s\n", lista->genero);
    printf("Puntaje: %i\n", lista->Puntaje);
    printf("\n");
}

void mostrarLista(nodoListaLibro *lista)
{
    nodoListaLibro *seg = lista;

    while (seg != NULL)
    {
        imprimir(seg);
        seg = seg->sig;
    }
}

// EJERCICIO 7
void mostrarArregloDeListas(celda A[], int validos)
{
    int i = 0;
    printf("%i", validos);

    while (i < validos)
    {
        printf("---Autor %s (Celda %i): ---\n", A[i].NombrePersona, i);
        mostrarLista(A[i].listaLibros);
        i++;
    }
}

// EJERCICIO 8
int buscarPosEnArregloRec(celda A[], char autor[], int validos, int i)
{
    int pos = -1;

    if (i < validos && strcmp(A[i].NombrePersona, autor) == 0)
    {
        pos = i;
    }
    else if (i < validos && strcmp(A[i].NombrePersona, autor) != 0)
    {
        pos = buscarPosEnArregloRec(A, autor, validos, i + 1);
    }

    return pos;
}

// EJERCICIO 9
int buscarEnListaRec(nodoListaLibro *lista, int puntaje)
{
    int rta = 0;

    if (lista != NULL)
    {
        if (lista->Puntaje == puntaje)
        {
            rta = 1;
        }
        else
        {
            rta = buscarEnListaRec(lista->sig, puntaje);
        }
    }

    return rta;
}
