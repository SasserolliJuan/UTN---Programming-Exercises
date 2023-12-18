#include "Arbol_De_Listas.h"

nodo_arbol_lista *inicArbol()
{
    return NULL;
}

// Funci�n para crear un nuevo nodo de la lista
nodo_lista_simple *crearNodoLista(persona dato)
{
    nodo_lista_simple *nuevoNodo = (nodo_lista_simple *)malloc(sizeof(nodo_lista_simple));

    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

// Funci�n para crear un nuevo nodo del �rbol de listas
nodo_arbol_lista *crearNodoArbolLista(int valor)
{
    nodo_arbol_lista *nuevoNodo = (nodo_arbol_lista *)malloc(sizeof(nodo_arbol_lista));

    nuevoNodo->valor = valor;
    nuevoNodo->lista = NULL;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;

    return nuevoNodo;
}

// Funci�n para agregar un nuevo nodo a la lista
// Funci�n para agregar un nuevo nodo a la lista de manera ordenada por DNI
nodo_lista_simple *agregarNodoListaOrdenado(nodo_lista_simple *lista, persona nuevoDato)
{
    nodo_lista_simple *nuevoNodo = crearNodoLista(nuevoDato);

    // Caso especial: la lista est� vac�a o el nuevo dato tiene un DNI menor al primer nodo
    if (lista == NULL || nuevoNodo->dato.dni < lista->dato.dni)
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    else
    {
         nodo_lista_simple *ante = lista;
         nodo_lista_simple *temp = lista->siguiente;

        // Buscar el lugar correcto para insertar el nuevo dato en orden ascendente por DNI
        while (temp != NULL && temp->dato.dni > nuevoNodo->dato.dni)
        {
            ante = temp;
            temp = temp->siguiente;
        }

        ante->siguiente = nuevoNodo;
        nuevoNodo->siguiente = temp;
    }

    return lista;
}

// Funci�n para insertar un nuevo nodo en el �rbol de listas
nodo_arbol_lista *insertarArbolLista(nodo_arbol_lista *arbol, int valor, persona datosLista)
{
    if (arbol == NULL)
    {
        // Si la ra�z es nula, crea un nuevo nodo de �rbol y su lista asociada
        arbol = crearNodoArbolLista(valor);
        arbol->lista = agregarNodoListaOrdenado(arbol->lista, datosLista);
    }
    else if (valor < arbol->valor)
    {
        // Recursivamente insertar en el sub�rbol izquierdo
        arbol->izquierda = insertarArbolLista(arbol->izquierda, valor, datosLista);
    }
    else if (valor > arbol->valor)
    {
        // Recursivamente insertar en el sub�rbol derecho
        arbol->derecha = insertarArbolLista(arbol->derecha, valor, datosLista);
    }
    else
    {
        // Si el valor ya existe, agregar el nuevo dato a la lista asociada
        arbol->lista = agregarNodoListaOrdenado(arbol->lista, datosLista);
    }

    return arbol;
}

nodo_arbol_lista *cargarDatosEnArbolDeListas(nodo_arbol_lista *arbol)
{
    char continuar = 's';

    while ((continuar == 's') || (continuar == 'S'))
    {
        persona datos;

        printf("Ingrese el nombre: ");
        fflush(stdin);
        scanf("%s", datos.nombre);

        printf("Ingrese la edad: ");
        fflush(stdin);
        scanf("%i", &datos.edad);

        printf("Ingrese el dni: ");
        fflush(stdin);
        scanf("%i", &datos.dni);

        // Insertar algunos nodos en el �rbol de listas
        arbol = insertarArbolLista(arbol, datos.edad, datos);

        printf("Desea continuar?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n");
    }

    return arbol;
}

// Funci�n para imprimir la lista asociada a un nodo del �rbol
void imprimirLista(nodo_lista_simple *lista)
{
    while (lista != NULL)
    {
        printf("Nombre: %s\n", lista->dato.nombre);
        printf("DNI: %i\n", lista->dato.dni);
        printf("\n");
        lista = lista->siguiente;
    }
}

// Funci�n para imprimir el �rbol en orden
void imprimirArbolEnOrden(nodo_arbol_lista *arbol)
{
    if (arbol != NULL)
    {
        imprimirArbolEnOrden(arbol->izquierda);
        printf("----Valor: %d----\nLista: \n", arbol->valor);
        imprimirLista(arbol->lista);
        imprimirArbolEnOrden(arbol->derecha);
    }
}
