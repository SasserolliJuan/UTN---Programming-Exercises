#include "st_lista_simple.h"

// INICIALIZAR LISTA
nodo_lista_simple *inic_lista_simple()
{
    return NULL;
}

// FUNCIONES DE CARGA
nodo_lista_simple *crear_nodo_lista_simple(int dato)
{
    nodo_lista_simple *aux = (nodo_lista_simple *)malloc(sizeof(nodo_lista_simple));
    aux->dato = dato;
    aux->siguiente = inic_lista_simple();
    return aux;
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

nodo_lista_simple *cargar_lista_simple_al_principio(nodo_lista_simple *lista)
{
    char continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        int aux_dato;
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%i", &aux_dato);

        nodo_lista_simple *aux = crear_nodo_lista_simple(aux_dato);
        lista = insertar_nodo_lista_simple_al_principio(lista, aux);

        printf("Presiona 's' o 'S' para continuar: ");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n");
    }

    return lista;
}

nodo_lista_simple *ultimo_nodo_lista_simple(nodo_lista_simple *lista)
{
    nodo_lista_simple *aux = lista;

    if (aux != NULL)
    {
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
    }
    return aux;
}

nodo_lista_simple *insertar_nodo_lista_simple_al_final(nodo_lista_simple *lista, nodo_lista_simple *nuevo_nodo)
{
    if (lista == NULL)
    {
        lista = nuevo_nodo;
    }
    else
    {
        nodo_lista_simple *aux = ultimo_nodo_lista_simple(lista);
        aux->siguiente = nuevo_nodo;
    }

    return lista;
}

nodo_lista_simple *cargar_lista_simple_al_final(nodo_lista_simple *lista)
{
    char continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        int aux_dato;
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%i", &aux_dato);

        nodo_lista_simple *aux = crear_nodo_lista_simple(aux_dato);
        lista = insertar_nodo_lista_simple_al_final(lista, aux);

        printf("Presiona 's' o 'S' para continuar: ");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n");
    }

    return lista;
}

nodo_lista_simple *insertar_nodo_lista_simple_manteniendo_orden(nodo_lista_simple *lista, nodo_lista_simple *nuevo_nodo)
{
    if (lista == NULL)
    {
        lista = nuevo_nodo;
    }
    else
    {
        if (nuevo_nodo->dato < lista->dato)
        {
            lista = insertar_nodo_lista_simple_al_principio(lista, nuevo_nodo);
        }
        else
        {
            nodo_lista_simple *ante = lista;
            nodo_lista_simple *seg = lista->siguiente;

            while ((seg != NULL) && (nuevo_nodo->dato > seg->dato))
            {
                ante = seg;
                seg = seg->siguiente;
            }

            nuevo_nodo->siguiente = seg;
            ante->siguiente = nuevo_nodo;
        }
    }

    return lista;
}

void mostrar_lista_simple(nodo_lista_simple *lista)
{
    if (lista != NULL)
    {
        printf("%d \n", lista->dato);
        mostrar_lista_simple(lista->siguiente);
    }
}

// FUNCIONES DE BORRADO
nodo_lista_simple *borrar_nodo_lista_simple_por_dato(nodo_lista_simple *lista, int dato)
{
    nodo_lista_simple *ante;
    nodo_lista_simple *seg;

    if ((lista != NULL) && (dato == lista->dato))
    {
        nodo_lista_simple *aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;

        while ((seg != NULL) && (dato != seg->dato))
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

nodo_lista_simple *borrar_toda_la_lista_simple(nodo_lista_simple *lista)
{
    nodo_lista_simple *proximo;
    nodo_lista_simple *seg = lista;

    while (seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }

    return seg;
}

// BUSCAR NODO
nodo_lista_simple *buscar_nodo_lista_simple(nodo_lista_simple *lista, int dato)
{
    nodo_lista_simple *seg = lista;

    while ((seg != NULL) && (seg->dato != dato))
    {
        seg = seg->siguiente;
    }

    return seg;
}

// FUNCIONES EXTRA
nodo_lista_simple *devolver_primer_nodo(nodo_lista_simple *lista)
{
    nodo_lista_simple *aux = inic_lista_simple();

    if (lista != NULL)
    {
        aux = lista;
    }

    return aux;
}

int sumar_contenido_lista_simple(nodo_lista_simple *lista)
{
    int suma = 0;

    nodo_lista_simple *seg = lista;

    while (seg != NULL)
    {
        suma += seg->dato;
        seg = seg->siguiente;
    }

    return suma;
}

nodo_lista_simple *ordenar_lista_seleccion(nodo_lista_simple *lista)
{
    nodo_lista_simple *actual;
    nodo_lista_simple *minimo;
    int temp;

    for (actual = lista; actual != NULL; actual = actual->siguiente)
    {
        minimo = actual;

        for (nodo_lista_simple *siguiente = actual->siguiente; siguiente != NULL; siguiente = siguiente->siguiente)
        {
            if (siguiente->dato < minimo->dato)
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

nodo_lista_simple *ordenar_lista_insercion(nodo_lista_simple *lista)
{
    if (lista == NULL || lista->siguiente == NULL)
    {
        return;
    }

    nodo_lista_simple *listaOrdenada = NULL;
    nodo_lista_simple *actual = lista;

    while (actual != NULL)
    {
        nodo_lista_simple *siguiente = actual->siguiente;

        if (listaOrdenada == NULL || actual->dato <= listaOrdenada->dato)
        {
            actual->siguiente = listaOrdenada;
            listaOrdenada = actual;
        }
        else
        {
            nodo_lista_simple *temp = listaOrdenada;

            while (temp->siguiente != NULL && temp->siguiente->dato < actual->dato)
            {
                temp = temp->siguiente;
            }

            actual->siguiente = temp->siguiente;
            temp->siguiente = actual;
        }

        actual = siguiente;
    }

    lista = listaOrdenada;

    return lista;
}

nodo_lista_simple *intercalarListasOrdenadas(nodo_lista_simple *lista1, nodo_lista_simple *lista2)
{
    nodo_lista_simple *listaAux = inic_lista_simple();
    nodo_lista_simple *actual1 = lista1;
    nodo_lista_simple *actual2 = lista2;

    while (actual1 != NULL && actual2 != NULL)
    {
        if (actual1->dato <= actual2->dato)
        {
            // Si el elemento actual de la lista 1 es menor o igual, lo agregamos a la lista auxiliar
            if (listaAux == NULL)
            {
                listaAux = actual1;
                lista1 = actual1->siguiente;
                listaAux->siguiente = NULL;
                actual1 = lista1;
            }
            else
            {
                listaAux->siguiente = actual1;
                actual1 = actual1->siguiente;
                listaAux = listaAux->siguiente;
                listaAux->siguiente = NULL;
            }
        }
        else
        {
            // Si el elemento actual de la lista 2 es menor, lo agregamos a la lista auxiliar
            if (listaAux == NULL)
            {
                listaAux = actual2;
                lista2 = actual2->siguiente;
                listaAux->siguiente = NULL;
                actual2 = lista2;
            }
            else
            {
                listaAux->siguiente = actual2;
                actual2 = actual2->siguiente;
                listaAux = listaAux->siguiente;
                listaAux->siguiente = NULL;
            }
        }
    }

    // Despu�s de salir del bucle, puede que una de las listas todav�a tenga elementos
    // Agregamos los elementos restantes de la lista 1 si quedan
    if (actual1 != NULL)
    {
        if (listaAux == NULL)
        {
            listaAux = actual1;
        }
        else
        {
            listaAux->siguiente = actual1;
        }
    }

    // Agregamos los elementos restantes de la lista 2 si quedan
    if (actual2 != NULL)
    {
        if (listaAux == NULL)
        {
            listaAux = actual2;
        }
        else
        {
            listaAux->siguiente = actual2;
        }
    }

    return lista1; // Retornamos la lista auxiliar como resultado (lista1 contiene la referencia a la nueva lista intercalada)
}

nodo_lista_simple *invertirListaSimple(nodo_lista_simple *lista)
{
    nodo_lista_simple *anterior = NULL;
    nodo_lista_simple *actual = lista;
    nodo_lista_simple *siguiente = NULL;

    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }

    lista = anterior;

    return lista;
}
