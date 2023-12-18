#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct automovil
{
    char patente[6];
    int valor;
    char marca[10];
} automovil;

typedef struct nodoAuto
{
    automovil dato;
    struct nodoAuto *siguiente;
} nodoAuto;

// PROTOTIPADOS

// Funciones Auxiliares:
void iniclista(nodoAuto **lista);

// Ejercicio 1:
nodoAuto *crearNodo(automovil autom);
nodoAuto *buscarUltimo(nodoAuto **);

// Ejercicio 2:
void agregarFinal(nodoAuto **lista, nodoAuto *nuevoNodo);

// Ejercicio 3:
int insertarCelda(automovil A[], int dim, automovil dato, int validos);

// Ejercicio 4:
void agregarMuchos(nodoAuto **lista);
void recorrerYmostrarLista(nodoAuto *);

// Ejercicio 5:
int pasar(nodoAuto *lista, automovil A[], int dim);
void imprimir(automovil A[], int i);

// Ejercicio 6:
void mostrarArregloRecursivo(automovil A[], int i, int pos);
void cargarLista(nodoAuto **, automovil *);

// Ejercicio 7:
int esPatentePar(const char *patente);
void imprimirLaSuma(nodoAuto *lista, int esElUltimo);
int sumarValoresPatentesParesRecursivo(nodoAuto *lista);
void recorrerYmostrarListaPares(nodoAuto *lista);

int main()
{
    nodoAuto *lista = NULL;

    int opcion = 0;
    char continuar;

    int dim = 10;
    automovil A[dim];
    int validos = 0;
    int i = 0;
    int suma = 0;
    int patPar = -1;

    do
    {
        printf("1. Agregar automoviles a la lista. \n");
        printf("2. Mostrar lista de automoviles. \n");
        printf("3. Pasar automoviles de lista a arreglo y mostrarlo. \n");
        printf("4. Suma de valores de los automoviles. \n");
        printf("\tOpcion: ");
        fflush(stdin);
        scanf("%i", &opcion);

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            agregarMuchos(&lista);
            break;
        }
        case 2:
        {
            recorrerYmostrarLista(lista);
            break;
        }
        case 3:
        {
            validos = pasar(lista, A, dim);
            mostrarArregloRecursivo(A, i, validos - 1);
            break;
        }
        case 4:
        {

            printf("Suma valores de los valores de patentes pares: \n");
            recorrerYmostrarListaPares(lista);
            suma = sumarValoresPatentesParesRecursivo(lista);
            printf("= %d\n", suma);
            break;
        }
        default:
        {
            printf("Opcion no valida. Saliendo...\n");
            system("cls");
            break;
        }
        }

        printf("Volver al menu principal?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        system("cls");

    } while ((continuar == 's') || (continuar == 'S'));

    system("pause");
}

// FUNCIONES AUXILIARES:
void iniclista(nodoAuto **lista)
{
    *lista = NULL;
}

// EJERCICIO 1:
nodoAuto *crearNodo(automovil autom)
{
    nodoAuto *aux = (nodoAuto *)malloc(sizeof(nodoAuto));

    aux->dato = autom;

    aux->siguiente = NULL;

    return aux;
}

// EJERCICIO 2:
void agregarFinal(nodoAuto **lista, nodoAuto *nuevoNodo)
{
    if (*lista == NULL)
    {
        *lista = nuevoNodo;
    }
    else
    {
        nodoAuto *actual = *lista;

        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// EJERCICIO 4:
void agregarMuchos(nodoAuto **lista)
{
    char continuar = 's';

    do
    {
        automovil autom;
        printf("Ingrese los datos del automovil: \n");
        printf("Patente: ");
        fflush(stdin);
        scanf("%s", autom.patente);

        printf("Valor: ");
        fflush(stdin);
        scanf("%i", &autom.valor);

        printf("Marca: ");
        fflush(stdin);
        scanf("%s", autom.marca);

        nodoAuto *aux = crearNodo(autom);

        agregarFinal(lista, aux);

        printf("Desea seguir cargando automoviles?: \n");
        fflush(stdin);
        scanf(" %c", &continuar);

    } while ((continuar == 's') || (continuar == 'S'));
}

void recorrerYmostrarLista(nodoAuto *lista)
{
    nodoAuto *seg = lista;

    while (seg != NULL)
    {
        printf("Patente: %s \n", seg->dato.patente);
        printf("Valor: %i \n", seg->dato.valor);
        printf("Marca: %s \n", seg->dato.marca);
        printf("\n");

        seg = seg->siguiente;
    }
}

// EJERCICIO 3:
int insertarCelda(automovil A[], int dim, automovil dato, int validos)
{
    int i = validos;

    while (i > 0 && dato.valor < A[i - 1].valor)
    {
        A[i] = A[i - 1];
        i--;
    }

    A[i] = dato;

    return validos + 1;
}

// EJERCICIO 5:
int pasar(nodoAuto *lista, automovil A[], int dim)
{
    int validos = 0;
    nodoAuto *actual = lista;

    while (actual != NULL && validos < dim)
    {
        validos = insertarCelda(A, dim, actual->dato, validos);
        actual = actual->siguiente;
    }

    return validos;
}

void imprimir(automovil A[], int i)
{
    printf("Patente: %s \n", A[i].patente);
    printf("Valor: %i \n", A[i].valor);
    printf("Marca: %s \n", A[i].marca);
    printf("\n");
}

// EJERCICIO 6:
void mostrarArregloRecursivo(automovil A[], int i, int pos)
{
    if (i <= pos)
    {
        imprimir(A, i);
        mostrarArregloRecursivo(A, i + 1, pos);
    }
}

// EJERCICIO 7:
int esPatentePar(const char *patente)
{
    int len = strlen(patente);
    if (len < 2)
    {
        return -1;
    }

    char penultimoCaracter = patente[len - 2];
    char ultimoCaracter = patente[len - 1];

    if ((penultimoCaracter >= '0' && penultimoCaracter <= '9') && (ultimoCaracter >= '0' && ultimoCaracter <= '9'))
    {
        int numero = (penultimoCaracter - '0') * 10 + (ultimoCaracter - '0');
        return (numero % 2 == 0);
    }
    else
    {
        printf("Los últimos dos caracteres de la patente no son dígitos\n");
        return -1;
    }
}

void imprimirLaSuma(nodoAuto *lista, int esElUltimo)
{
    if (esElUltimo)
    {
        printf("%d ", lista->dato.valor);
    }
    else
    {
        printf("%d + ", lista->dato.valor);
    }
}

int sumarValoresPatentesParesRecursivo(nodoAuto *lista)
{
    if (lista == NULL)
    {
        return 0; // Caso base: lista vacía
    }
    else
    {
        int esPar = esPatentePar(lista->dato.patente);
        if (esPar == -1)
        {
            return sumarValoresPatentesParesRecursivo(lista->siguiente);
        }
        else if (esPar == 1)
        {
            imprimirLaSuma(lista, lista->siguiente == NULL);
            return lista->dato.valor + sumarValoresPatentesParesRecursivo(lista->siguiente);
        }
        else
        {
            return sumarValoresPatentesParesRecursivo(lista->siguiente);
        }
    }
}

void recorrerYmostrarListaPares(nodoAuto *lista)
{
    nodoAuto *seg = lista;

    while (seg != NULL)
    {
        if (esPatentePar(seg->dato.patente) == 1)
        {
            printf("Patente: %s \n", seg->dato.patente);
            printf("Valor: %i \n", seg->dato.valor);
            printf("Marca: %s \n", seg->dato.marca);
            printf("\n");
        }

        seg = seg->siguiente;
    }
}