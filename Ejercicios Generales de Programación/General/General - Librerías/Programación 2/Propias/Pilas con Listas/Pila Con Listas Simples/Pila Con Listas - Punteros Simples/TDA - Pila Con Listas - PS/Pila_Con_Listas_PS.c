#include "Pila_Con_Listas_PS.h"

void inicpila(Pila * pila)
{
    pila->tope = NULL;
}

void apilar(Pila * pila, int valor)
{
    nodo_lista_simple_en_pila_PS * nuevo = (nodo_lista_simple_en_pila_PS*)malloc(sizeof(nodo_lista_simple_en_pila_PS));

    nuevo->dato = valor;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
}

void leer(Pila * pila)
{
    int dato = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &dato);

    apilar(pila, dato);
}

int desapilar(Pila * pila)
{
    int valor = 0;

    if (pilavacia(pila))
    {
        valor = -1 // Valor de error
    }

    valor = pila->tope->dato;
    nodo_lista_simple_en_pila_PS * temp = pila->tope;
    pila->tope = pila->tope->siguiente;
    free(temp);

    return valor;
}

int tope(Pila * pila)
{
    if (pilavacia(pila))
    {
        // Manejar error de pila vac�a aqu�, si es necesario
        return -1; // Valor de error
    }

    return pila->tope->dato;
}

int pilavacia(Pila * pila)
{
    return pila->tope == NULL;
}

void mostrar(Pila * pila)
{
    nodo_lista_simple_en_pila_PS * actual = pila->tope;

    printf("Contenido de la pila:\n");

    while (actual != NULL)
    {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}
