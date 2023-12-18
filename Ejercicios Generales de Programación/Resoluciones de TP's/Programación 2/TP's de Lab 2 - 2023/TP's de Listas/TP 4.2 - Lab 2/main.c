#include "st_lista_doble.h"
#include <math.h>

//PROTOTIPADOS

//Ejercicio 2:
int listaDobleCapicuaConRecursion(nodo_lista_doble*, nodo_lista_doble*);

//Ejercicio 3:
int contarElementosEnUnaLista(nodo_lista_doble*);
float determinarSiCantEsParOImpar(int);
nodo_lista_doble * borrarNodoListaDobleOrdenada(nodo_lista_doble*, float);

int main()
{
   nodo_lista_doble* lista;
   lista = inic_lista_doble();
   menu(lista);
}

void menu(nodo_lista_doble* lista)
{
    int opcion = 0;

    printf("Elija un ejercicio... \n");

    system("pause");
    system("cls");

    printf("2. Crear una funcion recursiva que determine si una lista doblemente vinculada es capicua(Despues de ver recursividad). \n");
    printf("3. Dada una lista doblemente enlazada ordenada de enteros, eliminar el nodo que se encuentra en el punto medio de la lista, si la cantidad de nodos es par, eliminar el inmediatamente superior. \n");
    printf("\n");
    fflush(stdin);
    scanf("%i", &opcion);

    system("cls");

    switch(opcion)
    {
        case 1:
            {
                printf("Ya se ha modificado la funcion 'borrarNodo()' de listas simples y se la ha transofrmado para el caso de una lista doble. Hecho en TDA. Este ejercicio no 'existe' en este main. \n");
                break;
            }
        case 2:
            {
                nodo_lista_doble* cola;
                int rta;
                lista = cargar_lista_doble(lista);
                mostrar_lista_doble(lista);
                cola = ultimo_nodo_lista_doble(lista);
                rta = listaDobleCapicuaConRecursion(lista, cola);

                if(rta == 1)
                {
                    printf("\nLa lista ES capicua. \n");
                }
                else if(rta == 0)
                {
                    printf("\nLa lista NO es capicua. \n");
                }
                break;
            }
        case 3:
            {
                int cantNodos = 0;
                float indice = 0;
                lista = cargar_lista_doble(lista);
                mostrar_lista_doble(lista);
                cantNodos = contarElementosEnUnaLista(lista);
                indice = determinarSiCantEsParOImpar(cantNodos);
                lista = borrarNodoListaDobleOrdenada(lista, indice);
                printf("\n");
                mostrar_lista_doble(lista);
                break;
            }
        case 4:
            {
                printf("Hecho en TDA. Este ejercicio no 'existe' en este main. \n");
                break;
            }
        default:
            {
                break;
            }
    }


}

//EJERCICIO 2:
int listaDobleCapicuaConRecursion(nodo_lista_doble* lista, nodo_lista_doble* cola)
{
    int rta = 0;

    if(lista != NULL && cola != NULL)
    {
        if(lista == cola || lista->anterior == cola)  //Si la cantidad de nodos es impar, lista y cola se van a encontrar en el mismo nodo. Si es impar, se van a pasar de largo entre sí. En ambos casos, significa que la lista es capicúa.
        {
            rta = 1;
        }
        else
        {
            if(lista->dato == cola->dato)
            {
                rta = listaDobleCapicuaConRecursion(lista->siguiente, cola->anterior);
            }
            else
            {
                rta = 0;
            }
        }
    }
    else
    {
        rta = 1; //La lista está vacía o tiene un solo elemento, se considera capicúa.
    }

   return rta;

}

//EJERCICIO 3:
int contarElementosEnUnaLista(nodo_lista_doble* lista)
{
    int cant = 0;
    nodo_lista_doble* seg = lista;

    while(seg != NULL)
    {
        cant++;
        seg = seg->siguiente;

    }

    return cant;
}

float determinarSiCantEsParOImpar(int cant)
{
    float indice = 0;

    if(cant % 2 == 0)
    {
        indice = (cant / 2) + 1;
    }
    else
    {
        indice = (float) cant / 2;
        indice = ceil(indice);
    }

    return indice;
}

nodo_lista_doble * borrarNodoListaDobleOrdenada(nodo_lista_doble* lista, float indice)
{
    int pos = 1;
    nodo_lista_doble* ante;
    nodo_lista_doble* seg = lista;

    if(seg != NULL)
    {
        while(pos < indice)
        {
            ante = seg;
            seg = seg->siguiente;
            pos++;
        }

        if(seg != NULL)
        {
            if(ante != NULL)
            {
                ante->siguiente = seg->siguiente;

                if(seg->siguiente != NULL)
                {
                    seg->siguiente->anterior = ante;
                }

                free(seg);
            }
            else
            {
               lista = seg->siguiente;
               lista->anterior = NULL;
               free(seg);
            }
        }
    }
    else
    {
       printf("La lista esta vacia. \n");
    }

    return lista;
}

