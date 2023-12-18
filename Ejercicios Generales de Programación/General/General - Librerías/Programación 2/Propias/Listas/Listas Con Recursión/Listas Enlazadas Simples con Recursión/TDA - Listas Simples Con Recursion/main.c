#include "Listas_Simples_Con_Recursion.h"

int main()
{
    printf("Hello listas con recursion!\n");

    nodo_lista_simple *lista = inic_lista_simple();
    nodo_lista_simple *nuevo;

    int i = 0;

    for(i = 1; i < 11; i++)
    {
        nuevo = crear_nodo_lista_simple(i);
        lista = insertar_nodo_lista_simple_al_final(lista, nuevo);
    }

    printf("\nContenido de la lista:\n");
    mostrar_lista_simple(lista);

    printf("\nContenido de la lista invertido (llamando a la funcion que la muestra invertida): \n");
    mostrarListaInvertidaR(lista);

    int suma = sumaContenidoListaR(lista);
    printf("\nLa suma de la lista es: %d \n",suma);

    printf("\nContenido de la lista en las posiciones pares: \n");
    //muestraPosParR(lista,0);
    otroMuestraPosPar(lista);

    lista = invertirRecursivo(lista);
    printf("\n\nContenido de la lista despues de invertirla: \n");
    mostrar_lista_simple(lista);

    lista = borrarNodoR(lista, 5);
    printf("\nContenido de la lista despues de borrar un dato: \n");
    mostrar_lista_simple(lista);

    lista = invertirRecursivo(lista);

    lista = insertarEnOrdenR(lista, crear_nodo_lista_simple(4));
    printf("\nContenido de la lista despues de insertar un dato: \n");
    mostrar_lista_simple(lista);
    return 0;
}
