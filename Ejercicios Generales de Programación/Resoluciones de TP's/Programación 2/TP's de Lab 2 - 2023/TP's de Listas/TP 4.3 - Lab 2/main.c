#include "st_lista_simple.h"

//PROTOTIPADOS

//Ejercicio 1:
void mostrarListaSimpleRecursion(nodo_lista_simple*);

//Ejercicio 2:
int sumaElementosListaRecursiva(nodo_lista_simple*);

//Ejercicio 3:
void mostrarElementosEnPosicionesParesEnListaRecursion(nodo_lista_simple*, int);

//Ejercicio 4:
nodo_lista_simple* borrarNodoPorDatoRecursion(nodo_lista_simple* lista, int dato);

//Ejercicio 5:
nodo_lista_simple* insertarNodoEnOrdenRecursivo(nodo_lista_simple*, nodo_lista_simple*);

int main()
{
   nodo_lista_simple* lista;
   lista = inic_lista_simple();
   menu(lista);
}

void menu(nodo_lista_simple* lista)
{
    int opcion = 0;

    printf("Elija un ejercicio... \n");

    system("pause");
    system("cls");

    printf("1. Recorrer una lista y mostrarla en forma invertida. \n");
    printf("2. Sumar los elementos de una lista. \n");
    printf("3. Mostrar los elementos de una lista ubicados en una posicion par. \n");
    printf("4. Borrar un nodo de una lista (buscado por un dato especifico). \n");
    printf("5. Insertar un nodo o dato en una lista simplemente enlazada en forma recursiva (manteniendo el orden de forma creciente). \n");
    printf("6. Invertir una lista cambiando los vinculos. \n");
    printf("\n");
    fflush(stdin);
    scanf("%i", &opcion);

    system("cls");

    switch(opcion)
    {
        case 1:
            {
                lista = cargar_lista_simple(lista);
                mostrar_lista_simple(lista);
                mostrarListaSimpleRecursion(lista);
                break;
            }
        case 2:
            {
                int suma = 0;
                lista = cargar_lista_simple(lista);
                mostrar_lista_simple(lista);
                suma = sumaElementosListaRecursiva(lista);
                printf("La suma de los elementos de la lista es %i", suma);
                break;
            }
        case 3:
            {
                int pos = 1;
                lista = cargar_lista_simple(lista);
                mostrar_lista_simple(lista);
                mostrarElementosEnPosicionesParesEnListaRecursion(lista, pos);
                break;

            }
        case 4:
            {
                int dato = 0;

                lista = cargar_lista_simple(lista);
                mostrar_lista_simple(lista);

                printf("Ingrese el dato a buscar: \n");
                fflush(stdin);
                scanf("%i", &dato);

                lista = borrarNodoPorDatoRecursion(lista, dato);
                printf("\n");
                mostrar_lista_simple(lista);
                break;
            }
        case 5:
            {
                lista = cargar_lista_simple(lista);
                printf("Lista: \n");
                mostrar_lista_simple(lista);
                lista = ordenar_lista_seleccion(lista);
                printf("Lista ordenada: \n");
                mostrar_lista_simple(lista);

                int dato = 0;
                printf("Ingrese el dato para el nuevo nodo: \n");
                fflush(stdin);
                scanf("%i", &dato);
                nodo_lista_simple* nuevoNodo = crear_nodo_lista_simple(dato);

                lista = insertarNodoEnOrdenRecursivo(lista, nuevoNodo);
                printf("Listra actualizada: \n");
                mostrar_lista_simple(lista);
                break;
            }
        case 6:
            {
                lista = cargar_lista_simple(lista);
                printf("Lista original: \n");
                mostrar_lista_simple(lista);

                lista = invertirListaSimple(lista);
                printf("Lista invertida: \n");
                mostrar_lista_simple(lista);
                break;
            }
        default:
            {
                break;
            }
    }
}

//EJERCICIO 1:
void mostrarListaSimpleRecursion(nodo_lista_simple* lista)
{
    if(lista != NULL)
    {
        mostrarListaSimpleRecursion(lista->siguiente);
        printf("%i", lista->dato);
    }
}

//EJERCICIO 2:
int sumaElementosListaRecursiva(nodo_lista_simple* lista)
{
    int suma = 0;

    if(lista->siguiente == NULL)
    {
        suma += lista->dato;
    }
    else
    {
        suma += lista->dato + sumaElementosListaRecursiva(lista->siguiente);
    }

    return suma;
}

//EJERCICIO 3:
void mostrarElementosEnPosicionesParesEnListaRecursion(nodo_lista_simple* lista, int pos)
{
    if(lista != NULL)
    {
        if(pos % 2 == 0)
        {
            printf("Posicion %i (par): %i \n", pos, lista->dato);
        }

        mostrarElementosEnPosicionesParesEnListaRecursion(lista->siguiente, pos+1);
    }
}

//EJERCICIO 4:
nodo_lista_simple* borrarNodoPorDatoRecursion(nodo_lista_simple* lista, int dato)
{
    nodo_lista_simple* seg = lista;
    nodo_lista_simple* ante = seg;

    if((lista != NULL) && (lista->dato == dato))  //Si el nodo a buscar es el primero.
    {
        nodo_lista_simple* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else if((seg != NULL) && (seg->dato == dato)) //Si el nodo a buscar NO es el primero.
    {
        ante->siguiente = seg->siguiente;
        free(seg);
    }
    else if(seg->siguiente != NULL)
    {
        lista->siguiente = borrarNodoPorDatoRecursion(seg->siguiente, dato);
    }
    else
    {
        printf("El dato a buscar no se encuentra en la lista. \n");
    }

    return lista;
}

//EJERCICIO 5:
nodo_lista_simple* insertarNodoEnOrdenRecursivo(nodo_lista_simple* lista, nodo_lista_simple* nuevoNodo)
{
    nodo_lista_simple* seg = lista;
    nodo_lista_simple* ante = seg;

    if((lista != NULL) && (lista->dato > nuevoNodo->dato))  //Si el dato del nuevo nodo es menor al del primer elemento de la lista.
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    else if((seg != NULL) && (seg->dato > nuevoNodo->dato))  //Encuentra el hueco para insertar el nuevo nodo.
    {
        nuevoNodo->siguiente = ante->siguiente;
        ante->siguiente = nuevoNodo;

    }
    else if(seg->siguiente != NULL)  //Avanza en la lista.
    {
        seg->siguiente = insertarNodoEnOrdenRecursivo(lista->siguiente, nuevoNodo);
    }
    else
    {
        printf("La lista esta vacia. \n");
    }

    return lista;
}
