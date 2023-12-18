#include "st_lista_doble.h"

// INICIALIZAR LISTA
nodo_lista_doble * inic_lista_doble()
{
    return NULL;
}

// FUNCIONES DE CARGA
nodo_lista_doble * crear_nodo_lista_doble(int dato)
{
    nodo_lista_doble * aux = (nodo_lista_doble*) malloc(sizeof(nodo_lista_doble));
    aux->anterior=inic_lista_doble();
    aux->siguiente=inic_lista_doble();
    aux->dato = dato;
    return aux;
}

nodo_lista_doble * insertar_nodo_lista_doble_al_principio(nodo_lista_doble* lista, nodo_lista_doble* nuevo_nodo)
{
    nuevo_nodo->siguiente = lista;
    lista = nuevo_nodo;
    return lista;
}

nodo_lista_doble * cargar_lista_doble(nodo_lista_doble* lista)
{
    char continuar = 's';

    while((continuar == 's') || (continuar == 'S'))
    {
        int aux_dato;
        printf("ingresa un numero:");
        scanf("%d", &aux_dato);

        nodo_lista_doble * aux = crear_nodo_lista_doble(aux_dato);
        lista = insertar_nodo_lista_doble_al_principio(lista, aux);

        printf("Desea continuar?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n");

    }
    return lista;
}

nodo_lista_doble * ultimo_nodo_lista_doble(nodo_lista_doble * lista)
{
    nodo_lista_doble * aux = NULL;
    if (lista)
    {
        aux = lista;
        while(aux->siguiente != NULL)
            aux = aux->siguiente;
    }
    return aux;
}

nodo_lista_doble * insertar_nodo_lista_doble_al_final(nodo_lista_doble * lista, nodo_lista_doble * nuevo_nodo)
{
    if (lista)
    {
        nodo_lista_doble * aux = ultimo_nodo_lista_doble(lista);
        aux->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = aux;
    }
    return lista;
}

nodo_lista_doble * insertar_nodo_lista_doble_manteniendo_orden(nodo_lista_doble * lista, nodo_lista_doble * nuevo_nodo)
{
    if(lista == NULL)
    {
        lista = nuevo_nodo;
    }
    else
    {
        if(nuevo_nodo->dato < lista->dato)
        {
            lista = insertar_nodo_lista_doble_al_principio(lista, nuevo_nodo);
        }
        else
        {
            nodo_lista_doble * ante = lista;
            nodo_lista_doble * seg = lista->siguiente;

            while((seg != NULL) && (nuevo_nodo->dato > seg->dato))
            {
                ante = seg;
                seg = seg->siguiente;
            }

            ante->siguiente = nuevo_nodo;
            nuevo_nodo->anterior = ante;
            nuevo_nodo->siguiente = seg;

            if(seg != NULL)
            {
                seg = seg->siguiente;
            }
        }
    }

    return lista;
}

// FUNCIONES DE MOSTRAR
void mostrar_nodo_lista_doble(nodo_lista_doble * nodo)
{
    printf("%d ", nodo->dato);
}

void mostrar_lista_doble(nodo_lista_doble* lista)
{
    if (lista)
    {
        printf("%d ", lista->dato);
        mostrar_lista_doble(lista->siguiente);
    }
}

nodo_lista_doble * buscar_nodo_lista_doble(nodo_lista_doble * lista, int dato)
{
    nodo_lista_doble* aux = NULL;
    if (lista)
    {
        if (lista->dato == dato)
            aux = lista;
        else
            aux = buscar_nodo_lista_doble(lista->siguiente, dato);
    }
    return aux;
}

// FUNCIONES DE BORRADO
nodo_lista_doble * borrar_primer_nodo_lista_doble(nodo_lista_doble * lista)
{
    if (lista)
    {
        nodo_lista_doble * borrar = lista;
        lista = lista->siguiente;
        lista->anterior = NULL;
        borrar->siguiente = NULL;
        free(borrar);
    }
    return lista;
}

nodo_lista_doble * borrar_ultimo_nodo_lista_doble(nodo_lista_doble * lista)
{
    if (lista)
    {
        nodo_lista_doble * aux = ultimo_nodo_lista_doble(lista);
        nodo_lista_doble * ante_ultimo = aux->anterior;
        ante_ultimo->siguiente = NULL;
        aux->anterior = NULL;
        free(aux);
    }
    return lista;
}

nodo_lista_doble * borrar_nodo_lista_doble_por_dato(nodo_lista_doble * lista, int dato)
{
    if (lista)
    {
        if (lista->dato == dato)
            lista = borrar_primer_nodo_lista_doble(lista);
        else
        {
            nodo_lista_doble * ante = lista;
            nodo_lista_doble * sig = lista->siguiente;
            while (sig && sig->dato != dato)
            {
                ante = sig;
                sig = sig->siguiente;
            }
            if (sig == NULL){}
            else
            {
                ante->siguiente = sig->siguiente;
                sig->anterior = NULL;
                free(sig);
            }
        }
    }
    return lista;
}
