#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "time.h"

// ESTRUCTURAS
typedef struct stPasajero
{
    int tipodeboleto; // 1 común, 2 jubilado, 3 estudiante
    float recorridoEnMetrosEstimado;
    float precioBoleto;
    char DNI[11];
} stPasajero;

typedef struct nodoPasajero
{
    stPasajero dato;
    struct nodoPasajero *siguiente;
} nodoPasajero;

typedef struct fila
{

    struct nodoFilaPasajero *primero;
    struct nodoFilaPasajero *ultimo;

} fila;

typedef struct nodoFilaPasajero
{
    char DNI[11];
    struct nodoFilaPasajero *siguiente;
    struct nodoFilaPasajero *anterior;
} nodoFilaPasajero;

// PROTOTIPOS

// Funciones Auxiliares
nodoPasajero *inic_lista_simple();
void inicFila(fila *fila);
nodoFilaPasajero *inic_lista_doble();

// Ejercicio 1
nodoPasajero *crearNodo(stPasajero datos);
nodoPasajero *agregarOrdenadoXRecorrido(nodoPasajero *lista, nodoPasajero *nuevoNodo);
nodoPasajero *cargar_lista_simple(nodoPasajero *lista);
void imprimir(nodoPasajero *lista);
void mostrar_lista_pasajeros(nodoPasajero *lista);

// Ejercicio 2
int verificarExistenciaPasajero(nodoPasajero *lista, char dni[]);

// Ejercicio 3
nodoPasajero *eliminarPasajeroXDNI(nodoPasajero *lista, char dni[]);

// Ejercicio 4
int contarPasajerosXTipoBoleto(nodoPasajero *lista, int tipoBoleto);

// Ejercicio 5
nodoFilaPasajero *crear_nodo_lista_doble(char dato[]);
nodoFilaPasajero *ultimo_nodo_lista_doble(nodoFilaPasajero *lista);
nodoFilaPasajero *insertar_nodo_lista_doble_al_final(nodoFilaPasajero *lista, nodoFilaPasajero *nuevo_nodo);
void agregar(fila *fila, char dato[]);

// Ejercicio 6
float calcularKilometrosTotales(nodoPasajero *lista);
float calcularCostoViajeTotal(nodoPasajero *lista, float precioLitroNafta);
nodoPasajero *buscarPasajeroPorDNI(nodoPasajero *lista, char DNI[11]);
nodoFilaPasajero *borrar_primer_nodo_lista_doble(nodoFilaPasajero *lista);
void bajarPasajeroDelColectivo(fila *filaPasajeros, float precioLitroNafta, nodoPasajero **lista);
void mostrar_fila(fila *fila);

int main()
{
    int opcion = 0;
    char continuar = 's';

    nodoPasajero *lista = inic_lista_simple();
    fila miFila;
    inic_lista_doble(&miFila);
    srand(time(NULL));

    printf("Elija un ejercicio...\n");

    system("pause");
    system("cls");

    do
    {
        printf("1.  Cargar lista de pasajeros. \n");
        printf("2.  Verificar si existe un pasajero. \n");
        printf("3.  Eliminar un pasajero. \n");
        printf("4.  Contar pasajeros por tipo de boleto. \n");
        printf("5.  Subir pasajeros al colectivo. \n");
        printf("6.  Calcular costo total del viaje. \n");
        printf("7.  Calcular Km totales recorridos. \n");
        printf("8.  Calcular ganancias del viaje. \n");
        printf("9.  Salir. \n");
        printf("\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%i", &opcion);

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            lista = cargar_lista_simple(lista);
            mostrar_lista_pasajeros(lista);
            break;
        }
        case 2:
        {
            int rta = 0;
            char dniABuscar[20];
            printf("Ingrese el DNI a buscar: ");
            fflush(stdin);
            scanf("%s", dniABuscar);
            rta = verificarExistenciaPasajero(lista, dniABuscar);

            if (rta == 1)
            {
                printf("Pasajero encontrado. \n");
            }
            else
            {
                printf("El pasajero no se encuentra a bordo. \n");
            }
            break;
        }
        case 3:
        {
            char dniABuscar[20];
            printf("Ingrese el DNI a buscar: ");
            fflush(stdin);
            scanf("%s", dniABuscar);

            lista = eliminarPasajeroXDNI(lista, dniABuscar);
            printf("Lista actualizada: \n");
            mostrar_lista_pasajeros(lista);
            break;
        }
        case 4:
        {
            int cantPas = 0;
            int tipoBoleto = 0;
            printf("Ingrese el tipo de boleto a buscar: ");

            while ((tipoBoleto != 1) && (tipoBoleto != 2) && (tipoBoleto != 3))
            {
                fflush(stdin);
                scanf("%i", &tipoBoleto);
            }

            cantPas = contarPasajerosXTipoBoleto(lista, tipoBoleto);
            printf("Hay %i pasajeros con el boleto del tipo %i\n", cantPas, tipoBoleto);

            break;
        }
        case 5:
        {
            char dniAAgregar[20];
            char continuar = 's';

            while ((continuar == 's') || (continuar == 'S'))
            {
                int rta = 0;
                printf("Ingrese el DNI a buscar: ");
                fflush(stdin);
                scanf("%s", dniAAgregar);

                rta = verificarExistenciaPasajero(lista, dniAAgregar);

                if (rta == 1)
                {
                    agregar(&miFila, dniAAgregar);
                }
                else
                {
                    printf("Error: este pasajero no existe. \n");
                }

                printf("Desea seguir subiendo pasajeros?: s/n\n");
                fflush(stdin);
                scanf("%c", &continuar);
            }

            mostrar_fila(&miFila);
            break;
        }
        case 6:
        {
            float costoTotal = 0;
            float precioXViaje = 0;

            printf("A cuanto quiere cobrar el litro de combustible?: ");
            fflush(stdin);
            scanf("%f", &precioXViaje);

            costoTotal = calcularCostoViajeTotal(lista, precioXViaje);
            printf("Se han gastado %.2f dolares para realizar el viaje. \n", costoTotal);
            break;
        }
        case 7:
        {
            float Kms = 0;
            Kms = calcularKilometrosTotales(lista);
            printf("Se han recorrido %.2f Km\n", Kms);
            break;
        }
        case 8:
        {
            float precioXViaje = 0;

            printf("A cuanto quiere cobrar el litro de combustible?: ");
            fflush(stdin);
            scanf("%f", &precioXViaje);

            bajarPasajeroDelColectivo(&miFila, precioXViaje, &lista);
            printf("\nFila actualizada: \n");
            mostrar_fila(&miFila);
            break;
        }
        case 9:
        {
            printf("Saliendo...\n");
            break;
        }
        default:
        {
            printf("Opcion no valida. Saliendo...");
            break;
        }
        }
        system("pause");
        printf("Desea volver al menu principal?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        system("cls");
    } while ((continuar == 's' || continuar == 'S'));

    system("pause");
}

// FUNCIONES AUXILIARES
nodoPasajero *inic_lista_simple()
{
    return NULL;
}

void inicFila(fila *fila)
{
    fila->primero = inic_lista_doble();
    fila->ultimo = inic_lista_doble();
}

nodoFilaPasajero *inic_lista_doble()
{
    return NULL;
}

// FUNCIONES NORMALES

// EJERCICIO 1
nodoPasajero *crearNodo(stPasajero datos)
{
    nodoPasajero *aux = (nodoPasajero *)malloc(sizeof(nodoPasajero));

    aux->dato = datos;
    aux->siguiente = NULL;

    return aux;
}

nodoPasajero *agregarOrdenadoXRecorrido(nodoPasajero *lista, nodoPasajero *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if (nuevoNodo->dato.recorridoEnMetrosEstimado < lista->dato.recorridoEnMetrosEstimado)
        {
            nuevoNodo->siguiente = lista;
            lista = nuevoNodo;
        }
        else
        {
            nodoPasajero *ante;
            nodoPasajero *seg = lista;

            while ((seg != NULL) && (nuevoNodo->dato.recorridoEnMetrosEstimado > seg->dato.recorridoEnMetrosEstimado))
            {
                ante = seg;
                seg = seg->siguiente;
            }

            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }

    return lista;
}

nodoPasajero *cargar_lista_simple(nodoPasajero *lista)
{
    char continuar = 's';

    while ((continuar == 's') || (continuar == 'S'))
    {
        stPasajero datos;
        printf("Ingrese su DNI: ");
        fflush(stdin);
        scanf("%s", datos.DNI);

        printf("Ingrese su tipo de boleto: ");
        fflush(stdin);
        scanf("%i", &datos.tipodeboleto);

        printf("Ingrese el precio del boleto: ");
        fflush(stdin);
        datos.precioBoleto = (rand() % 100) + 1;
        printf("%.2f\n", datos.precioBoleto);

        printf("Ingrese el recorrido estimado: ");
        fflush(stdin);
        datos.recorridoEnMetrosEstimado = (rand() % 100) + 1;
        printf("%.2f\n", datos.recorridoEnMetrosEstimado);

        nodoPasajero *aux = crearNodo(datos);
        lista = agregarOrdenadoXRecorrido(lista, aux);

        printf("Desea seguir cargando pasajeros?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    return lista;
}

void imprimir(nodoPasajero *lista)
{
    printf("DNI: %s\n", lista->dato.DNI);
    printf("TIPO DE BOLETO: %i\n", lista->dato.tipodeboleto);
    printf("PRECIO DEL BOLETO: %f\n", lista->dato.precioBoleto);
    printf("RECORRIDO ESTIMADO: %f\n", lista->dato.recorridoEnMetrosEstimado);
    printf("\n");
}

void mostrar_lista_pasajeros(nodoPasajero *lista)
{
    nodoPasajero *aux = lista;

    while (aux != NULL)
    {
        imprimir(aux);
        aux = aux->siguiente;
    }
}

// EJERCICIO 2
int verificarExistenciaPasajero(nodoPasajero *lista, char dni[])
{
    int rta = 0;
    nodoPasajero *seg = lista;

    while (seg != NULL)
    {
        if (strcmp(seg->dato.DNI, dni) == 0)
        {
            rta = 1;
        }
        seg = seg->siguiente;
    }

    return rta;
}

// EJERCICIO 3
nodoPasajero *eliminarPasajeroXDNI(nodoPasajero *lista, char dni[])
{
    if ((lista != NULL) && (strcmp(lista->dato.DNI, dni) == 0))
    {
        nodoPasajero *aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        nodoPasajero *ante;
        nodoPasajero *seg = lista;

        while ((seg != NULL) && (strcmp(seg->dato.DNI, dni) != 0))
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

// EJERCICIO 4
int contarPasajerosXTipoBoleto(nodoPasajero *lista, int tipoBoleto)
{
    int cant = 0;

    if (lista == NULL)
    {
        printf("Error: la lista esta vacia. \n");
    }
    else
    {
        nodoPasajero *seg = lista;

        while (seg != NULL)
        {
            if (seg->dato.tipodeboleto == tipoBoleto)
            {
                cant++;
            }
            seg = seg->siguiente;
        }
    }

    return cant;
}

// FUNCIONES CON FILA

// EJERCICIO 1
nodoFilaPasajero *crear_nodo_lista_doble(char dato[])
{
    nodoFilaPasajero *aux = (nodoFilaPasajero *)malloc(sizeof(nodoFilaPasajero));
    aux->anterior = inic_lista_doble();
    aux->siguiente = inic_lista_doble();
    strcpy(aux->DNI, dato);
    return aux;
}

nodoFilaPasajero *ultimo_nodo_lista_doble(nodoFilaPasajero *lista)
{
    nodoFilaPasajero *aux = NULL;
    if (lista)
    {
        aux = lista;
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
    }
    return aux;
}

nodoFilaPasajero *insertar_nodo_lista_doble_al_final(nodoFilaPasajero *lista, nodoFilaPasajero *nuevo_nodo)
{
    if (lista)
    {
        nodoFilaPasajero *aux = ultimo_nodo_lista_doble(lista);
        aux->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = aux;
    }
    return lista;
}

void agregar(fila *fila, char dato[])
{
    nodoFilaPasajero *nuevo = crear_nodo_lista_doble(dato);

    if (fila->primero == NULL)
    {
        fila->primero = nuevo;
        fila->ultimo = nuevo;
    }
    else
    {
        fila->primero = insertar_nodo_lista_doble_al_final(fila->primero, nuevo);
        fila->ultimo = nuevo;
    }
}

// EJERCICIO 2
float calcularKilometrosTotales(nodoPasajero *lista)
{
    float kilometrosTotales = 0;
    nodoPasajero *actual = lista;

    while (actual != NULL)
    {
        kilometrosTotales += actual->dato.recorridoEnMetrosEstimado / 1000.0;
        actual = actual->siguiente;
    }
    return kilometrosTotales;
}

float calcularCostoViajeTotal(nodoPasajero *lista, float precioLitroNafta)
{
    float costoTotal = 0;
    nodoPasajero *actual = lista;
    while (actual != NULL)
    {
        costoTotal += actual->dato.recorridoEnMetrosEstimado / 1000.0 * precioLitroNafta;
        actual = actual->siguiente;
    }
    return costoTotal;
}

nodoPasajero *buscarPasajeroPorDNI(nodoPasajero *lista, char DNI[11])
{
    char dni[20];
    nodoPasajero *actual = lista;

    while (actual != NULL)
    {
        if (strcmp(actual->dato.DNI, DNI) == 0)
        {
            printf("Pasajero encontrado. \n");
        }
        actual = actual->siguiente;
    }
    return actual;
}

nodoFilaPasajero *borrar_primer_nodo_lista_doble(nodoFilaPasajero *lista)
{
    if (lista != NULL)
    {
        nodoFilaPasajero *borrar = lista;
        lista = lista->siguiente;
        lista->anterior = NULL;
        borrar->siguiente = NULL;
        free(borrar);
    }
    else
    {
        printf("Error: la lista esta vacia.\n");
    }
    return lista;
}

void bajarPasajeroDelColectivo(fila *fila, float precioLitroNafta, nodoPasajero **lista)
{
    nodoFilaPasajero *primerPasajero = fila->primero;
    fila->primero = primerPasajero->siguiente;

    if (fila->primero == NULL)
    {
        fila->ultimo = NULL;
    }

    nodoPasajero *anterior = NULL;
    nodoPasajero *actual = *lista;

    while (actual != NULL)
    {
        if (strcmp(actual->dato.DNI, primerPasajero->DNI) == 0)
        {
            float recorridoKm = (float)actual->dato.recorridoEnMetrosEstimado / 1000.0;
            float gananciaViaje = (float)recorridoKm * precioLitroNafta;
            printf("Pasajero con DNI %s ha sido bajado del colectivo. Costo del viaje: %.2f\n", primerPasajero->DNI, gananciaViaje);

            if (anterior == NULL)
            {
                *lista = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }

            free(actual);
            free(primerPasajero);
        }

        anterior = actual;
        actual = actual->siguiente;
    }
}

void mostrar_fila(fila *fila)
{
    nodoFilaPasajero *actual = fila->primero;

    while (actual != NULL)
    {
        printf("%s \n", actual->DNI);
        actual = actual->siguiente;
    }
}
