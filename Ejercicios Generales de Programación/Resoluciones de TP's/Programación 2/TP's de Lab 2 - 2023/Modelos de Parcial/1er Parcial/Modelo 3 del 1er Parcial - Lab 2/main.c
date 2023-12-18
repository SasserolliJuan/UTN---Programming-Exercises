#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ESTRUCTURAS
typedef struct
{
    int dni;
    char nombre_apellido[30];
    int edad;
    char equipo[30];
} player;

typedef struct _nodoPlayer
{
    player p;
    struct _nodoPlayer *sig;
} nodoPlayer;

// PROTOTIPADOS:

// Ejercicio 1:
int cargaArreglo(player A[], int *validos);
void escribir(player A[], int i);
void mostrarArregloRecursivo(player A[], int validos, int i);

// Ejercicio 2:
nodoPlayer *inicLista();
nodoPlayer *crearNodo(player p);

// Ejercicio 3:
void insertInOrder(nodoPlayer **lista, nodoPlayer *nuevo);

// Ejercicio 4:
void *arreglo2Lista(player A[], nodoPlayer **lista, int validos);
void escribirLista(nodoPlayer *lista);

// Ejercicio 5:
void mostrarListaRecursivaConCondicionDeEdad(nodoPlayer *lista);
void mostrarListaRecursiva(nodoPlayer *lista);

// Ejercicio 6:
int buscarMayorEdad(nodoPlayer *lista, int edadMy, int dniPlayerMyEdad);

// Ejercicio 7:
nodoPlayer *pasarDeListaToLista(nodoPlayer *listaVieja, nodoPlayer *listaNueva, char equipo[]);

int main()
{
    int opcion = 0;
    char continuar = 's';
    nodoPlayer *lista = inicLista();
    nodoPlayer *listaAux = inicLista();
    player A[10];
    int validos = 0;

    printf("Elija un ejercicio...\n");

    system("pause");
    system("cls");
    do
    {
        printf("1. Cargar y mostrar arreglo recursivo. \n");
        printf("2. Pasar datos del arreglo a una lista y mostrar la lista recursiva. \n");
        printf("3. Buscar mayor edad y retornar el dni del player. \n");
        printf("4. Pasar datos de una lista a otra y mostrarlas. \n");
        printf("5. Salir. \n");
        printf("\n");
        fflush(stdin);
        scanf("%i", &opcion);

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            int i = 0;
            validos = cargaArreglo(A, &validos);
            printf("\n");
            mostrarArregloRecursivo(A, validos, i);
            break;
        }
        case 2:
        {
            arreglo2Lista(A, &lista, validos);
            printf("Lista ordenada de izquierda a derecha: \n");
            mostrarListaRecursiva(lista);
            printf("Lista ordenada de derecha a izquierda mayores a 25: \n");
            mostrarListaRecursivaConCondicionDeEdad(lista);
            break;
        }
        case 3:
        {
            int dni = 0, edadMy = 0, dniPlayerMyEdad = 0;
            dni = buscarMayorEdad(lista, edadMy, dniPlayerMyEdad);
            printf("El DNI del player con mayor edad es: %i \n", dni);
            break;
        }
        case 4:
        {
            char equipoABuscar[10];
            printf("Ingrese el nombre del equipo a buscar: \n");
            fflush(stdin);
            gets(equipoABuscar);

            listaAux = pasarDeListaToLista(lista, listaAux, equipoABuscar);
            printf("Lista original: \n");
            mostrarListaRecursiva(lista);
            printf("\nLista copiada: \n");
            mostrarListaRecursiva(listaAux);
            break;
        }
        case 5:
        {
            printf("Saliendo...\n");
            break;
        }
        default:
        {
            printf("Opcion no valida. Saliendo...\n");
            break;
        }
        }

        system("pause");
        printf("Desea volver al menu principal?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        system("cls");

    } while ((continuar == 's' || continuar == 'S'));
}

nodoPlayer *inicLista()
{
    return NULL;
}

// EJERCICIO 1:
int cargaArreglo(player A[], int *validos)
{
    int i = 0;
    char continuar = 's';

    while ((continuar == 's') || (continuar == 'S') && i < 10)
    {
        printf("DNI: \n");
        fflush(stdin);
        scanf("%i", &A[i].dni);

        printf("NOMBRE Y APELLIDO: \n");
        fflush(stdin);
        gets(A[i].nombre_apellido);

        printf("EDAD: \n");
        fflush(stdin);
        scanf("%i", &A[i].edad);

        printf("EQUIPO: \n");
        fflush(stdin);
        gets(A[i].equipo);

        (*validos)++;
        i++;

        printf("Desea seguir cargando datos al arreglo?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    return *validos;
}

void escribir(player A[], int i)
{
    printf("DNI: %i\n", A[i].dni);
    printf("NOMBRE Y APELLIDO: %s\n", A[i].nombre_apellido);
    printf("EDAD: %i\n", A[i].edad);
    printf("EQUIPO: %s\n", A[i].equipo);
}

void mostrarArregloRecursivo(player A[], int validos, int i)
{
    if (i < validos)
    {
        escribir(A, i);
        mostrarArregloRecursivo(A, validos, i + 1);
        printf("\n");
    }
}

// EJERCICIO 2:
nodoPlayer *crearNodo(player p)
{
    nodoPlayer *aux = (nodoPlayer *)malloc(sizeof(nodoPlayer));

    aux->p = p;
    aux->sig = NULL;

    return aux;
}

// EJERCICIO 3:
void insertInOrder(nodoPlayer **lista, nodoPlayer *nuevo)
{
    if (*lista == NULL) // Cuando la lista está vacía.
    {
        *lista = nuevo;
    }
    else
    {
        if (nuevo->p.dni < (*lista)->p.dni) // Cuando el dato del nuevo nodo es menor al del primer nodo de la lista.
        {
            nuevo->sig = *lista;
            *lista = nuevo;
        }
        else // Cuando el dato del nuevo nodo es mayor al del primero, se busca el hueco para insertar.
        {
            nodoPlayer *ante = *lista;
            nodoPlayer *seg = (*lista)->sig;

            while ((seg != NULL) && (nuevo->p.dni > seg->p.dni))
            {
                ante = seg;
                seg = seg->sig;
            }
            ante->sig = nuevo;
            nuevo->sig = seg;
        }
    }
}

// EJERCICIO 4:
void *arreglo2Lista(player A[], nodoPlayer **lista, int validos)
{
    int i = 0;

    while (i < validos)
    {
        nodoPlayer *aux = crearNodo(A[i]);
        insertInOrder(lista, aux);
        i++;
    }
}

void escribirLista(nodoPlayer *lista)
{
    printf("DNI: %i\n", lista->p.dni);
    printf("NOMBRE Y APELLIDO: %s\n", lista->p.nombre_apellido);
    printf("EDAD: %i\n", lista->p.edad);
    printf("EQUIPO: %s\n", lista->p.equipo);
}

// EJERCICIO 5:
void mostrarListaRecursivaConCondicionDeEdad(nodoPlayer *lista)
{
    if (lista != NULL)
    {
        mostrarListaRecursivaConCondicionDeEdad(lista->sig);

        if (lista->p.edad > 25)
        {
            escribirLista(lista);
            printf("\n");
        }
    }
}

void mostrarListaRecursiva(nodoPlayer *lista)
{
    if (lista != NULL)
    {
        escribirLista(lista);
        printf("\n");
        mostrarListaRecursiva(lista->sig);
    }
}

// EJERCICIO 6:
int buscarMayorEdad(nodoPlayer *lista, int edadMy, int dniPlayerMyEdad)
{
    if (lista != NULL)
    {
        if (lista->p.edad > edadMy)
        {
            edadMy = lista->p.edad;
            dniPlayerMyEdad = lista->p.dni;
        }

        dniPlayerMyEdad = buscarMayorEdad(lista->sig, edadMy, dniPlayerMyEdad);
    }

    return dniPlayerMyEdad;
}

// EJERCICIO 7:
nodoPlayer *pasarDeListaToLista(nodoPlayer *listaVieja, nodoPlayer *listaNueva, char equipo[])
{
    while (listaVieja != NULL)
    {
        if (strcmp(listaVieja->p.equipo, equipo) == 0)
        {
            nodoPlayer *aux = crearNodo(listaVieja->p);
            insertInOrder(&listaNueva, aux);
        }

        listaVieja = listaVieja->sig;
    }

    return listaNueva;
}