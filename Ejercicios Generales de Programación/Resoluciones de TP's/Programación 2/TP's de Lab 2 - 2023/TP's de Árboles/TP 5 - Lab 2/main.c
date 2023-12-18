#include "st_arbol.h"
#include "string.h"

// ESTRUCTURAS
typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} persona;

typedef struct nodoS
{
    persona dato;
    struct nodoS *sig;
} nodoS;

typedef struct nodoArbol
{
    persona dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
} nodoArbol;

// PROTOTIPOS

// Funciones Auxiliares
nodoS *inicLS();
nodoArbol *inicAP();

// Parte 1
// Ejercicio 1
void mostrarEnPreOrden();
void mostrarEnInOrden();
void mostrarEnPostOrden();
void nivelesYaltura();

// Ejercicio 2
int retornarCantNodosHojas(nodo_arbol *arbol);
int retornarCantNodosGrado1(nodo_arbol *arbol);
int verificarSiUnDatoExiste(nodo_arbol *arbol, int dato);

// Parte 2
// Ejercicio 1
nodoArbol *crear_nodo_arbol_personas(persona datos);
nodoArbol *insertar_nodo_en_arbol_personas(nodoArbol *arbol, nodoArbol *nuevo_nodo);
nodoArbol *cargar_arbol_personas(nodoArbol *arbol);

// Ejercicio 2
void imprimir(nodoArbol *arbol);
void mostrarArbolPersonas(nodoArbol *arbol);

// Ejercicio 3
nodoS *crear_nodo_lista_simple(persona datos);
nodoS *insertarXLegajo(nodoS *lista, nodoS *nuevoNodo);
nodoS *arbol2ListaSimple(nodoArbol *arbol, nodoS *lista);
void imprimirLista(nodoS *lista);
void mostrar_lista(nodoS *lista);

// Ejercicio 4
nodoArbol *buscarLegajo(nodoArbol *arbol, int legajoABuscar);

// Ejercicio 5
int buscarNodoXNombre(nodoArbol *arbol, char nombreABuscar[]);

// Ejercicio 6
int calcularAlturaArbol(nodoArbol *arbol);

// Ejercicio 7
int calcularCantNodos(nodoArbol *arbol);

// Ejercicio 8
int retornarCantNodosHojasPersonas(nodoArbol *arbol);

// Ejercicio 9
int es_hoja_arbol_persona(nodoArbol *arbol);
nodoArbol *nodo_mas_derecha_arbol_persona(nodoArbol *arbol);
nodoArbol *nodo_mas_izquierda_arbol_persona(nodoArbol *arbol);
nodoArbol *borrar_nodo_arbol_personas(nodoArbol *arbol, int dato);

int main()
{
    nodo_arbol *arbol = inic_arbol();
    arbol = cargar_arbol(arbol);

    // Parte 1
    mostrarEnPreOrden();
    mostrarEnInOrden();
    mostrarEnPostOrden();
    nivelesYaltura();

    int cantHojasArbol = retornarCantNodosHojas(arbol);
    printf("El arbol tiene %i nodos hoja. \n", cantHojasArbol);
    int nodosG1Arbol = retornarCantNodosGrado1(arbol);
    printf("El arbol tiene %i nodos de grado 1. \n", nodosG1Arbol);

    int dato = 0;
    printf("Ingrese un dato a buscar: ");
    fflush(stdin);
    scanf("%i", &dato);

    int flag = verificarSiUnDatoExiste(arbol, dato);
    if (flag == 1)
    {
        printf("El dato %i existe en el arbol. \n");
    }
    else
    {
        printf("El dato %i no existe en el arbol. \n");
    }

    preOrder(arbol);
    printf("\n");

    // Parte 2
    inOrder(arbol);
    printf("\n");

    // Ejercicio 1
    nodoArbol *arbolPersonas = inicAP();
    arbolPersonas = cargar_arbol_personas(arbolPersonas);

    // Ejercicio 2
    printf("\n\n");
    printf("Arbol: \n");
    mostrarArbolPersonas(arbolPersonas);

    // Ejercicio 3
    printf("\n\n");
    nodoS *lista = inicLS();
    lista = arbol2ListaSimple(arbolPersonas, lista);
    printf("Lista: \n");
    mostrar_lista(lista);

    // Ejercicio 4
    printf("\n\n");
    int legajo = 0;
    printf("Ingrese el legajo a buscar: ");
    fflush(stdin);
    scanf("%i", &legajo);

    nodoArbol *aux = buscarLegajo(arbolPersonas, legajo);
    imprimir(aux);

    // Ejercicio 5
    printf("\n\n");
    int flag2 = 0;
    char nombre[20];

    printf("Ingrese el nombre a buscar: ");
    fflush(stdin);
    scanf("%s", nombre);

    flag2 = buscarNodoXNombre(arbolPersonas, nombre);

    if (flag2 == 1)
    {
        printf("Nombre encontrado.\n");
    }
    else
    {
        printf("Error: nombre no encontrado.\n");
    }

    // Ejercicio 6:
    printf("\n\n");
    int altura = 0;
    altura = calcularAlturaArbol(arbolPersonas);
    printf("La altura del arbol es %i. \n", altura);

    // Ejercicio 7
    printf("\n\n");
    int nodos = 0;
    nodos = calcularCantNodos(arbolPersonas);
    printf("El arbol tiene %i nodos. \n", nodos);

    // Ejercicio 8
    printf("\n\n");
    int nodosHoja = 0;
    nodosHoja = retornarCantNodosHojasPersonas(arbolPersonas);
    printf("El arbol tiene %i nodos hoja (personas). \n", nodosHoja);

    // Ejercicio 9
    printf("\n\n");
    int aBorrar = 0;
    printf("Ingrese el legajo del nodo a borrar: ");
    fflush(stdin);
    scanf("%i", &aBorrar);

    borrar_nodo_arbol_personas(arbolPersonas, aBorrar);
    printf("Arbol de personas actualizado. \n");
    mostrarArbolPersonas(arbolPersonas);

    system("pause");
}

// FUNCIONES AUXILIARES
nodoS *inicLS()
{
    return NULL;
}

nodoArbol *inicAP()
{
    return NULL;
}
// PARTE 1

// EJERCICIO 1
void mostrarEnPreOrden()
{
    printf("El arbol mostrara (Preorden): \n");
    printf("8 - 3 - 1 - 6 - 4 - 7 - 10 - 14 - 13\n");
}

void mostrarEnInOrden()
{
    printf("El arbol mostrara (Inorden): \n");
    printf("1 - 3 - 4 - 6 - 7 - 8 - 10 - 14 - 13\n");
}

void mostrarEnPostOrden()
{
    printf("El arbol mostrara (Postorden): \n");
    printf("1 - 6 - 4 - 7 - 3 - 13 - 14 - 10 - 8\n");
}

void nivelesYaltura()
{
    printf("Los niveles del arbol son: \n");
    printf("Nivel 0: 8\n");
    printf("Nivel 1: 3 - 10\n");
    printf("Nivel 2: 1 - 6 - 14\n");
    printf("Nivel 3: 4 - 7 - 13\n");

    printf("Su altura es: 4\n");
}

// EJERCICIO 2
int retornarCantNodosHojas(nodo_arbol *arbol)
{
    int cantHojas = 0;

    if ((arbol != NULL) && (es_hoja(arbol) == 1))
    {
        cantHojas++;
    }
    else if (arbol != NULL)
    {
        cantHojas += retornarCantNodosHojas(arbol->izquierda);
        cantHojas += retornarCantNodosHojas(arbol->derecha);
    }

    return cantHojas;
}

int retornarCantNodosGrado1(nodo_arbol *arbol)
{
    int cantG1 = 0;

    if (arbol != NULL)
    {
        cantG1 += retornarCantNodosGrado1(arbol->izquierda);
        cantG1 += retornarCantNodosGrado1(arbol->derecha);

        if ((arbol->izquierda != NULL) && (arbol->derecha == NULL))
        {
            cantG1++;
        }
        else if ((arbol->derecha != NULL) && (arbol->izquierda == NULL))
        {
            cantG1++;
        }
    }

    return cantG1;
}

int verificarSiUnDatoExiste(nodo_arbol *arbol, int dato)
{
    int flag = 0;
    if (arbol != NULL && arbol->dato == dato)
    {
        flag = 1;
    }
    else if ((arbol != NULL) && (dato < arbol->dato))
    {
        flag = verificarSiUnDatoExiste(arbol->izquierda, dato);
    }
    else if ((arbol != NULL) && (dato > arbol->dato))
    {
        flag = verificarSiUnDatoExiste(arbol->derecha, dato);
    }

    return flag;
}

// PARTE 2

// EJERCICIO 1
nodoArbol *crear_nodo_arbol_personas(persona datos)
{
    nodoArbol *aux = (nodoArbol *)malloc(sizeof(nodoArbol));

    aux->dato = datos;
    aux->der = inicAP();
    aux->izq = inicAP();

    return aux;
}

nodoArbol *insertar_nodo_en_arbol_personas(nodoArbol *arbol, nodoArbol *nuevo_nodo)
{
    if (arbol == NULL)
    {
        arbol = nuevo_nodo;
    }
    else
    {
        if (arbol->dato.legajo > nuevo_nodo->dato.legajo)
        {
            arbol->izq = insertar_nodo_en_arbol_personas(arbol->izq, nuevo_nodo);
        }
        else if (arbol->dato.legajo < nuevo_nodo->dato.legajo)
        {
            arbol->der = insertar_nodo_en_arbol_personas(arbol->der, nuevo_nodo);
        }
        else
            printf("Error: ya existe el dato.\n");
    }
    return arbol;
}

nodoArbol *cargar_arbol_personas(nodoArbol *arbol)
{
    char continuar = 's';

    do
    {
        persona datos;
        printf("Ingrese el numero de legajo: ");
        fflush(stdin);
        scanf("%i", &datos.legajo);

        printf("Ingrese el nombre: ");
        fflush(stdin);
        scanf("%s", datos.nombre);

        printf("Ingrese la edad: ");
        fflush(stdin);
        scanf("%i", &datos.edad);

        nodoArbol *aux = crear_nodo_arbol_personas(datos);
        arbol = insertar_nodo_en_arbol_personas(arbol, aux);

        printf("Desea seguir cargando datos al arbol?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n");

    } while (continuar == 's' || continuar == 'S');

    return arbol;
}

// EJERCICIO 2
void imprimir(nodoArbol *arbol)
{
    printf("NRO. DE LEGAJO: %i\n", arbol->dato.legajo);
    printf("NOMBRE: %s\n", arbol->dato.nombre);
    printf("EDAD: %i\n", arbol->dato.edad);
}

void mostrarArbolPersonas(nodoArbol *arbol)
{
    if (arbol != NULL)
    {
        mostrarArbolPersonas(arbol->izq);
        imprimir(arbol);
        mostrarArbolPersonas(arbol->der);
    }
}

// EJERCICIO 3
nodoS *crear_nodo_lista_simple(persona datos)
{
    nodoS *aux = (nodoS *)malloc(sizeof(nodoS));

    aux->dato = datos;
    aux->sig = NULL;

    return aux;
}

nodoS *insertarXLegajo(nodoS *lista, nodoS *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoS *seg = lista;

        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }

        seg->sig = nuevoNodo;
    }

    return lista;
}

nodoS *arbol2ListaSimple(nodoArbol *arbol, nodoS *lista)
{
    if (arbol != NULL)
    {
        lista = arbol2ListaSimple(arbol->izq, lista);

        nodoS *aux = crear_nodo_lista_simple(arbol->dato);
        lista = insertarXLegajo(lista, aux);

        lista = arbol2ListaSimple(arbol->der, lista);
    }

    return lista;
}

void imprimirLista(nodoS *lista)
{
    printf("NRO. DE LEGAJO: %i\n", lista->dato.legajo);
    printf("NOMBRE: %s\n", lista->dato.nombre);
    printf("EDAD: %i\n", lista->dato.edad);
}

void mostrar_lista(nodoS *lista)
{
    nodoS *seg = lista;

    while (seg != NULL)
    {
        imprimirLista(seg);
        seg = seg->sig;
    }
}

// EJERCICIO 4
nodoArbol *buscarLegajo(nodoArbol *arbol, int legajoABuscar)
{
    nodoArbol *aux = (nodoArbol *)malloc(sizeof(nodoArbol));

    if (arbol != NULL)
    {
        if (arbol->dato.legajo == legajoABuscar)
        {
            aux->dato = arbol->dato;
        }
        else if (arbol->dato.legajo > legajoABuscar)
        {
            aux = buscarLegajo(arbol->izq, legajoABuscar);
        }
        else if (arbol->dato.legajo < legajoABuscar)
        {
            aux = buscarLegajo(arbol->der, legajoABuscar);
        }
        else
        {
            printf("El legajo buscado no existe. \n");
        }
    }
    return aux;
}

// EJERCICIO 5
int buscarNodoXNombre(nodoArbol *arbol, char nombreABuscar[])
{
    int flag = 0;

    if (arbol != NULL)
    {
        if (strcmp(arbol->dato.nombre, nombreABuscar) == 0)
        {
            flag = 1;
        }
        else
        {
            flag = buscarNodoXNombre(arbol->izq, nombreABuscar);

            if (flag == 0)
            {
                flag = buscarNodoXNombre(arbol->der, nombreABuscar);
            }
        }
    }

    return flag;
}

// EJERCICIO 6
int calcularAlturaArbol(nodoArbol *arbol)
{
    int altura = 0;

    if (arbol != NULL)
    {
        altura++;
        altura += calcularAlturaArbol(arbol->izq);

        if ((arbol->izq != NULL) && (arbol->der == NULL))
        {
            altura--;
        }
        else if ((arbol->izq == NULL) && (arbol->der != NULL))
        {
            altura--;
        }

        altura += calcularAlturaArbol(arbol->der);
    }

    return altura;
}

// EJERCICIO 7
int calcularCantNodos(nodoArbol *arbol)
{
    int cantNodos = 0;

    if (arbol != NULL)
    {
        cantNodos++;
        cantNodos += calcularCantNodos(arbol->izq);
        cantNodos += calcularCantNodos(arbol->der);
    }

    return cantNodos;
}

// EJERCICIO 8
int retornarCantNodosHojasPersonas(nodoArbol *arbol)
{
    int cantHojas = 0;

    if ((arbol != NULL) && (es_hoja_arbol_persona(arbol) == 1))
    {
        cantHojas++;
    }
    else if (arbol != NULL)
    {
        cantHojas += retornarCantNodosHojasPersonas(arbol->izq);
        cantHojas += retornarCantNodosHojasPersonas(arbol->der);
    }

    return cantHojas;
}

// EJERCICIO 9
int es_hoja_arbol_persona(nodoArbol *arbol)
{
    int rta = -1;
    if ((arbol->der == NULL) && (arbol->izq == NULL))
    {
        rta = 1;
    }
    else
    {
        rta = 0;
    }
    return rta;
}

nodoArbol *nodo_mas_derecha_arbol_persona(nodoArbol *arbol)
{
    if (arbol->der != NULL)
    {
        arbol = nodo_mas_derecha_arbol_persona(arbol->der);
    }
    return arbol;
}

nodoArbol *nodo_mas_izquierda_arbol_persona(nodoArbol *arbol)
{
    if (arbol->izq != NULL)
    {
        arbol = nodo_mas_izquierda_arbol_persona(arbol->izq);
    }
    return arbol;
}

nodoArbol *borrar_nodo_arbol_personas(nodoArbol *arbol, int dato)
{
    if (arbol != NULL)
    {
        if (arbol->dato.legajo == dato)
        {
            if (es_hoja_arbol_persona(arbol) == 1)
            {
                free(arbol);
                arbol = NULL;
            }
            else if (arbol->izq != NULL)
            {
                nodoArbol *nodo_derecha = nodo_mas_derecha_arbol_persona(arbol->izq);
                arbol->dato = nodo_derecha->dato;
                arbol->izq = borrar_nodo_arbol_personas(arbol->izq, nodo_derecha->dato.legajo);
            }
            else if (arbol->der != NULL)
            {
                nodoArbol *nodo_izquierda = nodo_mas_izquierda_arbol_persona(arbol->der);
                arbol->dato = nodo_izquierda->dato;
                arbol->der = borrar_nodo_arbol_personas(arbol->der, nodo_izquierda->dato.legajo);
            }
        }
        else if (arbol->dato.legajo > dato)
        {
            arbol->izq = borrar_nodo_arbol_personas(arbol->izq, dato);
        }
        else
        {
            arbol->der = borrar_nodo_arbol_personas(arbol->der, dato);
        }
    }
    return arbol;
}