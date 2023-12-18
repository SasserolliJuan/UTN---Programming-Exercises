#include "st_lista_simple.h"
#include "st_lista_doble.h"
#include <time.h>

// PROTOTIPADOS:

nodo_lista_simple *crearNodo(int dato);
nodo_lista_simple *cargarRandomsListaSimple(nodo_lista_simple *lista);
nodo_lista_simple *cargarFinal(nodo_lista_simple *lista, nodo_lista_simple *nuevoNodo);
void mostrarListaIzqADer(nodo_lista_simple *lista);
void mostrarListaDerAIzq(nodo_lista_simple *lista);
int cantNodos(nodo_lista_simple *lista);
nodo_lista_simple *borrarNodoPorPos(nodo_lista_simple *lista, int pos, int posMax);
nodo_lista_simple *borrarNodosMayoresAX(nodo_lista_simple *lista, int dato);
nodo_lista_doble *agregarOrdenado(nodo_lista_doble *lista, nodo_lista_doble *nuevoNodo);
nodo_lista_doble *pasarNodosListaSimpleAListaDobleOrdenada(nodo_lista_simple **listaSimple, nodo_lista_doble *listaDoble);

int main()
{
  int opcion = 0;
  char continuar = 's';
  srand(time(NULL));
  nodo_lista_simple *lista = inic_lista_simple();
  nodo_lista_doble *listaD = inic_lista_doble();

  printf("Elija un ejercicio...\n");

  system("pause");
  system("cls");

  do
  {
    printf("1. Cargar lista con enteros. \n");
    printf("2. Mostrar lista. \n");
    printf("3. Cantidad de nodos. \n");
    printf("4. Eliminar un nodo segun una posicion dada. \n");
    printf("5. Eliminar nodos mayores a un valor dado. \n");
    printf("6. Modificar funcion 'agregarNodoD' para listas dobles. \n");
    printf("7. Pasar valores de una lista simple a una lista doble. \n");
    printf("8. Salir. \n");
    printf("\n");
    printf("Opcion: \n");
    fflush(stdin);
    scanf("%i", &opcion);

    switch (opcion)
    {
    case 1:
    {
      lista = cargarRandomsListaSimple(lista);
      break;
    }
    case 2:
    {
      int opcionMostrar = 0;
      printf("De que forma quiere ver la lista?: (1 = Izq a Der) - (2 = Der a Izq). \n");
      fflush(stdin);
      scanf("%i", &opcionMostrar);

      switch ((opcionMostrar))
      {
      case 1:
      {
        mostrarListaIzqADer(lista);
        break;
      }
      case 2:
      {
        mostrarListaDerAIzq(lista);
        break;
      }
      default:
      {
        break;
      }
      }

      break;
    }
    case 3:
    {
      int cant = 0;
      cant = cantNodos(lista);
      printf("La lista tiene %i nodos. \n", cant);
      break;
    }
    case 4:
    {
      int pos = 0, cant = 0;
      cant = cantNodos(lista);

      printf("Ingrese la posicion del nodo a eliminar: ");
      fflush(stdin);
      scanf("%i", &pos);
      lista = borrarNodoPorPos(lista, pos, cant);
      mostrarListaIzqADer(lista);
      break;
    }
    case 5:
    {
      int valorCriterio = 0;
      printf("Ingrese un dato para eliminar los nodos que contengan valores mayores a ese dato. \n");
      fflush(stdin);
      scanf("%i", &valorCriterio);
      lista = borrarNodosMayoresAX(lista, valorCriterio);
      mostrar_lista_simple(lista);
      break;
    }
    case 6:
    {
      printf("Hecho en forma de TDA. Este ejercicio no existe en este main. \n");
      break;
    }
    case 7:
    {
      listaD = pasarNodosListaSimpleAListaDobleOrdenada(&lista, listaD);
      printf("Lista original: \n");
      mostrarListaIzqADer(lista);
      printf("Lista doble ordenada: \n");
      mostrar_lista_doble(listaD);
      printf("\n");
      break;
    }
    case 8:
    {
      system("cls");
      printf("Saliendo...\n");
      system("pause");
      break;
    }
    }

    printf("Desea volver al menu?: s/n\n");
    fflush(stdin);
    scanf("%c", &continuar);
    system("cls");

  } while ((continuar == 's' || continuar == 'S'));

  system("pause");
}

nodo_lista_simple *crearNodo(int dato)
{
  nodo_lista_simple *aux =
      (nodo_lista_simple *)malloc(sizeof(nodo_lista_simple));

  aux->dato = dato;
  aux->siguiente = NULL;

  return aux;
}

nodo_lista_simple *cargarFinal(nodo_lista_simple *lista, nodo_lista_simple *nuevoNodo)
{
  if (lista == NULL)
  {
    lista = nuevoNodo;
  }
  else
  {
    nodo_lista_simple *ultimo = lista;

    while (ultimo->siguiente != NULL)
    {
      ultimo = ultimo->siguiente;
    }

    ultimo->siguiente = nuevoNodo;
  }

  return lista;
}

nodo_lista_simple *cargarRandomsListaSimple(nodo_lista_simple *lista)
{
  char continuar = 's';

  do
  {
    int datoNodo = 0;
    datoNodo = (rand() % 20) + 1;
    printf("Dato del nodo ingresado automaticamente. \n");

    nodo_lista_simple *aux = crearNodo(datoNodo);
    lista = cargarFinal(lista, aux);

    printf("Desea continuar?: s/n\n");
    fflush(stdin);
    scanf("%c", &continuar);

  } while ((continuar == 's') || (continuar == 'S'));

  return lista;
}

void mostrarListaIzqADer(nodo_lista_simple *lista)
{
  while (lista != NULL)
  {
    printf("%i \n", lista->dato);
    lista = lista->siguiente;
  }
}

void mostrarListaDerAIzq(nodo_lista_simple *lista)
{
  nodo_lista_simple *ante = lista;

  if (lista != NULL)
  {
    mostrarListaDerAIzq(lista->siguiente);
    printf("%i \n", lista->dato);
  }
}

int cantNodos(nodo_lista_simple *lista)
{
  int cantNodos = 0;

  while (lista != NULL)
  {
    cantNodos++;
    lista = lista->siguiente;
  }

  return cantNodos;
}

nodo_lista_simple *borrarNodoPorPos(nodo_lista_simple *lista, int pos, int posMax)
{
  if (lista == NULL || pos <= 0 || pos > posMax)
  {
    printf("Error. Posicion no valida. \n");
  }
  else if (pos == 1)
  {
    nodo_lista_simple *aux = lista;
    lista = lista->siguiente;
    free(aux);
  }
  else
  {
    int i = 1;
    nodo_lista_simple *ante;
    nodo_lista_simple *seg = lista;

    while (i < pos)
    {
      ante = seg;
      seg = seg->siguiente;
      i++;
    }

    ante->siguiente = seg->siguiente;
  }

  return lista;
}

nodo_lista_simple *borrarNodosMayoresAX(nodo_lista_simple *lista, int dato)
{
  nodo_lista_simple *ante = NULL;
  nodo_lista_simple *seg = lista;
  nodo_lista_simple *nuevoInicio = lista; // Mantenemos un nuevo inicio de lista

  while (seg != NULL)
  {
    if (seg->dato >= dato)
    {
      if (ante == NULL) // El nodo a eliminar es el primer nodo de la lista
      {
        nodo_lista_simple *aux = seg;
        nuevoInicio = seg->siguiente;
        seg = nuevoInicio;
        free(aux);
      }
      else // Eliminar nodos en medio o al final de la lista
      {
        nodo_lista_simple *aux = seg;
        ante->siguiente = seg->siguiente;
        seg = seg->siguiente;
        free(aux);
      }
    }
    else // Si no esta vacia, se avanza al siguiente nodo
    {
      ante = seg;
      seg = seg->siguiente;
    }
  }

  return nuevoInicio;
}
// FUNCION PARA CREAR UN NODO DOBLE:

/*
nodo_lista_doble *crear_nodo_lista_doble(int dato)
{
    nodo_lista_doble *aux = (nodo_lista_doble *)malloc(sizeof(nodo_lista_doble));
    aux->anterior = inic_lista_doble();
    aux->siguiente = inic_lista_doble();
    aux->dato = dato;
    return aux;
}

*/

nodo_lista_doble *agregarOrdenado(nodo_lista_doble *lista, nodo_lista_doble *nuevoNodo)
{

  if (lista == NULL)
  {
    lista = nuevoNodo;
  }
  else
  {
    nodo_lista_doble *ante;
    nodo_lista_doble *seg = lista;

    while ((seg != NULL) && (nuevoNodo->dato > seg->dato))
    {
      ante = seg;
      seg = seg->siguiente;
    }

    ante->siguiente = nuevoNodo;
    nuevoNodo->anterior = ante;
    nuevoNodo->siguiente = seg;

    if (seg != NULL)
    {
      seg = seg->siguiente;
    }
  }

  return lista;
}

nodo_lista_doble *pasarNodosListaSimpleAListaDobleOrdenada(nodo_lista_simple **listaSimple, nodo_lista_doble *listaDoble)
{
  while (*listaSimple != NULL)
  {
    int datoAPasar = 0;
    datoAPasar = (*listaSimple)->dato;
    nodo_lista_doble *aux = crear_nodo_lista_doble(datoAPasar);
    listaDoble = agregarOrdenado(listaDoble, aux);

    nodo_lista_simple *aEliminar = *listaSimple;
    *listaSimple = (*listaSimple)->siguiente;
    free(aEliminar);
  }

  return listaDoble;
}
