#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ESTRUCTURAS
typedef struct persona
{
    int tipo; // 1 = regular, 2 = jubilado, 3 = persona gestante, 4 = empresario
    int cantBoletasAPagar;
    struct persona *siguiente;
} persona;

typedef struct nodo2
{
    persona dato;
    struct nodo2 *ante;
    struct nodo2 *sig;
} nodo2;

typedef struct fila
{
    nodo2 *primero; // primer cliente
    nodo2 *ultimo;  // ultimo cliente
    int numeroFila;
    char nombreCajero[50];
} fila;

// PROTOTIPOS

// Funciones Auxiliares
persona *inic_lista_simple();
void inicFila(fila *fila);
nodo2 *inic_lista_doble();

// Ejercicio 1
persona *crearNodoSimple(int tipo, int cantBoletasAPagar);
persona *agregarAlFinal(persona *lista, persona *nuevoNodo);
persona *cargarListaClientes(persona *lista, int cantClientes);

// Ejercicio 2
void mostrarListaClientes(persona *lista);

// Ejercicio 3
int cargarArregloDeFilas(fila filas[], int *validos);

// Ejercicio 4
void mostrarFilas(fila fila);

// Ejercicio 5
int contarClientesFila(fila *fila);
void agregarCliente(fila *fila, persona *cliente);
void cargarClientesXCaja(fila filas[], persona *lista);

// Ejercicio 6
void fila2File(nodo2 *clienteABorrar, char nomArchivo[]);
void mostrarFile(char nomArchivo[]);
void atenderCliente(fila *fila, char nomArchivo[]);

// Ejercicio 7 y 8
void calcularPromedioFacturasYTiempoEspera(fila filas[], int validos);

int main()
{
    int opcion = 0;
    char continuar = 's';

    persona *lista = inic_lista_simple();
    fila filas[5];
    int validos = 0;
    FILE *arch;

    srand(time(NULL));

    printf("Elija un ejercicio...\n");

    system("pause");
    system("cls");

    do
    {
        printf("1.  Cargar lista de clientes.\n");
        printf("2.  Mostrar lista de clientes. \n");
        printf("3.  Cargar filas. \n");
        printf("4.  Mostrar filas. \n");
        printf("5.  Cargar y mostrar filas con clientes. \n");
        printf("6.  Atender clientes. \n");
        printf("7.  Calcular tiempo promedio de espera por caja. \n");
        printf("8.  Salir. \n");
        printf("\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%i", &opcion);

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            int cantClientes = (rand() % 8) + 1;
            lista = cargarListaClientes(lista, cantClientes);
            break;
        }
        case 2:
        {
            mostrarListaClientes(lista);
            break;
        }
        case 3:
        {
            validos = cargarArregloDeFilas(filas, &validos);
            printf("Se han cargado las %i cajas. \n", validos);
            break;
        }
        case 4:
        {
            for (int i = 0; i < validos; i++)
            {
                mostrarFilas(filas[i]);
            }

            break;
        }
        case 5:
        {
            cargarClientesXCaja(filas, lista);
            for (int i = 0; i < validos; i++)
            {
                mostrarFilas(filas[i]);
            }
            break;
        }
        case 6:
        {
            char nombreArchivo[20];
            printf("Ingrese el nombre del archivo: ");
            fflush(stdin);
            gets(nombreArchivo);

            for (int i = 0; i < validos; i++)
            {
                atenderCliente(filas, nombreArchivo);
            }

            printf("Clientes atendidos y almacenados en el archivo '%s'.\n", nombreArchivo);
            mostrarFile(nombreArchivo);
            break;
        }

        case 7:
        {
            calcularPromedioFacturasYTiempoEspera(filas, validos);
            break;
        }
        case 8:
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
        printf("Desea volver al menu principal?: s/n ");
        fflush(stdin);
        scanf(" %c", &continuar);
        system("cls");
    } while (continuar == 's' || continuar == 'S');

    system("pause");
}

// FUNCIONES AUXILIARES
persona *inic_lista_simple()
{
    return NULL;
}

void inicFila(fila *fila)
{
    fila->primero = inic_lista_doble();
    fila->ultimo = inic_lista_doble();
}

nodo2 *inic_lista_doble()
{
    return NULL;
}

// EJERCICIO 1
persona *crearNodoSimple(int tipo, int cantBoletasAPagar)
{
    persona *aux = (persona *)malloc(sizeof(persona));
    aux->tipo = tipo;
    aux->cantBoletasAPagar = cantBoletasAPagar;
    aux->siguiente = NULL;
    return aux;
}

persona *agregarAlFinal(persona *lista, persona *nuevoNodo)
{
    if (lista == NULL)
    {
        return nuevoNodo;
    }
    else
    {
        persona *seg = lista;
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
        seg->siguiente = nuevoNodo;
        return lista;
    }
}

persona *cargarListaClientes(persona *lista, int cantClientes)
{
    for (int i = 0; i < cantClientes; i++)
    {
        int tipo = (rand() % 4) + 1;
        int cantBoletasAPagar = (rand() % 20) + 1;
        persona *aux = crearNodoSimple(tipo, cantBoletasAPagar);
        lista = agregarAlFinal(lista, aux);
    }
    return lista;
}

// EJERCICIO 2
void mostrarListaClientes(persona *lista)
{
    persona *seg = lista;
    while (seg != NULL)
    {
        printf("TIPO DE CLIENTE: %d\n", seg->tipo);
        printf("CANT. BOLETAS A PAGAR: %d\n", seg->cantBoletasAPagar);
        seg = seg->siguiente;
    }
}

// EJERCICIO 3
int cargarArregloDeFilas(fila filas[], int *validos)
{
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el numero de la caja (3 digitos): ");
        fflush(stdin);
        scanf("%d", &filas[i].numeroFila);

        printf("Ingrese el nombre del cajero: ");
        fflush(stdin);
        scanf("%s", filas[i].nombreCajero);

        inicFila(&filas[i]);
        (*validos)++;
    }
    return (*validos);
}

// EJERCICIO 4
void mostrarFilas(fila fila)
{
    printf("Caja %d (%s):\n", fila.numeroFila, fila.nombreCajero);

    nodo2 *actual = fila.primero;
    while (actual != NULL)
    {
        printf("  Tipo de Cliente: %d, Boletas a Pagar: %d\n", actual->dato.tipo, actual->dato.cantBoletasAPagar);
        actual = actual->sig;
    }

    printf("\n");
}

// EJERCICIO 5
int contarClientesFila(fila *fila)
{
    int cantClientes = 0;
    nodo2 *aux = fila->primero;
    while (aux != NULL)
    {
        cantClientes++;
        aux = aux->sig;
    }
    return cantClientes;
}

void agregarCliente(fila *fila, persona *cliente)
{
    nodo2 *nuevoNodo = (nodo2 *)malloc(sizeof(nodo2));
    nuevoNodo->dato = *cliente;
    nuevoNodo->sig = NULL;
    nuevoNodo->ante = fila->ultimo;

    if (fila->ultimo == NULL)
    {
        fila->primero = nuevoNodo;
        fila->ultimo = nuevoNodo;
    }
    else
    {
        fila->ultimo->sig = nuevoNodo;
        fila->ultimo = nuevoNodo;
    }
}

void cargarClientesXCaja(fila filas[], persona *lista)
{
    persona *seg = lista;
    while (seg != NULL)
    {
        int filaConMenosClientes = 0;
        int menorCantClientes = contarClientesFila(&filas[0]);
        for (int i = 1; i < 5; i++)
        {
            int numClientes = contarClientesFila(&filas[i]);
            if (i == 0 || numClientes < menorCantClientes)
            {
                filaConMenosClientes = i;
                menorCantClientes = numClientes;
            }
        }
        agregarCliente(&filas[filaConMenosClientes], seg);
        seg = seg->siguiente;
    }
}

// EJERCICIO 6
void fila2File(nodo2 *clienteABorrar, char nomArchivo[])
{
    FILE *arch = fopen(nomArchivo, "ab");

    if (arch != NULL)
    {
        fwrite(clienteABorrar, sizeof(nodo2), 1, arch);
        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void mostrarFile(char nomArchivo[])
{
    nodo2 *aux = (nodo2 *)malloc(sizeof(nodo2));

    FILE *arch = fopen(nomArchivo, "rb");

    if (arch != NULL)
    {
        fseek(arch, 0, SEEK_SET);

        while ((fread(aux, sizeof(nodo2), 1, arch)) > 0)
        {
            printf("TIPO DE CLIENTE: %i\n", aux->dato.tipo);
            printf("CANT. BOLETAS A PAGAR: %i\n", aux->dato.cantBoletasAPagar);
        }
        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void atenderCliente(fila fila[], char nomArchivo[])
{
    while (fila->primero != NULL)
    {
        nodo2 *clienteAtendido = fila->primero;
        fila->primero = clienteAtendido->sig;
        fila2File(clienteAtendido, nomArchivo);
        free(clienteAtendido);
    }
}

// EJERCICIO 7 y 8
void calcularPromedioFacturasYTiempoEspera(fila filas[], int validos)
{
    float tiempoPromedioMinimo = -1.0;
    int filaMinTiempoPromedio = -1;

    for (int i = 0; i < validos; i++)
    {
        fila *caja = &filas[i];
        nodo2 *cliente = caja->primero;
        int tiempoAcumulado = 0;
        int cantFacturasCaja = 0;
        int cantClientesCaja = 0;

        while (cliente != NULL)
        {
            tiempoAcumulado += cantFacturasCaja;
            cantFacturasCaja += cliente->dato.cantBoletasAPagar;
            cantClientesCaja++;

            cliente = cliente->sig;
        }

        float tiempoPromedio = (float)tiempoAcumulado / cantClientesCaja;

        if (tiempoPromedioMinimo == -1.0 || tiempoPromedio < tiempoPromedioMinimo)
        {
            tiempoPromedioMinimo = tiempoPromedio;
            filaMinTiempoPromedio = i;
        }

        printf("Caja %d - Tiempo promedio de espera: %.2f - Cantidad de facturas: %d\n", caja->numeroFila, tiempoPromedio, cantFacturasCaja);
    }

    if (filaMinTiempoPromedio != -1)
    {
        printf("La caja con el menor tiempo promedio de espera es la caja %d\n", filas[filaMinTiempoPromedio].numeroFila);
    }
    else
    {
        printf("No hay cajas disponibles.\n");
    }
}
