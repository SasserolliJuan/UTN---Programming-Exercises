#include "Pila_Con_Listas_PS.h"
#include "st_lista_simple.h"

// PROTOTIPADOS

// Generales:
void menu(FILE *, nodo_lista_simple *, Pila *);

// Ejercicio 1:
void cargaDeArchivo(FILE *, char[], int);
void leerDatosEInsertarEnLista(FILE *, char[], nodo_lista_simple *);

// Ejercicio 2:
void leerDatosEInsertarEnListaOrdenada(FILE *, char[], nodo_lista_simple *);

// Ejercicio 3:
int busquedaNodo(nodo_lista_simple *);

// Ejercicio 4:
nodo_lista_simple *cargaYmuestraDeListas(nodo_lista_simple *);
nodo_lista_simple *ordenacionDeListas(nodo_lista_simple *);

// Ejercicio 7:
void recorrerYordenarPilaConParesEnTope(Pila *, int);
void eliminarValoresMenoresA10(Pila *, int);

int main() {
  nodo_lista_simple *lista;
  lista = inic_lista_simple();
  FILE *arch = fopen("arch", "wb");
  Pila *pila;
  inicpila(&pila);
  menu(arch, lista, pila);
}

void menu(FILE *arch, nodo_lista_simple *lista, Pila *pila) 
{
  int opcion = 0;

  printf("Elija un ejercicio...\n");

  system("pause");
  system("cls");

  printf("1. Hacer un programa que lea de un archivo datos y los inserte en "
         "una lista.\n");
  printf("2. Hacer un programa que lea de un archivo datos y los inserte en "
         "una lista en forma ordenada. \n");
  printf("3. Hacer una funcion que retorne un 1 (uno) o 0 (cero) si existe un "
         "determinado elemento en una lista dada. \n");
  printf("4. Hacer una funcion que intercale en orden los elementos de dos "
         "listas ordenadas generando una nueva lista. Se deben redireccionar "
         "los punteros, no se deben crear nuevos nodos. \n");
  printf("6. Invertir los elementos de una lista redireccionando solamente los "
         "punteros(No se deben crear nuevos nodos). \n");
  printf("7. Utilizando el TDA Pila creado en el punto 5, cargar la pila con "
         "numeros enteros. A) Luego, recorrer dicha pila e insertar por orden "
         "de llegada (al final) en una lista simplemente enlazada aquellos "
         "numeros que sean pares. Cuidado, la funcion no debe perder la pila "
         "original, trabaje de forma tal que se conserven sus datos. B) "
         "Eliminar de la lista cargada en el ejercicio anterior, aquellos "
         "nodos que contengan valores menores a 10. \n");
  printf("\n");
  fflush(stdin);
  scanf("%i", &opcion);

  system("cls");

  switch (opcion) 
  {
  case 1: 
  {
    char nombreArchivo[20];
    int cant = 0;
    printf("Ingrese el nombre del archivo: \n");
    fflush(stdin);
    gets(nombreArchivo);
    printf("Ingrese la cantidad de datos a cargar en el archivo: \n");
    fflush(stdin);
    scanf("%i", &cant);
    cargaDeArchivo(arch, nombreArchivo, cant);
    leerDatosEInsertarEnLista(arch, nombreArchivo, lista);
    break;
  }
  case 2: 
  {
    char nombreArchivo[20];
    int cant = 0;
    printf("Ingrese el nombre del archivo: \n");
    fflush(stdin);
    gets(nombreArchivo);
    printf("Ingrese la cantidad de datos a cargar en el archivo: \n");
    fflush(stdin);
    scanf("%i", &cant);
    cargaDeArchivo(arch, nombreArchivo, cant);
    leerDatosEInsertarEnListaOrdenada(arch, nombreArchivo, lista);
    break;
  }
  case 3: 
  {
    int elementoBuscado = 0;
    lista = cargar_lista_simple(lista);
    mostrar_lista_simple(lista);
    printf("Ingrese el dato a buscar: ");
    fflush(stdin);
    scanf("%i", &elementoBuscado);
    int rta = existe_elemento_en_lista(lista, elementoBuscado);

    if (rta == 1) {
      printf("El elemento %d existe en la lista.\n", elementoBuscado);
    } else {
      printf("El elemento %d no existe en la lista.\n", elementoBuscado);
    }
    break;
  }
  case 4: {
    printf("Lista 1: \n");
    printf("Desordenada: \n");
    lista = cargaYmuestraDeListas(lista);
    printf("Ordenada: \n");
    lista = ordenacionDeListas(lista);

    printf("\nLista 2: \n");
    nodo_lista_simple *lista2;
    lista2 = inic_lista_simple();

    printf("Desordenada: \n");
    lista2 = cargaYmuestraDeListas(lista2);
    printf("Ordenada: \n");
    lista2 = ordenacionDeListas(lista2);

    printf("\nLista 3: \n");
    nodo_lista_simple *listaAux = inic_lista_simple();
    listaAux = intercalarListasOrdenadas(lista, lista2);
    mostrar_lista_simple(listaAux);
    break;
  }
  case 5: {
    printf("Este ejercicio se ha creado aparte como un TDA. No 'existe' en el "
           "presente main. \n");
    break;
  }
  case 6: {
    lista = cargaYmuestraDeListas(lista);
    printf("\nLista invertida: \n");
    lista = invertirListaSimple(lista);
    mostrar_lista_simple(lista);
    break;
  }
  case 7: {
    Pila *pilaAux;
    inicpila(&pilaAux);
    int dato = 0, datoComp = 0, datoComp2 = 0, cantNodos = 0, i = 0;

    printf("Cargue la pila 'original': \n");
    printf("Cuantos nodos desea ingresar?: ");
    fflush(stdin);
    scanf("%i", &cantNodos);
    printf("Ingrese los datos de los nodos: \n");

    while (i < cantNodos) {
      fflush(stdin);
      scanf("%i", &dato);

      apilar(&pila, dato);
      i++;
    }

    int topOg = tope(&pila);
    int flag = 0;
    dato = 0;
    int top = tope(&pila);
    printf("Ingrese los datos de los nodos (escribir 99 para salir): \n");

    while (dato != 99) {

      fflush(stdin);
      scanf("%i", &dato);

      if (dato != 99) {
        apilar(&pila, dato);
      }
    }

    recorrerYordenarPilaConParesEnTope(&pila, topOg);
    mostrar(&pila);
    eliminarValoresMenoresA10(&pila, topOg);
    mostrar(&pila);
    break;
  }
  default: {
    break;
  }
  }
}

// EJERCICIO 1:
void cargaDeArchivo(FILE *arch, char nombreArchivo[], int cant) {
  int num = 0;
  arch = fopen(nombreArchivo, "wb");

  if (arch != NULL) {
    printf("Ingrese los datos al archivo: \n");

    for (int i = 0; i < cant; i++) {
      fflush(stdin);
      scanf("%i", &num);
      fwrite(&num, sizeof(int), 1, arch);
    }

    fclose(arch);
  } else {
    printf("No se pudo abrir el archivo para escritura. \n");
  }
}

void leerDatosEInsertarEnLista(FILE *arch, char nombreArchivo[],
                               nodo_lista_simple *lista) {
  int aux = 0;

  arch = fopen(nombreArchivo, "rb");

  if (arch != NULL) {
    nodo_lista_simple *nuevoNodo = lista;

    while (fread(&aux, sizeof(int), 1, arch) != 0) {
      nuevoNodo = crear_nodo_lista_simple(aux);
      lista = insertar_nodo_lista_simple_al_principio(lista, nuevoNodo);
    }

    printf("\n");
    mostrar_lista_simple(lista);

    fclose(arch);
  } else {
    printf("No se pudo abrir el archivo para lectura y escritura. \n");
  }
}

// EJERCICIO 2:
void leerDatosEInsertarEnListaOrdenada(FILE *arch, char nombreArchivo[],
                                       nodo_lista_simple *lista) {
  int aux = 0;
  arch = fopen(nombreArchivo, "rb");

  if (arch != NULL) {
    nodo_lista_simple *nuevoNodo;

    while (fread(&aux, sizeof(int), 1, arch) != 0) {
      nuevoNodo = crear_nodo_lista_simple(aux);
      lista = insertar_nodo_lista_simple_al_principio(lista, nuevoNodo);
    }

    printf("\n");
    lista = ordenar_lista_seleccion(lista);
    mostrar_lista_simple(lista);

    fclose(arch);
  } else {
    printf("No se pudo abrir el archivo para lectura. \n");
  }
}

// EJERCICIO 3:
int existe_elemento_en_lista(nodo_lista_simple *lista, int elemento) {
  int rta;

  while (lista != NULL) {
    if (lista->dato == elemento) {
      rta = 1; // El elemento existe en la lista.
      lista = lista->siguiente;
    } else if (lista->dato != elemento) {
      lista = lista->siguiente;
    } else if (lista == NULL) {
      rta = 0;
    }
  }

  return rta; // El elemento no se encontr� en la lista.
}

// EJERCICIO 4:
nodo_lista_simple *cargaYmuestraDeListas(nodo_lista_simple *lista) {
  lista = cargar_lista_simple(lista);
  mostrar_lista_simple(lista);

  return lista;
}

nodo_lista_simple *ordenacionDeListas(nodo_lista_simple *lista) {
  lista = ordenar_lista_seleccion(lista);
  mostrar_lista_simple(lista);

  return lista;
}

// EJERCICIO 7:
void recorrerYordenarPilaConParesEnTope(Pila *pila, int topOg) {
  Pila *pilaAux;
  Pila *pilaAux2;
  inicpila(&pilaAux);
  inicpila(&pilaAux2);

  int topWb = tope(pila);

  while (topWb !=
         topOg) // Desapila hasta dejar la pila con los elementos originales.
  {
    apilar(&pilaAux, desapilar(pila));
    topWb = tope(
        pila); // Va actualizando el tope de la pila actual para ir avanzando.
  }

  while (!pilavacia(&pilaAux)) // Mientras la pila auxiliar NO est� vac�a...
  {
    if (tope(&pilaAux) % 2 == 1) // Si el tope de la pila auxiliar es impar, lo
                                 // pasa a la pila original.
    {
      apilar(pila, desapilar(&pilaAux));
    } else // Si el tope es par, lo pasa a la 2da pila auxiliar. As�, se van
           // dejando todos los pares en una sola pila. Mientras ue se van
           // pasando los impares a la actual.
    {
      apilar(&pilaAux2, desapilar(&pilaAux));
    }
  }

  while (!pilavacia(&pilaAux2)) // Pasa todos los pares de vuelta a la auxiliar
                                // 1 para conservar el orden original cuando se
                                // los pase de vuelta a la pila actual.
  {
    apilar(&pilaAux, desapilar(&pilaAux2));
  }

  while (!pilavacia(&pilaAux)) {
    apilar(pila, desapilar(&pilaAux));
  }
}

void eliminarValoresMenoresA10(Pila *pila, int topOg) {
  Pila *pilaAux;
  Pila *pilaAux2;
  inicpila(&pilaAux);
  inicpila(&pilaAux2);

  int topWb = tope(pila);

  while (topWb !=
         topOg) // Desapila hasta dejar la pila con los elementos originales.
  {
    apilar(&pilaAux, desapilar(pila));
    topWb = tope(
        pila); // Va actualizando el tope de la pila actual para ir avanzando.
  }

  while (!pilavacia(&pilaAux)) // Minetras la pila auxiliar NO est� vac�a...
  {
    if (tope(&pilaAux) < 10) // Si el tope de la pila auxiliar es menor a 10, lo
                             // apila en la 2da pila auxiliar.
    {
      apilar(&pilaAux2, desapilar(&pilaAux));
    } else {
      apilar(pila,
             desapilar(
                 &pilaAux)); // Si el tope de la pila auxiliar es mayor o igual
                             // a 10, lo vuelve a apilar en la pila actual.
    }
  }
}

/*
NodoListaSimple* insertarAlFinal(NodoListaSimple* lista, int dato) {
    NodoListaSimple* nuevoNodo =
(NodoListaSimple*)malloc(sizeof(NodoListaSimple)); nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (lista == NULL) {
        return nuevoNodo;
    }

    NodoListaSimple* actual = lista;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevoNodo;

    return lista;
}

int main() {
    Pila pila;
    inicializarPila(&pila);

    // Simula la carga de la pila con n�meros enteros
    // Puedes implementar tu propia l�gica para cargar la pila
    // Aqu� se agrega manualmente un ejemplo
    for (int i = 1; i <= 10; i++) {
        pila.tope = insertarAlFinal(pila.tope, i);
    }

    NodoListaSimple* listaSimple = inicializarLista();

    // Recorrer la pila y agregar n�meros pares a la lista enlazada simple
    NodoListaSimple* pilaActual = pila.tope;
    while (pilaActual != NULL) {
        if (pilaActual->dato % 2 == 0) {
            listaSimple = insertarAlFinal(listaSimple, pilaActual->dato);
        }
        pilaActual = pilaActual->siguiente;
    }

    // Imprimir la lista enlazada simple con n�meros pares
    NodoListaSimple* listaActual = listaSimple;
    printf("N�meros pares en la lista: ");
    while (listaActual != NULL) {
        printf("%d ", listaActual->dato);
        listaActual = listaActual->siguiente;
    }
    printf("\n");

    // Limpieza de memoria (liberar nodos)
    while (listaSimple != NULL) {
        NodoListaSimple* temp = listaSimple;
        listaSimple = listaSimple->siguiente;
        free(temp);
    }

    return 0;
}
*/
