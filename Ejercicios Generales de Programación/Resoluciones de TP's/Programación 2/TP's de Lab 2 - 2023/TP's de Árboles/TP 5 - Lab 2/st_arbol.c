#include "st_arbol.h"

// INICIALIZAR ARBOL
nodo_arbol *inic_arbol()
{
    return NULL;
}

// FUNCIONES PARA AGREGAR
nodo_arbol *crear_nodo_arbol(int dato)
{
    nodo_arbol *aux = (nodo_arbol *)malloc(sizeof(nodo_arbol));

    aux->dato = dato;
    aux->derecha = inic_arbol();
    aux->izquierda = inic_arbol();

    return aux;
}

nodo_arbol *insertar_nodo_en_arbol(nodo_arbol *arbol, nodo_arbol *nuevo_nodo)
{
    if (arbol == NULL)
    {
        arbol = nuevo_nodo;
    }
    else
    {
        if (arbol->dato > nuevo_nodo->dato)
        {
            arbol->izquierda = insertar_nodo_en_arbol(arbol->izquierda, nuevo_nodo);
        }
        else if (arbol->dato < nuevo_nodo->dato)
        {
            arbol->derecha = insertar_nodo_en_arbol(arbol->derecha, nuevo_nodo);
        }
        else
            printf("Error: ya existe el dato.\n");
    }
    return arbol;
}

nodo_arbol *cargar_arbol(nodo_arbol *arbol)
{
    char continuar = 's';

    do
    {
        int aux_dato;
        printf("Ingrese un numero: ");
        scanf("%d", &aux_dato);

        nodo_arbol *aux = crear_nodo_arbol(aux_dato);
        arbol = insertar_nodo_en_arbol(arbol, aux);

        printf("Desea seguir cargando datos al arbol?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n");

    } while (continuar == 's' || continuar == 'S');

    return arbol;
}

int buscar(nodo_arbol *arbol, int dato)
{
    int rta = 0;
    if (arbol != NULL)
    {
        if (arbol->dato == dato)
            rta = 1;
        else if (arbol->dato < dato)
            rta = buscar(arbol->derecha, dato);
        else
            rta = buscar(arbol->izquierda, dato);
    }
    return rta;
}

// FUNCIONES PARA MOSTRAR
void preOrder(nodo_arbol *arbol)
{
    if (arbol != NULL)
    {
        printf("%d ", arbol->dato);
        preOrder(arbol->izquierda);
        preOrder(arbol->derecha);
    }
}

void inOrder(nodo_arbol *arbol)
{
    if (arbol != NULL)
    {
        inOrder(arbol->izquierda);
        printf("%d ", arbol->dato);
        inOrder(arbol->derecha);
    }
}

void postOrder(nodo_arbol *arbol)
{
    if (arbol != NULL)
    {
        inOrder(arbol->izquierda);
        inOrder(arbol->derecha);
        printf("%d ", arbol->dato);
    }
}

// FUNCIONES PARA BORRAR
int es_hoja(nodo_arbol *arbol)
{
    int rta = -1;
    if ((arbol->derecha == NULL) && (arbol->izquierda == NULL))
    {
        rta = 1;
    }
    else
    {
        rta = 0;
    }
    return rta;
}

nodo_arbol *nodo_mas_derecha(nodo_arbol *arbol)
{
    if (arbol->derecha != NULL)
    {
        arbol = nodo_mas_derecha(arbol->derecha);
    }
    return arbol;
}

nodo_arbol *nodo_mas_izquierda(nodo_arbol *arbol)
{
    if (arbol->izquierda != NULL)
    {
        arbol = nodo_mas_izquierda(arbol->izquierda);
    }
    return arbol;
}

nodo_arbol *borrar_nodo_arbol(nodo_arbol *arbol, int dato)
{
    if (arbol != NULL)
    {
        if (arbol->dato == dato)
        {
            if (es_hoja(arbol) == 1)
            {
                free(arbol);
                arbol = NULL;
            }
            else if (arbol->izquierda != NULL)
            {
                nodo_arbol *nodo_derecha = nodo_mas_derecha(arbol->izquierda);
                arbol->dato = nodo_derecha->dato;
                arbol->izquierda = borrar_nodo_arbol(arbol->izquierda, nodo_derecha->dato);
            }
            else if (arbol->derecha != NULL)
            {
                nodo_arbol *nodo_izquierda = nodo_mas_izquierda(arbol->derecha);
                arbol->dato = nodo_izquierda->dato;
                arbol->derecha = borrar_nodo_arbol(arbol->derecha, nodo_izquierda->dato);
            }
        }
        else if (arbol->dato > dato)
        {
            arbol->izquierda = borrar_nodo_arbol(arbol->izquierda, dato);
        }
        else
        {
            arbol->derecha = borrar_nodo_arbol(arbol->derecha, dato);
        }
    }
    return arbol;
}