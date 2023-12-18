#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ESTRUCTURAS
typedef struct
{
    char nombreSeleccion[50];
    char nombreDT[50];
    nodo *listaJugadores;
} selección;

typedef struct nodo
{
    stJugador j;
    struct nodo *sig;
} nodo;

typedef struct
{
    int nro_camiseta;
    char nombre[50];
    int pos;
    int goles;
} stJugador;

typedef struct arbol
{
    struct arbol *izquierda;
    struct arbol *derecha;
    stJugador j;
} arbol;

// PROTOTIPOS

int main()
{

    srand(time(NULL));
    system("pause");
    return 0;
}

// EJERCICIO 1
arbol *cargarArbol(arbol *arbol)
{
    char continuar = 's';

    while (continuar == 's')
    {
        stJugador j;
        printf("Ingrese el nombre del jugador: ");
        fflush(stdin);
        scanf("%s", j.nombre);

        printf("Ingrese el numero de camiseta: ");
        fflush(stdin);
        j.nro_camiseta = (rand() % 23) + 1;
        printf("Nro camiseta: %i\n", j.nro_camiseta);
    }
}