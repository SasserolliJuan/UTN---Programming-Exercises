#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructuras:

typedef struct
{
    int codigoProducto;
    char marca[50]; // Nintendo Switch, Xbox, Playstation
    float precioEnMiles;
    int stock;
    char modelo[50]; // Común, Pro, Slim

} stConsola;

typedef struct nodoConsola
{
    stConsola dato;
    struct nodoConsola *siguiente;

} nodoConsola;

typedef struct
{
    char Nombre[50];
    int mediodepago; // 1 efectivo, 2 patacones, 3 dolar ahorro
    float totalCompra;

} stCliente;

typedef struct nodoCliente
{
    stCliente dato;
    struct nodoCliente *siguiente;
    struct nodoCliente *anterior;

} nodoCliente;

// PROTOTIPADOS:

// Funciones Auxiliares:
nodoConsola *iniclistaConsolas();
nodoCliente *iniclistaClientes();

//  Ejercicio 1:
nodoConsola *crearNodoConsola(stConsola dato);

// Ejercicio 2:
nodoConsola *cargarNodoOrdenado(nodoConsola *lista, nodoConsola *nuevoNodo);

// Ejercicio 3:
nodoConsola *cargaListaConsolas(nodoConsola *lista);
void imprimirDatosConsola(nodoConsola *lista);
void mostrarListaConsolasPorPrecioRecursiva(nodoConsola *lista, int precioCriterio);

// Ejercicio 4:
void mostrarListaConsolasRecursiva(nodoConsola *lista);
int controlarStock(nodoConsola *lista, char marca[], char modelo[], int cantidadPedida);

// Ejercicio 5:
nodoCliente *crearNodoCliente(stCliente dato);
nodoCliente *cargarAlFinal(nodoCliente *lista, nodoCliente *nuevoNodo);
float controlarStockClientes(nodoConsola **lista, char marca[], int cantidadPedida);
nodoCliente *cargarListaClientes(nodoCliente *lista, nodoConsola **listaConsolas, char marca[], int cantidadAComprar);
void mostrarListaClientesRecursiva(nodoCliente *lista);

// Ejercicio 6:
float totalAPagarPorClientes(nodoCliente *lista);

// Ejercicio 7 & 8:
void mostrarListaClientesRecursivaHaciaAtras(nodoCliente *lista);
nodoCliente *borradoDeClientesAtendidosEnLista(nodoCliente *lista);

int main()
{
    int opcion = 0;
    char continuar = 's';
    nodoConsola *listaConsolas = iniclistaConsolas();
    nodoCliente *listaClientes = iniclistaClientes();

    printf("Elija un ejercicio...\n");

    system("pause");
    system("cls");

    do
    {
        printf("1. Cargar lista de consolas. \n");
        printf("2. Mostrar lista de consolas. \n");
        printf("3. Controlar stock. \n");
        printf("4. Cargar lista de clientes. \n");
        printf("5. Mostrar lista de clientes. \n");
        printf("6. Mostrar total a pagar por todos los clientes. \n");
        printf("7. Atender y borrar clientes de la lista. \n");
        printf("8. Salir.\n");
        printf("\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%i", &opcion);

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            listaConsolas = cargaListaConsolas(listaConsolas);
            break;
        }
        case 2:
        {
            printf("Lista de consolas original: \n");
            mostrarListaConsolasRecursiva(listaConsolas);

            int precio = 0;
            printf("Ingrese el precio a buscar: \n");
            fflush(stdin);
            scanf("%i", &precio);

            printf("Lista de consolas mostradas segun un precio: \n");
            mostrarListaConsolasPorPrecioRecursiva(listaConsolas, precio);
            break;
        }
        case 3:
        {
            char marca[50];
            char modelo[50];
            int cantidad = 0;
            int rta = 0;

            printf("Lista de consolas con sus datos originales: \n");
            mostrarListaConsolasRecursiva(listaConsolas);

            printf("Ingrese la marca, el modelo y la cantidad que se quiere de una consola: \n");
            printf("Marca: ");
            fflush(stdin);
            gets(marca);
            printf("Modelo: ");
            fflush(stdin);
            gets(modelo);
            printf("Cantidad: ");
            fflush(stdin);
            scanf("%i", &cantidad);
            printf("\n");

            rta = controlarStock(listaConsolas, marca, modelo, cantidad);

            if (rta == 1)
            {
                printf("Se han modificado los stocks satisfactoriamente. \n");
            }
            else
            {
                printf("Error: no se han podido modificar los stocks. \n");
            }
            break;
        }
        case 4:
        {
            char marca[50];
            int cantidad = 0;
            char continuar = 's';

            while (continuar == 's' || continuar == 'S')
            {
                printf("Lista de consolas: \n");
                mostrarListaConsolasRecursiva(listaConsolas);

                printf("Ingrese la marca y la cantidad que se quiere de una consola: \n");
                printf("Marca: ");
                fflush(stdin);
                gets(marca);
                printf("Cantidad: ");
                fflush(stdin);
                scanf("%i", &cantidad);
                printf("\n");

                listaClientes = cargarListaClientes(listaClientes, &listaConsolas, marca, cantidad);
                printf("Desea seguir cargando clientes a su respectiva lista?: s/n\n");
                fflush(stdin);
                scanf("%c", &continuar);
                printf("\n");
            }

            printf("Lista de clientes: \n");
            mostrarListaClientesRecursiva(listaClientes);

            printf("Lista de consolas cons datos (stocks) modificados: \n");
            mostrarListaConsolasRecursiva(listaConsolas);
            break;
        }
        case 5:
        {
            mostrarListaClientesRecursiva(listaClientes);
            break;
        }
        case 6:
        {
            float suma = 0;
            suma = totalAPagarPorClientes(listaClientes);
            printf("La suma total a pagar por los clientes es de: %.2f\n", suma);
            break;
        }
        case 7:
        {
            listaClientes = borradoDeClientesAtendidosEnLista(listaClientes);
            break;
        }
        case 8:
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

// FUNCIONES AUXILIARES:
nodoConsola *iniclistaConsolas() // Funciona tanto para la lista de consolas, como de clientes.
{
    return NULL;
}

nodoCliente *iniclistaClientes()
{
    return NULL;
}

// EJERCICIO 1:
nodoConsola *crearNodoConsola(stConsola dato)
{
    nodoConsola *aux = (nodoConsola *)malloc(sizeof(nodoConsola));

    aux->dato = dato;
    aux->siguiente = NULL;

    return aux;
}

// EJERCICIO 2:
nodoConsola *cargarNodoOrdenado(nodoConsola *lista, nodoConsola *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if (nuevoNodo->dato.stock < lista->dato.stock)
        {
            nuevoNodo->siguiente = lista;
            lista = nuevoNodo;
        }
        else
        {
            nodoConsola *ante = lista;
            nodoConsola *seg = lista->siguiente;

            while ((seg != NULL) && nuevoNodo->dato.stock > seg->dato.stock)
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

// EJERCICIO 3:
nodoConsola *cargaListaConsolas(nodoConsola *lista)
{
    char continuar = 's';

    do
    {
        stConsola datos;
        printf("Ingrese los datos de la consola: \n");
        printf("Codigo del producto: ");
        fflush(stdin);
        scanf("%i", &datos.codigoProducto);

        printf("Marca: ");
        fflush(stdin);
        scanf("%s", datos.marca);

        printf("Precio en miles: ");
        fflush(stdin);
        scanf("%f", &datos.precioEnMiles);

        printf("Stock: ");
        fflush(stdin);
        scanf("%i", &datos.stock);

        printf("Modelo: ");
        fflush(stdin);
        scanf("%s", datos.modelo);

        nodoConsola *aux = crearNodoConsola(datos);
        lista = cargarNodoOrdenado(lista, aux);

        printf("Desea seguir cargando consolas a su respectiva lista?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n");

    } while ((continuar == 's') || (continuar == 'S'));

    return lista;
}

void imprimirDatosConsola(nodoConsola *lista)
{
    printf("Codigo del producto: %i\n", lista->dato.codigoProducto);
    printf("Marca: %s\n", lista->dato.marca);
    printf("Precio: %.2f\n", lista->dato.precioEnMiles);
    printf("Stock: %i\n", lista->dato.stock);
    printf("Modelo: %s\n", lista->dato.modelo);
}

void mostrarListaConsolasPorPrecioRecursiva(nodoConsola *lista, int precioCriterio)
{
    if (lista != NULL)
    {
        if (lista->dato.precioEnMiles == precioCriterio)
        {
            imprimirDatosConsola(lista);
            printf("\n");
        }

        mostrarListaConsolasPorPrecioRecursiva(lista->siguiente, precioCriterio);
    }
}

// EJERCICIO 4:
void mostrarListaConsolasRecursiva(nodoConsola *lista)
{
    if (lista != NULL)
    {
        imprimirDatosConsola(lista);
        printf("\n");

        mostrarListaConsolasRecursiva(lista->siguiente);
    }
}

int controlarStock(nodoConsola *lista, char marca[], char modelo[], int cantidadPedida)
{
    int rta = 0;

    if (lista == NULL)
    {
        printf("Error: la lista de consolas esta vacia. \n");
    }
    else
    {
        nodoConsola *seg = lista;

        while (seg != NULL)
        {
            if ((seg->dato.stock >= cantidadPedida) && (strcmp(seg->dato.marca, marca) == 0) && (strcmp(seg->dato.modelo, modelo) == 0))
            {
                int nuevoStock = 0;
                nuevoStock = seg->dato.stock - cantidadPedida;
                seg->dato.stock = nuevoStock;
                rta = 1;
            }

            seg = seg->siguiente;
        }
    }

    return rta;
}

// EJERCICIO 5:
nodoCliente *crearNodoCliente(stCliente dato)
{
    nodoCliente *aux = (nodoCliente *)malloc(sizeof(nodoCliente));

    aux->dato = dato;
    aux->anterior = NULL;
    aux->siguiente = NULL;

    return aux;
}

nodoCliente *cargarAlFinal(nodoCliente *lista, nodoCliente *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoCliente *seg = lista;

        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }

        seg->siguiente = nuevoNodo;
        nuevoNodo->anterior = seg;
        nuevoNodo->siguiente = NULL;
    }

    return lista;
}

float controlarStockClientes(nodoConsola **lista, char marca[], int cantidadAComprar)
{
    float totalDeCompra = 0;

    if (*lista == NULL)
    {
        printf("Error: la lista de consolas esta vacia. \n");
    }
    else
    {
        nodoConsola *seg = *lista;

        while (seg != NULL)
        {
            if (strcmp(seg->dato.marca, marca) == 0)
            {
                int nuevoStock = 0;
                nuevoStock = seg->dato.stock - cantidadAComprar;
                seg->dato.stock = nuevoStock;
                totalDeCompra += (float)seg->dato.precioEnMiles * cantidadAComprar;
            }
            seg = seg->siguiente;
        }
    }
    return totalDeCompra;
}

nodoCliente *cargarListaClientes(nodoCliente *lista, nodoConsola **listaConsolas, char marca[], int cantidadAComprar)
{
    stCliente datos;
    printf("Ingrese los datos del cliente: \n");
    printf("Nombre: ");
    fflush(stdin);
    scanf("%s", datos.Nombre);

    printf("Metodo de pago: ");
    fflush(stdin);
    scanf("%i", &datos.mediodepago);

    datos.totalCompra = 0;
    datos.totalCompra = controlarStockClientes(listaConsolas, marca, cantidadAComprar);
    printf("Total de compra: %.2f\n", datos.totalCompra);

    nodoCliente *aux = crearNodoCliente(datos);
    lista = cargarAlFinal(lista, aux);

    return lista;
}

void imprimirDatosCliente(nodoCliente *lista)
{
    printf("Nombre: %s\n", lista->dato.Nombre);
    printf("Medio de pago: %i\n", lista->dato.mediodepago);
    printf("Total de compra: %.2f\n", lista->dato.totalCompra);
}

void mostrarListaClientesRecursiva(nodoCliente *lista)
{
    if (lista != NULL)
    {
        imprimirDatosCliente(lista);
        printf("\n");

        mostrarListaClientesRecursiva(lista->siguiente);
    }
}

// EJERCICIO 6:
float totalAPagarPorClientes(nodoCliente *lista)
{
    float sumaTotalAPagar = 0;
    nodoCliente *seg = lista;

    while (seg != NULL)
    {
        sumaTotalAPagar += (float)seg->dato.totalCompra;
        seg = seg->siguiente;
    }

    return sumaTotalAPagar;
}

// EJERCICIO 7 & 8:
void mostrarListaClientesRecursivaHaciaAtras(nodoCliente *lista)
{
    if (lista != NULL)
    {
        mostrarListaClientesRecursivaHaciaAtras(lista->siguiente);

        imprimirDatosCliente(lista);
        printf("\n");
    }
}

nodoCliente *borradoDeClientesAtendidosEnLista(nodoCliente *lista)
{
    nodoCliente *aux;

    while (lista != NULL)
    {
        mostrarListaClientesRecursivaHaciaAtras(lista);
        aux = lista;
        lista = lista->siguiente;
        free(aux);
        printf("Cliente atendido y borrado. \n");
    }

    return lista;
}