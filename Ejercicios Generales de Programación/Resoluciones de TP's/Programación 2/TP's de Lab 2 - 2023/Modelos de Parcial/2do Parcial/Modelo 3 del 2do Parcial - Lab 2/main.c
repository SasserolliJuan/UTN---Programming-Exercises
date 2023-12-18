#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ESTRUCTURAS
typedef struct nodoArbol
{
    int dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
} nodoArbol;

typedef struct listaPuntajes
{
    struct listaPuntajes *sig;
    int puntos;
} listaPuntajes;

typedef struct nodoJugador
{
    char nombreJugador[20];
    struct listaPuntajes *puntajes;
    struct nodoJugador *siguiente;
} nodoJugador;

// PROTOTIPOS

// Ejercicio 1
nodoArbol *inicArbol();
nodoJugador *inicLista();
nodoArbol *insertarEnArbol(nodoArbol *arbol, nodoArbol *nuevo);
nodoArbol *cargarArbol(nodoArbol *arbol, int dif);

// Ejercicio 2
nodoJugador *crearNodoJugador(char nombre[], listaPuntajes *puntajes);
int buscarJugador(nodoJugador *lista, char nombre[]);
nodoJugador *devolverJugador(nodoJugador *lista, char nombre[]);
nodoJugador *agregarAlPpioJugador(nodoJugador *lista, nodoJugador *nuevo);
listaPuntajes *agregarAlFinalPuntuaciones(listaPuntajes *lista, listaPuntajes *nuevo);
void mostrarJugador(nodoJugador *jugador);
nodoJugador *cargarListaJugadores(nodoJugador *lista, listaPuntajes *nuevo);

// Ejercicio 3
void mostrarArbol(nodoArbol *arbol);
int elegirNumeroAAdivinar(nodoArbol *arbol);

// Ejercicio 4
int confirmacionAdivinanza(int num, int numAdiv);
int adivinar(int numAdiv);

// Ejercicio 5
listaPuntajes *crearNodoPuntaje(int puntaje);

// Ejercicio 6
int calculoDePuntuacionesDeUnJugador(listaPuntajes *lista);
int mostrarPuntuaciones(nodoJugador *lista);
nodoJugador *jugadorGanador(nodoJugador *lista, int puntajeGanador);

int main()
{
    int dificultad = 0;
    srand(time(NULL));

    nodoArbol *arbol = inicArbol();

    printf("Seleccione el nivel de dificultad: \n");
    printf("1: Facil, 2: Intermedio, 3: Dificil. \n");

    while (dificultad != 1 && dificultad != 2 && dificultad != 3)
    {
        fflush(stdin);
        scanf("%i", &dificultad);

        if (dificultad != 1 && dificultad != 2 && dificultad != 3)
        {
            printf("Error: nivel de dificultad no valido.\n");
        }
    }

    arbol = cargarArbol(arbol, dificultad);
    printf("Arbol cargado. \n");

    nodoJugador *listaJugadores = inicLista();

    char seguir = 's';

    while (seguir == 's')
    {
        int numeroAAdivinar = elegirNumeroAAdivinar(arbol);
        int intentos = adivinar(numeroAAdivinar);

        listaPuntajes *aux = crearNodoPuntaje(intentos);
        listaJugadores = cargarListaJugadores(listaJugadores, aux);

        printf("Desea seguir jugando?: s/n\n");
        fflush(stdin);
        scanf(" %c", &seguir);
    }

    int puntajeGanador = mostrarPuntuaciones(listaJugadores);

    nodoJugador *aux2 = jugadorGanador(listaJugadores, puntajeGanador);

    printf("El puntaje ganador es de %i puntos, y corresponde al jugador %s \n", puntajeGanador, aux2->nombreJugador);

    system("pause");
    return 0;
}

nodoArbol *inicArbol()
{
    return NULL;
}

nodoJugador *inicLista()
{
    return NULL;
}

// EJERCICIO 1
nodoArbol *crearNodoArbol(int valor)
{
    nodoArbol *aux = (nodoArbol *)malloc(sizeof(nodoArbol));
    aux->dato = valor;
    aux->izq = inicArbol();
    aux->der = inicArbol();
    return aux;
}

nodoArbol *insertarEnArbol(nodoArbol *arbol, nodoArbol *nuevo)
{
    if (arbol == NULL)
    {
        arbol = nuevo;
    }
    else if (nuevo->dato < arbol->dato)
    {
        arbol->izq = insertarEnArbol(arbol->izq, nuevo);
    }
    else if (nuevo->dato > arbol->dato)
    {
        arbol->der = insertarEnArbol(arbol->der, nuevo);
    }

    return arbol;
}

nodoArbol *cargarArbol(nodoArbol *arbol, int dif)
{
    if (dif == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            int num = (rand() % 100) + 1;

            nodoArbol *aux = crearNodoArbol(num);

            arbol = insertarEnArbol(arbol, aux);
        }
    }
    else if (dif == 2)
    {
        for (int i = 0; i < 10; i++)
        {
            int num = (rand() % 100) + 1;

            nodoArbol *aux = crearNodoArbol(num);

            arbol = insertarEnArbol(arbol, aux);
        }
    }
    else
    {
        for (int i = 0; i < 15; i++)
        {
            int num = (rand() % 100) + 1;

            nodoArbol *aux = crearNodoArbol(num);

            arbol = insertarEnArbol(arbol, aux);
        }
    }

    return arbol;
}

// EJERCICIO 2
nodoJugador *crearNodoJugador(char nombre[], listaPuntajes *puntajes)
{
    nodoJugador *aux = (nodoJugador *)malloc(sizeof(nodoJugador));
    strcpy(aux->nombreJugador, nombre);
    aux->puntajes = puntajes;
    aux->siguiente = NULL;
    return aux;
}

int buscarJugador(nodoJugador *lista, char nombre[])
{
    int rta = 0;
    nodoJugador *seg = lista;

    while (seg != NULL)
    {
        if (strcmp(seg->nombreJugador, nombre) == 0)
        {
            rta = 1;
        }
        seg = seg->siguiente;
    }

    return rta;
}

nodoJugador *devolverJugador(nodoJugador *lista, char nombre[])
{
    nodoJugador *seg = lista;

    while (seg != NULL && strcmp(seg->nombreJugador, nombre) != 0)
    {
        seg = seg->siguiente;
    }

    return seg;
}

nodoJugador *agregarAlPpioJugador(nodoJugador *lista, nodoJugador *nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

listaPuntajes *agregarAlFinalPuntaje(listaPuntajes *lista, listaPuntajes *nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        listaPuntajes *seg = lista;

        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }
        seg->sig = nuevo;
    }

    return lista;
}

void mostrarJugador(nodoJugador *jugador)
{
    printf("Nombre: %s\n", jugador->nombreJugador);
    listaPuntajes *seg = jugador->puntajes;
    printf("Puntajes: \n");

    while (seg != NULL)
    {
        printf("- %i puntos.\n", seg->puntos);
        seg = seg->sig;
    }
}

nodoJugador *cargarListaJugadores(nodoJugador *lista, listaPuntajes *nuevo)
{
    int rta = 0;

    char nombreJugador[20];
    printf("Ingrese el nombre del jugador: ");
    fflush(stdin);
    scanf("%s", nombreJugador);

    rta = buscarJugador(lista, nombreJugador);

    if (rta == 0)
    {
        printf("El jugador no se encuentra en la lista. Creando jugador...\n");

        nodoJugador *aux = crearNodoJugador(nombreJugador, nuevo);
        lista = agregarAlPpioJugador(lista, aux);
    }
    else
    {
        printf("Jugador encontrado. \n");

        lista->puntajes = agregarAlFinalPuntaje(lista->puntajes, nuevo);
        nodoJugador *aux2 = devolverJugador(lista, nombreJugador);
        mostrarJugador(aux2);
        system("pause");
    }
    return lista;
}

// EJERCICIO 3
void mostrarArbol(nodoArbol *arbol)
{
    if (arbol != NULL)
    {
        mostrarArbol(arbol->izq);
        printf("Dato: %i\n", arbol->dato);
        mostrarArbol(arbol->der);
    }
}

int buscarNumeroEnArbol(nodoArbol *arbol, int numero)
{
    int num = 0;

    if (arbol != NULL)
    {
        if (arbol->dato == numero)
        {
            num = arbol->dato;
        }
        else if (numero < arbol->dato)
        {
            num = buscarNumeroEnArbol(arbol->izq, numero);
        }
        else
        {
            num = buscarNumeroEnArbol(arbol->der, numero);
        }
    }

    return num;
}

int elegirNumeroAAdivinar(nodoArbol *arbol)
{
    int numEncontrado = -1;
    int numAdivinar = 0;

    while (numAdivinar != numEncontrado)
    {
        numAdivinar = (rand() % 100) + 1;

        numEncontrado = buscarNumeroEnArbol(arbol, numAdivinar);
    }

    return numAdivinar;
}

// EJERCICIO 4
int confirmacionAdivinanza(int num, int numAdiv)
{
    int rta = 0;

    if (num == numAdiv)
    {
        rta = 1;
    }
    else if (num > numAdiv)
    {
        rta = 2;
    }
    else if (num < numAdiv)
    {
        rta = 3;
    }

    return rta;
}

int adivinar(int numAdiv)
{
    int num = 0;
    int rta = 0;
    int nroIntentos = 0;

    while (num != numAdiv)
    {
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%i", &num);

        rta = confirmacionAdivinanza(num, numAdiv);

        if (rta == 2)
        {
            printf("Fallo. El numero a adivinar es menor. \n");
            nroIntentos++;
        }
        else if (rta == 3)
        {
            printf("Fallo. El numero a adivinar es mayor. \n");
            nroIntentos++;
        }
        else if (rta == 1)
        {
            printf("Felicidades. Numero adivinado. \n");
        }
    }

    return nroIntentos;
}

// EJERCICIO 5
listaPuntajes *crearNodoPuntaje(int puntaje)
{
    listaPuntajes *aux = (listaPuntajes *)malloc(sizeof(listaPuntajes));
    aux->puntos = puntaje;
    aux->sig = NULL;
    return aux;
}

// EJERCICIO 6
int calculoDePuntuacionesDeUnJugador(listaPuntajes *lista)
{
    int puntajeTotal = 0;
    listaPuntajes *seg = lista;

    while (seg != NULL)
    {
        puntajeTotal += seg->puntos;

        seg = seg->sig;
    }

    return puntajeTotal;
}

int mostrarPuntuaciones(nodoJugador *lista)
{
    int i = 0;
    int mnPj = INT_MAX; // Inicializar con el valor máximo posible de un entero
    int puntaje = 0;
    nodoJugador *seg = lista;

    while (seg != NULL)
    {
        printf("Jugador %i (%s): ", i + 1, seg->nombreJugador);

        listaPuntajes *segAux = seg->puntajes;

        // Corregir llamada a la función
        puntaje = calculoDePuntuacionesDeUnJugador(segAux);

        if (puntaje < mnPj)
        {
            mnPj = puntaje;
        }

        printf("Puntos: %i\n", puntaje);

        seg = seg->siguiente;
        i++; // Incrementar el índice
    }

    return mnPj;
}

nodoJugador *jugadorGanador(nodoJugador *lista, int puntajeGanador)
{
    nodoJugador *jugadorGanador = NULL;
    nodoJugador *seg = lista;

    while (seg != NULL)
    {
        listaPuntajes *segAux = seg->puntajes;
        int puntaje = calculoDePuntuacionesDeUnJugador(segAux);

        if (puntaje == puntajeGanador)
        {
            jugadorGanador = seg;
        }

        seg = seg->siguiente;
    }

    return jugadorGanador;
}
