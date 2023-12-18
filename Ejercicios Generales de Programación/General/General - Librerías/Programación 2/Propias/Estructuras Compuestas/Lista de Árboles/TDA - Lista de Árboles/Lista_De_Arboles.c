#include "Lista_De_Arboles.h"

nodo_lista_arbol *inicLista()
{
    return NULL;
}

nodo_lista_arbol *crearNodoLista(int anio)
{
    nodo_lista_arbol *nuevo = (nodo_lista_arbol *)malloc(sizeof(nodo_lista_arbol));

    nuevo->anioNacimiento = anio;
    nuevo->arbolPersonas = NULL;
    nuevo->sig = NULL;

    return nuevo;
}

nodo_arbol *crearNodoArbol(persona p)
{
    nodo_arbol *nuevo = (nodo_arbol *)malloc(sizeof(nodo_arbol));

    nuevo->p = p;
    nuevo->der = NULL;
    nuevo->izq = NULL;

    return nuevo;
}

persona cargarPersona()
{
    persona nueva;

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s", nueva.nombre);

    printf("Ingrese DNI: ");
    fflush(stdin);
    scanf("%i", &nueva.dni);

    return nueva;
}

nodo_lista_arbol *buscarNodoAnio(nodo_lista_arbol *lista, int anio)
{
    while ((lista != NULL) && (lista->anioNacimiento != anio))
    {
        lista = lista->sig;
    }

    return lista;
}

nodo_lista_arbol *agregarEnOrdenEnLista(nodo_lista_arbol *lista, nodo_lista_arbol *nuevo)
{
    if (lista && nuevo->anioNacimiento > lista->anioNacimiento)
    {
        nodo_lista_arbol *ante;
        nodo_lista_arbol *aux = lista;

        while ((aux != NULL) && (aux->anioNacimiento < nuevo->anioNacimiento))
        {
            ante = aux;
            aux = aux->sig;
        }
        ante->sig = nuevo;
        nuevo->sig = aux;
    }
    else
    {
        nuevo->sig = lista;
        lista = nuevo;
    }

    return lista;
}

nodo_arbol *insertarEnArbol(nodo_arbol *arbol, nodo_arbol *nuevo)
{
    if (arbol == NULL)
    {
        arbol = nuevo;
    }
    else if (nuevo->p.dni < arbol->p.dni)
    {
         arbol->izq = insertarEnArbol(arbol->izq, nuevo);
    }
    else
    {
        arbol->der = insertarEnArbol(arbol->der, nuevo);
    }

    return arbol;
}

nodo_lista_arbol *cargarDatosEnListaDeArboles(nodo_lista_arbol *lista)
{
    char continuar = 's';
    int anio;
    nodo_lista_arbol *nodoEncontrado;

    while ((continuar == 's') || (continuar == 's'))
    {
        persona datosAux;
        printf("Ingrese anio de nacimiento de la persona: ");
        scanf("%d", &anio);

        nodoEncontrado = buscarNodoAnio(lista, anio);

        if (nodoEncontrado == NULL)
        {
            nodo_lista_arbol *aux = crearNodoLista(anio); // If the year is not found, create a new node in the list
            lista = agregarEnOrdenEnLista(lista, aux);
            nodoEncontrado = buscarNodoAnio(lista, anio); // Retrieve the newly added node
        }

        datosAux = cargarPersona();
        nodo_arbol *auxArbol = crearNodoArbol(datosAux);
        nodoEncontrado->arbolPersonas = insertarEnArbol(nodoEncontrado->arbolPersonas, auxArbol);

        printf("Desea seguir cargando? s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);

    }

    return lista;
}

void mostrarPersona(persona mostrar)
{
    printf("\n\nNombre: %s", mostrar.nombre);
    printf("\nDNI: %i", mostrar.dni);
}

void mostrarArbol(nodo_arbol *arbol)
{
    if (arbol != NULL)
    {
        mostrarArbol(arbol->izq);
        mostrarPersona(arbol->p);
        mostrarArbol(arbol->der);
    }
}

void mostrarListaDeArboles(nodo_lista_arbol *lista)
{
    while (lista != NULL)
    {
        printf("\n\n Anio de Nacimiento: %d\n", lista->anioNacimiento);
        mostrarArbol(lista->arbolPersonas);
        lista = lista->sig;
    }
}
