// TRABAJO PRACTICO FINAL PARA LABORATORIO 1 - UTN MDP 2022. ----> REALIZADO POR ALUMNOS DE LA COMISION 1. < GRUPO 5 >

//                      INTEGRANTES DEL GRUPO Y SU ROL EN EL DESARROLLO DEL TP, POR ORDEN DE PASO REALIZADO:                          //
// JUAN SASSEROLLI, ENCARGADO DE REALIZAR PASOS 1 Y 2. TAMBIEN REALIZO LOS MENUS Y SUBMENUS, ADEMAS DE AYUDAR A TESTEAR LOS PASOS 3 Y 4.
// CLARA DOMINGUEZ, ENCARGADA DE REALIZAR EL PASO 3, TAMBIEN AYUDO EN EL PASO 1, Y 2.
// ALAN BOHNSDALEN, ENCARGADO DE REALIZAR EL PASO 4. TAMBIEN AYUDO EN EL PASO 2, Y 3.

// TODO EL TRABAJO QUE SE VE REFLEJADO EN ESTE ARCHIVO FUE PROBADO MULTIPLES VECES POR CADA INTEGRANTE DEL GRUPO PARA GARANTIZAR SU
// FUNCIONAMIENTO CORRECTO Y QUE FUERA ACORDE A LAS CONSIGNAS DEL TP.
// ESTE GRUPO NO UTILIZO GITHUB, SE REALIZABAN LOS PASOS SECUENCIALMENTE, Y SE IBA PROBANDO HASTA QUE FUNCIONABA DE UNA FORMA CORRECTA CADA PASO.
// PARA COMUNICARNOS CAMBIOS Y REALIZAR LOS "MERGE", UTILIZAMOS PRINCIPALMENTE WHATSAPP, Y DISCORD.
// LA COMUNICACION ABIERTA DE LOS CAMBIOS REALIZADOS Y PROBLEMAS CON LOS QUE NOS ENCONTRAMOS AL TRABAJAR EL TP FUERON ESENCIALES,
// YA QUE TODOS PARTICIPABAMOS DE UNA FORMA EQUITATIVA EN EL DESARROLLO DEL TRABAJO FINAL. CADA INTEGRANTE ELIGIO EL TEMA QUE LE RESULTO MAS COMODO.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 30
#define MAX_VENTAS 20

//------------------------------------------ESTRUCTURAS---------------------------------------------//

typedef struct StockIngrediente
{
    char nombre_ingrediente[20];
    float cantidad;
    char tipo[20];
    float costo;

} StockIngrediente;

typedef struct Preparacion
{
    char nombre_preparacion[20];
    int cantidad;

} Preparacion;

typedef struct IngredienteXReceta
{
    char nombre_Ingrediente[20];
    float cantidad;

} IngredienteXReceta;

typedef struct Receta
{
    char nombre_preparacion[20];
    IngredienteXReceta ingredientes[20];
    int cantIngredientes;

} Receta;

typedef struct PreparacionVenta
{
    char nombre_preparacion[20];
    int cantidad;
} PreparacionVenta;

typedef struct PrecioPreparacion
{
    char nombre_preparacion[20];
    float precio_venta; /// precio por unidad
} PrecioPreparacion;

typedef struct PedidoPreparacion
{
    char nombre_preparacion[20];
    int cantidad;
} PedidoPreparacion;

typedef struct Venta
{
    int idVenta;
    PedidoPreparacion items_pedido[20]; /// puedo pedir hasta 20 items
    int cantItems;                      /// los validos del arreglo de items_pedido
    float valor_total;                  /// valor total a pagar
    int activo;
} Venta;

//-------------------------------------------------------PROTOTIPADOS-------------------------------------------------------------------//

//                                                   -----     MENUS:   -----                                               //
/// Menus Y submenus: desarrollados por Juan Sasserolli

// muestra las opciones del menu principal
void MenuPrincipal();

int menuOpcionesPasos();
int subMenuPaso2();
int subMenuPaso3();
int subMenuPaso4();

// FUNCIÓN utilizada para mostrar la cantidad de registros, realizada para que sirva para cualquier archivo y tipo de dato.
int cantRegGenerico(char[], int);

///----->PASO 1 Y 2: Desarrollado conjuntamente, principalmente por Juan Sasserolli, con ayuda de Alan Bohnsdalen y Clara Dominguez---///

//                           Funciones para LECTURA y MUESTRA de INGREDIENTES                                                                //
void lecturaIngredientes(char[], StockIngrediente *, int);
void mostrarListaIngredientes(StockIngrediente[], int);
void mostrarIngredientes(StockIngrediente);

//                           Funciones para LECTURA y MUESTRA de PEDIDOS                                                                     //
void lecturaPedidos(char[], Preparacion *, int);
void mostrarUnPedido(Preparacion);
void mostrarListaPedidos(Preparacion *, int);

//                           Funciones para LECTURA y MUESTRA de RECETAS                                                                     //
void lecturaRecetas(char[], Receta *, int);
void mostrarRecetas(Receta *, int);

//                           Funciones ayuda para preparacion de pedidos: Buscar Receta, buscar ingrediente                                  //
int buscarRecetaPorNombre(Preparacion, Receta *, int);
int buscarIngredientePorNombre(StockIngrediente *, IngredienteXReceta, int);

// FUNCIÓN de PREPARACION de pedidos y sobreescritura del stock de pedidos (sin trabajar sobre el archivo, sobre la variable)
void preparacionDePedidos(StockIngrediente *, Preparacion *, Receta *, PreparacionVenta *, int, int, int, int[]);

void cargaArchivoPreparadosVenta(char[], PreparacionVenta *, int);

void lecturaArchivoPreparados(char[], PreparacionVenta *, int);
void sobreEscrituraDeStockIngrediente(char[], StockIngrediente *, int);

void lecturaStockIngredientesActualizado(char[], StockIngrediente *, int);
void mostrarProduccionYstockRestanteIngredientes(PreparacionVenta *, StockIngrediente *, int, int);

///---------------------------------------------------- FIN FUNCIONES PASO 1 Y 2 ----------------------------------------------------///

//                                          -------    COMIENZO FUNCIONES PASO 3:     -------                                         ///

//------------------------------------------------->PASO 3: Realizado por Clara Dominguez, con ayuda de Alan Bohnsdalen

void cargaPreciosPreparadosAutomaticamente(float[], Preparacion *, Receta *, StockIngrediente *, PrecioPreparacion *, int, int);
void cargaPreciosPreparadosPorElUsuario(float[], Preparacion *, Receta *, StockIngrediente *, PrecioPreparacion *, int, int);

void cargaArchivoPrecios(char[], PrecioPreparacion *, int);
void lecturaArchivoPrecios(char[], PrecioPreparacion *, int);

void mostrarUnPrecio(PrecioPreparacion);
void mostrarListaPrecios(PrecioPreparacion *, int);

void cambiarPrecioPreparado(PrecioPreparacion *, int);
void cambiarPrecioVariosPreparados(PrecioPreparacion *, int, char);

void cargarUnaVenta(Venta *, int, int *, PreparacionVenta *, PrecioPreparacion *);
void cargarListaVentas(Venta *, int *, PreparacionVenta *, int, PrecioPreparacion *, int, int *);
void calculoTotalUnaVenta(Venta *, PrecioPreparacion *, int);
void cargarArchivoVentasSobreescribiendo(char[], Venta *, int);
void cargarVentasEnArchivoConAppend(char[], Venta[], int);

void lecturaArchivoVentas(char[], Venta *, int);

void mostrarUnaVenta(Venta);
void mostrarListaVentas(Venta *, int, PrecioPreparacion *, int);

void mostrarProductosRemanentes(PreparacionVenta *, int);

int bajaLogica(char[], Venta *);

int devolucionAlStock(PreparacionVenta *, PedidoPreparacion, int);

///----------------------------------------------------------- FIN FUNCIONES PASO 3---------------------------------------------------------///

///                                              ------------ FUNCIONES PASO 4: ----------                                             ///
//------------------------------------------------>PASO 4: Realizado por Alan Bohnsdalen

void calculoYmuestraIngresosTotales(int[], float *, PreparacionVenta *, int, int[], PrecioPreparacion *, Venta *, int);
void gananciaDia(float[], float, int, int[]);
void cargaPreparadosInicio(PreparacionVenta *, int, int[]);

///------------------------------------------------------------------ FIN FUNCIONES PASO 4 --------------------------------------------------------///

//-------------------------------------------IMPLEMENTACION DE LAS FUNCIONES-----------------------------------------------//
int main()
{
    MenuPrincipal();

    system("pause");
    return 0;
}

int menuOpcionesPasos()
{
    int opcion = 0;
    printf("\n _____               _   _              _____    ______   _____    _____     ");
    printf("\n|  __ \\      /\\     | | | |     ||     |  __ |  |  ____| |  __ |   |_   _|      /\\   ");
    printf("\n| |__) |    /  \\    |  || |    |  |    | |  | | | |__    | |__| |    | |       /  \\    ");
    printf("\n|  ___/    / || \\   | . ` |   | || |   | |  | | |  __|   |  _  |     | |      / || \\    ");
    printf("\n| |       / ____ \\  | ||  |  | ____ |  | |__| | | |____  | |  | |   _| |_    / ____ \\   ");
    printf("\n|_|      |_|    |_| |_| |_| |_|    |_| |_____|  |______| |_|   |_| |_____|  |_|    |_|    ");

    printf("\n ========================================================== \n");
    printf("          > > > > Bienvenido a la panaderia < < < < \n");
    printf(" ========================================================== \n");
    printf("                    MENU PRINCIPAL:             \n");
    printf("\n\tPRIMERA PARTE: \n");
    printf(" - PASO 1: INGRESO DE MATERIA PRIMA ---> PRESIONE 1. \n");
    printf(" - PASO 2: COCINANDO LOS PREPARADOS ---> PRESIONE 2. \n");
    printf(" - PASOS 1 Y 2: INGRESO DE MATERIA PRIMA Y COCCION DE LOS PREPARADOS ---> PRESIONE 12. \n");
    printf("\n\tSEGUNDA PARTE: \n");
    printf("PASO 3: VENTA AL PUBLICO ---> PRESIONE 3. \n");
    printf("\n\tTERCERA PARTE: \n");
    printf("PASO 4: RESUMEN DEL DIA ---> PRESIONE 4. \n");
    printf("\n\tIngrese la opcion que desea: ");
    scanf("%i", &opcion);

    return opcion;
}

void MenuPrincipal()
{
    char archivoIngredientes[] = {"stockingredientes.bin"};
    char archivoIngredientesActualizado[] = {"stockingredientesActualizado.bin"};
    char archivoPedidos[] = {"demanda.bin"};
    char archivoRecetas[] = {"recetas.bin"};
    char archivoPrecios[] = {"precios.bin"};
    char archivoPreparados[] = {"stockventa.bin"};
    char archivoVentas[] = {"ventas.bin"};

    StockIngrediente listaIngredientes[TAM_MAX];

    Preparacion listaPreparaciones[TAM_MAX];

    PreparacionVenta preparadosParaVenta[TAM_MAX];

    Receta listaRecetas[TAM_MAX];

    PrecioPreparacion listaPrecios[TAM_MAX];

    Venta listaVentas[MAX_VENTAS];

    int cantPedidos = 0, cantIngredientes = 0, cantRecetas = 0, cantRegistros = 0, total_producido_posible, cantVentasDuranteCarga = 0;
    int numReceta = -1, idParaEliminar = -1, opcionPrecios = 0, respuesta = 0, cantVentasEnArchivo = 0;

    int StockPrepInicio[20], vendido[20];
    float costoPreparaciones[20], ingreso = 0;

    char continuar, seguir = 's', continuarSM2, continuarSM3, continuarSM4;

    do
    {
        int opcionM = menuOpcionesPasos();
        switch (opcionM)
        {
            // MENU DE LA PRIMERA Y SEGUNDA PARTE:
        case 1:
            cantRegistros = cantRegGenerico(archivoIngredientes, sizeof(StockIngrediente));
            cantIngredientes = cantRegistros;
            lecturaIngredientes(archivoIngredientes, listaIngredientes, cantIngredientes);
            break;
        case 2:
            do
            {
                int opcionSM2 = subMenuPaso2();
                switch (opcionSM2)
                {
                case 1:
                    cantRegistros = cantRegGenerico(archivoPedidos, sizeof(Preparacion));
                    cantPedidos = cantRegistros;
                    lecturaPedidos(archivoPedidos, listaPreparaciones, cantPedidos);

                    mostrarListaPedidos(listaPreparaciones, cantPedidos);

                    break;
                case 2:
                    cantRegistros = cantRegGenerico(archivoRecetas, sizeof(Receta));
                    cantRecetas = cantRegistros;
                    lecturaRecetas(archivoRecetas, listaRecetas, cantRecetas);
                    mostrarRecetas(listaRecetas, cantRecetas);
                    break;
                case 3:
                    fflush(stdin);
                    cantRegistros = cantRegGenerico(archivoPedidos, sizeof(Preparacion));
                    cantPedidos = cantRegistros;
                    lecturaPedidos(archivoPedidos, listaPreparaciones, cantPedidos);

                    mostrarListaPedidos(listaPreparaciones, cantPedidos);

                    fflush(stdin);
                    cantRegistros = cantRegGenerico(archivoRecetas, sizeof(Receta));
                    cantRecetas = cantRegistros;
                    lecturaRecetas(archivoRecetas, listaRecetas, cantRecetas);

                    mostrarRecetas(listaRecetas, cantRecetas);

                    break;
                case 4:
                    printf("\nCOMIENZO DE PREPARACION DE PEDIDOS: \n");
                    preparacionDePedidos(listaIngredientes, listaPreparaciones, listaRecetas, preparadosParaVenta, cantIngredientes, cantPedidos, cantRecetas, &total_producido_posible);
                    cargaPreparadosInicio(preparadosParaVenta, cantPedidos, StockPrepInicio);
                    mostrarListaPedidos(listaPreparaciones, cantPedidos);

                    printf("\nCARGA DE ARCHIVO CON LOS PREPARADOS PARA LA VENTA: \n");
                    cargaArchivoPreparadosVenta(archivoPreparados, preparadosParaVenta, cantPedidos);
                    lecturaArchivoPreparados(archivoPreparados, preparadosParaVenta, cantPedidos);

                    mostrarListaIngredientes(listaIngredientes, cantIngredientes);
                    sobreEscrituraDeStockIngrediente(archivoIngredientes, listaIngredientes, cantIngredientes);
                    mostrarProduccionYstockRestanteIngredientes(preparadosParaVenta, listaIngredientes, cantPedidos, cantIngredientes);
                    break;
                default:
                    printf("Opcion no valida.");
                    break;
                }
                printf("\n\tDesea volver al MENU del PASO 2? s/n: ");
                fflush(stdin);
                scanf("%c", &continuarSM2);
                system("cls");

            } while (continuarSM2 == 's' || continuarSM2 == 'S');
            break;

        case 12:
            cantRegistros = cantRegGenerico(archivoIngredientes, sizeof(StockIngrediente));
            cantIngredientes = cantRegistros;
            lecturaIngredientes(archivoIngredientes, listaIngredientes, cantIngredientes);

            fflush(stdin);
            cantRegistros = cantRegGenerico(archivoPedidos, sizeof(Preparacion));
            cantPedidos = cantRegistros;
            lecturaPedidos(archivoPedidos, listaPreparaciones, cantPedidos);

            fflush(stdin);
            cantRegistros = cantRegGenerico(archivoRecetas, sizeof(Receta));
            cantRecetas = cantRegistros;
            lecturaRecetas(archivoRecetas, listaRecetas, cantRecetas);

            preparacionDePedidos(listaIngredientes, listaPreparaciones, listaRecetas, preparadosParaVenta, cantIngredientes, cantPedidos, cantRecetas, &total_producido_posible);
            cargaPreparadosInicio(preparadosParaVenta, cantPedidos, StockPrepInicio);

            cargaArchivoPreparadosVenta(archivoPreparados, preparadosParaVenta, cantPedidos);
            lecturaArchivoPreparados(archivoPreparados, preparadosParaVenta, cantPedidos);

            sobreEscrituraDeStockIngrediente(archivoIngredientes, listaIngredientes, cantIngredientes);
            lecturaStockIngredientesActualizado(archivoIngredientes, listaIngredientes, cantIngredientes);
            mostrarProduccionYstockRestanteIngredientes(preparadosParaVenta, listaIngredientes, cantPedidos, cantIngredientes);

            system("PAUSE");
            break;

            // MENU DE LA TERCERA PARTE:
        case 3:
            do
            {
                int opcionSM3 = subMenuPaso3();
                switch (opcionSM3)
                {
                case 1:

                    while (opcionPrecios != 1 && opcionPrecios != 2)
                    {
                        printf("Como desea asignar los precios?\n1: Automaticamente, con una ganancia del 51%%.\n2: Cargarlos manualmente.\nIngrese la opcion: ");
                        scanf("%d", &opcionPrecios);
                    }

                    if (opcionPrecios == 1)
                    {
                        cargaPreciosPreparadosAutomaticamente(costoPreparaciones, listaPreparaciones, listaRecetas, listaIngredientes, listaPrecios, cantIngredientes, cantRecetas);
                    }
                    else
                    {
                        cargaPreciosPreparadosPorElUsuario(costoPreparaciones, listaPreparaciones, listaRecetas, listaIngredientes, listaPrecios, cantIngredientes, cantRecetas);
                    }

                    cargaArchivoPrecios(archivoPrecios, listaPrecios, cantPedidos);
                    lecturaArchivoPrecios(archivoPrecios, listaPrecios, cantPedidos);

                    cargaArchivoPreparadosVenta(archivoPreparados, preparadosParaVenta, cantPedidos);
                    lecturaArchivoPreparados(archivoPreparados, preparadosParaVenta, cantPedidos);

                    mostrarListaPrecios(listaPrecios, cantPedidos);
                    break;
                case 2:

                    mostrarListaPrecios(listaPrecios, cantPedidos);

                    cambiarPrecioVariosPreparados(listaPrecios, numReceta, seguir);

                    printf("\n -Lista de precios actualizada con los cambios realizados- \n");
                    mostrarListaPrecios(listaPrecios, cantPedidos);
                    break;
                case 3:
                    cargarListaVentas(listaVentas, &cantVentasDuranteCarga, preparadosParaVenta, cantPedidos, listaPrecios, cantRecetas, &cantVentasEnArchivo);

                    system("pause");

                    mostrarListaVentas(listaVentas, cantVentasDuranteCarga, listaPrecios, cantRecetas);

                    cargarVentasEnArchivoConAppend(archivoVentas, listaVentas, cantVentasDuranteCarga);
                    break;
                case 4:
                    mostrarListaVentas(listaVentas, cantVentasEnArchivo, listaPrecios, cantRecetas);

                    do
                    {
                        printf("Ingrese ID de venta a eliminar: ");
                        fflush(stdin);
                        scanf("%d", &idParaEliminar);
                    } while (idParaEliminar <= -1);

                    for (int i = 0; i < cantVentasEnArchivo; i++)
                    {
                        if (listaVentas[i].idVenta == idParaEliminar)
                        {
                            if (bajaLogica(archivoVentas, &listaVentas[i]) == 1) // si llegó hasta aquí, definitivamente se trata de la venta buscada, y como fue dada de baja, se procede a la devolucion de los preparados que tenía la venta, y se sobreescribe tal archivo con la nueva información, para no contaminar los datos de la parte 4
                            {
                                for (int j = 0; j < listaVentas[i].cantItems; j++)
                                {
                                    respuesta = devolucionAlStock(preparadosParaVenta, listaVentas[i].items_pedido[j], cantRecetas);
                                    cargaArchivoPreparadosVenta(archivoPreparados, preparadosParaVenta, cantPedidos);
                                    lecturaArchivoPreparados(archivoPreparados, preparadosParaVenta, cantPedidos);
                                }
                            }
                        }
                    }

                    if (respuesta == 1)
                    {
                        printf("Se han devuelto al stock exitosamente sus productos.\n");
                    }
                    else
                    {
                        printf("No se ha podido realizar la devolucion.\n");
                    }

                    break;
                case 5:
                    printf("LECTURA Y MUESTRA DEL ARCHIVO VENTAS:"); // se sobreescribe con wb, así se persiste definitivamente en el archivo las ventas de la iteración del programa actual, para una muestra segura de todas las ventas del archivo, ya que lee el estado actual del archivo. Si no se hiciera esto, podría acumularse basura
                    lecturaArchivoVentas(archivoVentas, listaVentas, cantVentasDuranteCarga);
                    cargarArchivoVentasSobreescribiendo(archivoVentas, listaVentas, cantVentasEnArchivo);
                    mostrarListaVentas(listaVentas, cantVentasEnArchivo, listaPrecios, cantRecetas);

                    break;
                default:
                    printf("Opcion no valida.\n");
                    break;
                }
                printf("\n\tDesea volver al MENU DE VENTAS? s/n: ");
                fflush(stdin);
                scanf("%c", &continuarSM3);
                system("cls");
            } while (continuarSM3 == 's' || continuar == 'S');
            break;

            // MENU DE LA TERCERA PARTE:
        case 4:
            do
            {
                int opcionSM4 = subMenuPaso4();
                switch (opcionSM4)
                {
                case 1:
                    mostrarListaIngredientes(listaIngredientes, cantIngredientes);
                    break;
                case 2:
                    mostrarProductosRemanentes(preparadosParaVenta, cantPedidos);
                    break;
                case 3:
                    calculoYmuestraIngresosTotales(vendido, &ingreso, preparadosParaVenta, cantPedidos, StockPrepInicio, listaPrecios, listaVentas, cantVentasEnArchivo);
                    break;
                case 4:
                    gananciaDia(costoPreparaciones, ingreso, cantPedidos, vendido);
                    break;
                default:
                    printf("Opcion no valida.\n");
                    break;
                }

                printf("\nDesea continuar ejecutando el PASO 4? s/n: ");
                fflush(stdin);
                scanf("%c", &continuarSM4);
                system("cls");

            } while (continuarSM4 == 's' || continuarSM4 == 'S');
            break;

        default:
            printf("Opcion no valida. \n");
            break;
        }

        printf("\nDesea volver al MENU GENERAL? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        system("cls");
    } while (continuar == 's' || continuar == 'S');
}

int subMenuPaso2()
{
    int opcionSM2 = 0;
    system("cls");
    printf("\nSUB-MENU PASO 2: \n");
    printf(" - MUESTRA DE PEDIDOS ---> PRESIONE 1. \n"); // no está explicito en el menú pero se realiza la lectura del archivo de pedidos y luego la muestra. Lo mismo pasa con el resto.
    printf(" - MUESTRA DE RECETAS ---> PRESIONE 2. \n");
    printf(" - MUESTRA DE PEDIDOS Y RECETAS ---> PRESIONE 3. \n"); // esta opción nos ayudó a probar tantas veces como quisieramos el archivo, ya que hacía la tarea de probar el correcto FUNCIÓNamiento de dos pasos, en 1 solo.
    printf(" - CARGA DE ARCHIVO PEDIDOS, SOBREESCRITURA INGREDIENTES --> PRESIONE 4. \n");
    printf("\n\tIngrese la opcion que desea: ");
    scanf("%i", &opcionSM2);

    return opcionSM2;
}

int subMenuPaso3()
{
    int opcionSM3 = 0;
    system("cls");
    printf("\n\tMENU VENTAS (PASO 3):\t\n");
    printf(" - CARGA DE PRECIOS DE LOS PREPARADOS ---> PRESIONE 1. \n");
    printf(" - MODIFICAR PRECIOS ---> PRESIONE 2. \n");
    printf(" - INGRESAR VENTAS ---> PRESIONE 3. \n");
    printf(" - CANCELACION VENTAS ---> PRESIONE 4. \n");
    printf(" - MUESTRA LISTA DE VENTAS ---> PRESIONE 5. \n"); // esta opción también lee el archivo y lo sobreescribe con wb con la lista de ventas
    printf("\n\tIngrese la opcion que desea: ");
    scanf("%i", &opcionSM3);

    return opcionSM3;
}

int subMenuPaso4()
{
    int opcionSM4 = 0;
    system("cls");
    printf("\nSUB-MENU PASO 4: \n");
    printf(" - SUBPASO 1: MUESTRA DE INGREDIENTES REMANENTES ---> PRESIONE 1. \n");
    printf(" - SUBPASO 2: MUESTRA DE LISTA DE PREPARADOS Y SU CANTIDAD RESTANTE PARA LA VENTA ---> PRESIONE 2. \n");
    printf(" - SUBPASO 3: MUESTRA DEL INGRESO TOTAL DEL DIA ---> PRESIONE 3. \n");
    printf(" - SUBPASO 4: MUESTRA DE LA GANANCIA DEL DIA ---> PRESIONE 4. \n");
    printf("\n\tIngrese la opcion que desea: ");
    scanf("%i", &opcionSM4);

    return opcionSM4;
}

int cantRegGenerico(char nombreArch[TAM_MAX], int tamanio)
{
    int cantidad = 0;

    FILE *buffer;
    buffer = fopen(nombreArch, "rb");

    if (buffer != NULL)
    {
        fseek(buffer, 0, SEEK_END);
        cantidad = ftell(buffer) / tamanio;
        fclose(buffer);
    }
    else
    {
        printf("Fallo la apertura del archivo. (Error en cantRegGenerico)\n");
    }

    return cantidad;
}

//                                 -------- COMIENZO FUNCIONES PASO 1 Y 2 -------                                               //

void lecturaIngredientes(char nombArch[], StockIngrediente listaIngredientes[TAM_MAX], int cantIngredientes)
{
    FILE *fp;
    fp = fopen(nombArch, "rb");

    if (fp != NULL)
    {
        for (int i = 0; i < cantIngredientes; i++)
        {
            fread(&listaIngredientes[i], sizeof(StockIngrediente), 1, fp);
        }
        printf("Se ha realizado correctamente la lectura de los ingredientes.\n");
        fclose(fp);
    }
    else
    {
        printf("\nError. No se ha podido abrir el archivo de ingredientes para su lectura.\n");
    }
}

void mostrarIngredientes(StockIngrediente ingrediente)
{
    printf(" %s \n", ingrediente.nombre_ingrediente);
    printf("Cantidad: %.2f \n", ingrediente.cantidad);
    printf("Tipo: %s \n", ingrediente.tipo);
    if ((strcmp(ingrediente.tipo, "solido") == 0))
    {
        printf("Costo por kg/unidad: $%.2f \n", ingrediente.costo);
    }
    else
    {
        printf("Costo por litro: $%.2f \n", ingrediente.costo);
    }
}

void mostrarListaIngredientes(StockIngrediente listaIngredientes[], int cantIngredientes)
{
    int i = 0;

    printf("----------------------INGREDIENTES--------------------------\n");

    for (i = 0; i < cantIngredientes; i++)
    {
        printf("\n\tIngrediente #%i: ", i + 1);
        mostrarIngredientes(listaIngredientes[i]);
    }
}

void lecturaPedidos(char archivoPedidos[], Preparacion listaPreparaciones[], int cantRegistros)
{
    FILE *fp;
    fp = fopen(archivoPedidos, "rb");
    if (fp != NULL)
    {
        for (int i = 0; i < cantRegistros; i++)
        {
            fread(&listaPreparaciones[i], sizeof(Preparacion), 1, fp);
        }

        printf("Se ha realizado correctamente la lectura de las demandas.\n");
        fclose(fp);
    }
    else
    {
        printf("\nError. Ha fallado la apertura del archivo de pedidos para su lectura.\n");
    }
}

void mostrarUnPedido(Preparacion listaPreparaciones)
{
    printf("\n\tA preparar: %s \n", listaPreparaciones.nombre_preparacion);
    printf("\tCantidad: %i\n", listaPreparaciones.cantidad);
}

void mostrarListaPedidos(Preparacion listaPreparaciones[], int cantPedidos)
{
    int i = 0;

    printf("------------------------PEDIDOS----------------------------\n\n");
    for (i = 0; i < cantPedidos; i++)
    {
        printf("Pedido #%i: \n", i + 1);
        mostrarUnPedido(listaPreparaciones[i]);
        printf("\n\t----------------------------------------\n");
    }
    printf("\n");
}

void lecturaRecetas(char archivoRecetas[], Receta listaRecetas[], int cantRecetas)
{
    FILE *fp;
    fp = fopen(archivoRecetas, "rb");
    if (fp != NULL)
    {
        for (int i = 0; i < cantRecetas; i++)
        {
            fread(&listaRecetas[i], sizeof(Receta), 1, fp);
        }
        printf("\nSe ha realizado correctamente la lectura de las recetas.\n");

        fclose(fp);
    }
    else
    {
        printf("\nError. Ha fallado la apertura del archivo de recetas para su lectura.\n");
    }
}

void ingredientesNecesariosXReceta(Receta listaRecetas)
{
    for (int i = 0; i < listaRecetas.cantIngredientes; i++)
    {
        printf("Ingrediente: %s. Cantidad: %.2f \n", listaRecetas.ingredientes[i].nombre_Ingrediente, listaRecetas.ingredientes[i].cantidad);
    }
}

void mostrarRecetas(Receta listaRecetas[], int cantRecetas)
{
    printf("\n------------------------RECETAS----------------------------\n");

    for (int i = 0; i < cantRecetas; i++)
    {
        printf("\n\n\tReceta #%i: %s\n", i, listaRecetas[i].nombre_preparacion);
        ingredientesNecesariosXReceta(listaRecetas[i]);
        printf("\tCantidad de ingredientes necesarios: %i \n", listaRecetas[i].cantIngredientes);
        printf("\t----------------------------------------\n");
    }
    printf("\n");

    printf("INFO: Hay %i recetas. \n", cantRecetas);
}

int buscarRecetaPorNombre(Preparacion demanda, Receta listaRecetas[], int cantRecetas)
{
    int rtaR = -1, j = 0;

    while ((strcmpi(demanda.nombre_preparacion, listaRecetas[j].nombre_preparacion) != 0) && (j < cantRecetas)) // Se busca la receta de acuerdo al pedido, para ver si lo que se esta demandando es algo que se puede hacer.
    {
        j++;
    }

    if (j == cantRecetas)
    {
        printf("No se encontro la receta. \n");
    }
    else
    {
        printf("\nReceta numero %i, encontrada. ", j);
        rtaR = j;
    }
    return rtaR;
}

int buscarIngredientePorNombre(StockIngrediente listaIngredientes[], IngredienteXReceta ixr, int cantIngredientes)
{
    int j = 0, rtaI = -1;

    while ((strcmp(listaIngredientes[j].nombre_ingrediente, ixr.nombre_Ingrediente) != 0) && (j < cantIngredientes))
    {

        j++;
    }

    if (j == cantIngredientes)
    {
        rtaI = -1;
    }
    else
    {
        rtaI = j;
    }
    return rtaI;
}

void preparacionDePedidos(StockIngrediente listaIngredientes[], Preparacion listaPreparaciones[], Receta listaRecetas[], PreparacionVenta preparadosParaVenta[], int cantIngredientes, int cantPedidos, int cantRecetas, int total_producido_posible[])
{
    int cantidadR = 0, aux = 250;

    IngredienteXReceta ixr;

    int posIngrediente[10];

    for (int i = 0; i < cantPedidos; i++)
    {
        aux = 250; // valor que se va reseteando.

        int posReceta = buscarRecetaPorNombre(listaPreparaciones[i], listaRecetas, cantRecetas);

        if (posReceta >= 0 && posReceta < cantRecetas)
        {
            Receta a = listaRecetas[posReceta];

            for (int x = 0; x < a.cantIngredientes; x++)
            {
                cantidadR = 0; // valor que se va reseteando.

                ixr = a.ingredientes[x];

                posIngrediente[x] = buscarIngredientePorNombre(listaIngredientes, ixr, cantIngredientes);

                if (posIngrediente[x] >= 0 && posIngrediente[x] < cantIngredientes)
                {
                    fflush(stdin);
                    while ((cantidadR <= listaPreparaciones[i].cantidad) && ((listaIngredientes[posIngrediente[x]].cantidad) >= (cantidadR * (ixr.cantidad))))
                    {
                        cantidadR++;
                    }

                    cantidadR--;

                    if (aux > cantidadR)
                    {
                        aux = cantidadR;
                    }
                }

                total_producido_posible[i] = aux;
                listaIngredientes[posIngrediente[x]].cantidad = listaIngredientes[posIngrediente[x]].cantidad - aux * (ixr.cantidad);
            }
        }
    }

    printf("\n");
    system("pause");

    // carga de estructura de ventas:
    for (int h = 0; h < cantPedidos; h++)
    {
        strcpy(preparadosParaVenta[h].nombre_preparacion, listaPreparaciones[h].nombre_preparacion);
        preparadosParaVenta[h].cantidad = total_producido_posible[h];
    }
}

void mostrarProduccionYstockRestanteIngredientes(PreparacionVenta preparadosParaVenta[], StockIngrediente listaIngredientes[], int cantPedidos, int cantIngredientes)
{
    printf("\n------------------PRODUCCION REALIZADA-----------------\n\n");

    for (int j = 0; j < cantPedidos; j++) // Muestra la cantidad producida.
    {
        printf("%s: %i  \n", preparadosParaVenta[j].nombre_preparacion, preparadosParaVenta[j].cantidad);
    }

    system("pause");

    printf("\n----------ACTUALIZACION DE STOCK INGREDIENTES----------\n");
    for (int k = 0; k < cantIngredientes; k++) // Muestra el remanente de stock.
    {
        printf("\t%-5s. Restante: %-2.2f\t\n", listaIngredientes[k].nombre_ingrediente, listaIngredientes[k].cantidad);
    }
    printf("\n");
}

//// cada demanda tiene un tipo de producto o distintos tipos. primero se recorre los productos de la demanda, luego se buscan esos productos en la
////  la idea es restar a la cantidad total de ingredientes, la totalidad de ese mismo tipo de ingrediente que se necesita por receta

void cargaArchivoPreparadosVenta(char archivoPreparados[], PreparacionVenta preparadosParaVenta[], int cantPedidos)
{
    FILE *fp;
    fp = fopen(archivoPreparados, "wb");
    if (fp != NULL)
    {
        for (int i = 0; i < cantPedidos; i++)
        {
            fwrite(&preparadosParaVenta[i], sizeof(PreparacionVenta), 1, fp);
        }

        fclose(fp);
    }
    else
    {
        printf("El archivo no se pudo abrir. \n");
    }
}

void lecturaArchivoPreparados(char archivoPreparados[], PreparacionVenta preparadosParaVenta[], int cantPedidos)
{
    FILE *fp;
    fp = fopen(archivoPreparados, "rb");
    if (fp != NULL)
    {
        for (int j = 0; j < cantPedidos; j++)
        {
            fread(&preparadosParaVenta[j], sizeof(PreparacionVenta), 1, fp);
        }
        printf("Se ha realizado correctamente la lectura del archivo de preparados.\n");
        fclose(fp);
    }
    else
    {
        printf("Error. El archivo no se ha podido abrir. \n");
    }
}

void sobreEscrituraDeStockIngrediente(char archivoIngredientes[], StockIngrediente listaIngredientes[], int cantIngredientes)
{
    FILE *fp;
    fp = fopen(archivoIngredientes, "wb");
    if (fp != NULL)
    {
        for (int i = 0; i < cantIngredientes; i++)
        {
            fwrite(&listaIngredientes[i], sizeof(StockIngrediente), 1, fp);
        }
        printf("Se ha sobreescrito correctamente el stock de ingredientes en el archivo\n");
        fclose(fp);
    }
    else
    {
        printf("El archivo no se pudo abrir. \n");
    }
}

void lecturaStockIngredientesActualizado(char archivoIngredientes[], StockIngrediente listaIngredientes[], int cantIngredientes)
{
    FILE *fp;
    fp = fopen(archivoIngredientes, "rb");
    if (fp != NULL)
    {
        for (int i = 0; i < cantIngredientes; i++)
        {
            fread(&listaIngredientes[i], sizeof(StockIngrediente), 1, fp);
        }
        printf("Se ha realizado la lectura del stock de ingredientes actualizado correctamente.\n");
        fclose(fp);
    }
    else
    {
        printf("El archivo de stock ingredientes no se pudo abrir para su lectura. \n");
    }
}
///                                        -------- FIN FUNCIONES PASO 1 Y 2 -------                                               ///

///                      --------------    COMIENZO IMPLEMENTACION FUNCIONES PASO 3:     --------------                           ///

// PASO 3, FUNCIÓN 1: CARGA LOS PRECIOS DE LOS PREPARADOS AUTOMATICAMENTE, CON UN MARGEN DE RENTABILIDAD DEL 51%.
void cargaPreciosPreparadosAutomaticamente(float costoPreparados[], Preparacion listaPreparaciones[], Receta listaRecetas[], StockIngrediente listaIngredientes[], PrecioPreparacion listaPrecios[], int cantIngredientes, int cantReceta)
{
    // ACLARACION: ESTA FUNCIÓN NO ESTABA EN LOS REQUISITOS, PERO ENCONTRAMOS MAS EFICIENTE PARA EL DEBBUGGING DEL PROGRAMA, QUE SE FUERAN CARGANDO AUTOMATICAMENTE, PARA AHORRAR TIEMPO ESENCIAL PARA PODER VERIFICAR LA INFORMACION QUE SE UTILIZA EN EL RESTO DE LAS FUNCIONES

    float suma = 0, rentabilidad = 1.51;
    int posReceta = 0;

    for (int i = 0; i < cantReceta; i++)
    {
        posReceta = buscarRecetaPorNombre(listaPreparaciones[i], listaRecetas, cantReceta);
        if (posReceta >= 0)
        {
            for (int j = 0; j < listaRecetas[posReceta].cantIngredientes; j++)
            {
                int posIngrediente = buscarIngredientePorNombre(listaIngredientes, listaRecetas[posReceta].ingredientes[j], cantIngredientes);
                suma += (listaIngredientes[posIngrediente].costo) * (listaRecetas[posReceta].ingredientes[j].cantidad);
            }
        }

        costoPreparados[i] = suma; // esto se agregó para facilitar el mecanismo del paso 4

        suma *= rentabilidad;
        strcpy(listaPrecios[i].nombre_preparacion, listaRecetas[posReceta].nombre_preparacion);
        listaPrecios[i].precio_venta = suma;

        suma = 0; // se resetea cada vez para no mezclar/pisar valores
    }
}

// PASO 3, FUNCIÓN 2: CARGA LOS PRECIOS DE LOS PREPARADOS EN BASE A LO QUE DESEE EL USUARIO.
void cargaPreciosPreparadosPorElUsuario(float costoPreparados[], Preparacion listaPreparaciones[], Receta listaRecetas[], StockIngrediente listaIngredientes[], PrecioPreparacion listaPrecios[], int cantIngredientes, int cantReceta)
{
    float suma = 0, asignarPrecio = -1;
    int posReceta = 0;

    for (int i = 0; i < cantReceta; i++)
    {
        posReceta = buscarRecetaPorNombre(listaPreparaciones[i], listaRecetas, cantReceta); // va buscando en la lista de recetas y si da -1 significa que no la encontró. Por ello, se comprueba que posReceta sea mayor o igual a 0

        if (posReceta >= 0)
        {
            for (int j = 0; j < listaRecetas[posReceta].cantIngredientes; j++)
            {
                int posIngrediente = buscarIngredientePorNombre(listaIngredientes, listaRecetas[posReceta].ingredientes[j], cantIngredientes);
                suma += (listaIngredientes[posIngrediente].costo) * (listaRecetas[posReceta].ingredientes[j].cantidad);
            }
        }

        costoPreparados[i] = suma;

        while (asignarPrecio <= 0) // se verifica que se esté ingresando un precio mayor a 0 por si el user se equivoca e ingresa un número negativo.
        {
            printf("\nCosto preparado %s: %.2f.\n\tIngrese el precio que desea cobrar: ", listaPreparaciones[i].nombre_preparacion, suma);
            scanf("%f", &asignarPrecio);
        }

        strcpy(listaPrecios[i].nombre_preparacion, listaRecetas[posReceta].nombre_preparacion);
        listaPrecios[i].precio_venta = asignarPrecio;

        suma = 0;           // se resetea cada vez para que no se vayan mezclando los valores
        asignarPrecio = -1; // se resetea cada vez, para no pisar valores, y también para el while, que impide cargar valores negativos
    }
}

// PASO 3, FUNCIÓN 3: FUNCIÓN de carga de precios de los preparados en el archivo precios.bin
void cargaArchivoPrecios(char archivoPrecios[], PrecioPreparacion listaPrecios[], int cantPedidos)
{
    FILE *fp;
    fp = fopen(archivoPrecios, "wb");
    if (fp != NULL)
    {
        for (int i = 0; i < cantPedidos; i++)
        {
            fwrite(&listaPrecios[i], sizeof(PrecioPreparacion), 1, fp);
        }

        fclose(fp);
    }
    else
    {
        printf("Error. No se ha podido abrir el archivo de precios de preparados para su carga.\n");
    } // La mayoría, si no todos los mensajes de error, son únicos. Esto me ayudó mucho a descubrir en qué parte estaba fallando mi código, durante las sesiones de debbugging.
}

// PASO 3, FUNCIÓN 4: LEE EL ARCHIVO DE PRECIOS Y LO DEJA LISTO PARA SU UTILIZACIÓN
void lecturaArchivoPrecios(char archivoPrecios[], PrecioPreparacion listaPrecios[], int cantPedidos)
{
    FILE *fp;
    fp = fopen(archivoPrecios, "rb");
    if (fp != NULL)
    {
        for (int i = 0; i < cantPedidos; i++)
        {
            fread(&listaPrecios[i], sizeof(PrecioPreparacion), 1, fp);
        }
        fclose(fp);
    }
    else
    {
        printf("Error. No se ha podido abrir el archivo de precios de preparados para su lectura.\n");
    }
}

// PASO 3, FUNCIÓN 5: MUESTRA UN PRECIO
void mostrarUnPrecio(PrecioPreparacion listaPrecios)
{
    printf(" %s. ", listaPrecios.nombre_preparacion);
    printf("Precio Venta: $%.2f\n", listaPrecios.precio_venta);
}

// PASO 3, FUNCIÓN 6: MUESTRA UNA LISTA DE PRECIOS
void mostrarListaPrecios(PrecioPreparacion listaPrecios[], int cantPedidos)
{
    printf("\n");
    for (int i = 0; i < cantPedidos; i++)
    {
        printf("Receta #%i: ", i);
        mostrarUnPrecio(listaPrecios[i]);
        printf("\n");
    }
}

// PASO 3, FUNCIÓN 7: CAMBIA EL PRECIO DE UN PREPARADO
void cambiarPrecioPreparado(PrecioPreparacion listaPrecios[], int numReceta)
{

    if (listaPrecios[numReceta].precio_venta > 0)
    {
        printf("\n\tReceta: %s. Precio actual: $%.2f.\n", listaPrecios[numReceta].nombre_preparacion, listaPrecios[numReceta].precio_venta);
    }
    else
    {
        printf("\n\tReceta: %s.\n", listaPrecios[numReceta].nombre_preparacion);
    } // realicé esta comprobación por si acaso no se ejecuta la opción de cargar precios y se va directo a la de modificación.

    listaPrecios[numReceta].precio_venta = -1; // para que entre al while y el user sólo pueda cargar números positivos sobre 0

    while (listaPrecios[numReceta].precio_venta < 0)
    {
        printf("Que precio desea asignarle?: ");
        scanf("%f", &listaPrecios[numReceta].precio_venta);
    }
}

// PASO 3, FUNCIÓN 8: CAMBIA EL PRECIO DE VARIOS PREPARADOS, TANTO COMO QUIERA EL USUARIO
void cambiarPrecioVariosPreparados(PrecioPreparacion listaPrecios[], int numReceta, char seguir)
{
    seguir = 's';

    printf("\t---------- CARGA DE PRECIOS PREPARADOS --------\t");
    while (seguir == 's' || seguir == 'S')
    {
        while (numReceta < 0 || numReceta > 12)
        {
            printf("\nIngrese numero de la preparacion a la que desea cambiarle el precio: ");
            fflush(stdin);
            scanf("%i", &numReceta);
        }

        cambiarPrecioPreparado(listaPrecios, numReceta);

        printf("\nDesea cambiar el precio de otra receta? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);
        numReceta = -1; // reseteo de valor para que entre al while y no haya problemas con el ingreso de datos.
    }
}

// PASO 3, FUNCIÓN 9: CARGA UNA VENTA
void cargarUnaVenta(Venta *listaVentas, int cantRecetas, int *cantPedidosPrep, PreparacionVenta preparadosParaVenta[], PrecioPreparacion listaPrecios[])
{
    int numReceta = 0, i = 0;
    char continuar = 's';
    *cantPedidosPrep = 0;

    while ((*cantPedidosPrep < 20) && (continuar == 's'))
    {
        (*listaVentas).items_pedido[*cantPedidosPrep].cantidad = 0; // reset de cantidad a pedir, sin esto, se pisarían datos. Costó muchas sesiones de debbugging descubrir que debía hacerse este reset en particular

        printf("\tLista preparaciones en stock:\t"); // aquí se van mostrando las recetas que disponen de stock. A fines prácticos, nos resultó mejor de esta forma, ya que si mostrabamos todas las recetas era más fácil equivocarse e ingresar el numero de una receta que no disponía de stock. Las cantidades se van actualizando para reflejar las ventas realizadas
        for (int i = 0; i < cantRecetas; i++)
        {
            if (preparadosParaVenta[i].cantidad > 0)
            {
                printf("\n");
                printf("Receta %-2i: %-5s.\nCantidad: %i. Precio: $%.2f", i, preparadosParaVenta[i].nombre_preparacion, preparadosParaVenta[i].cantidad, listaPrecios[i].precio_venta);
                printf("\n");
            }
        }

        printf("\n\tIngrese cual producto desea (de 0 a 12): ");
        scanf("%i", &numReceta);
        printf("\n");
        while (numReceta < 0 || numReceta > 12)
        {
            printf("Ingrese cual producto desea (de 0 a 12): ");
            scanf("%i", &numReceta);
        }

        strcpy((*listaVentas).items_pedido[*cantPedidosPrep].nombre_preparacion, preparadosParaVenta[numReceta].nombre_preparacion);

        if (preparadosParaVenta[numReceta].cantidad > 0) // para que no se le pregunte innecesariamente al usuario qué cantidad desea de algo que no tiene stock
        {
            while ((*listaVentas).items_pedido[*cantPedidosPrep].cantidad <= 0)
            {
                printf("Ingrese que cantidad desea de %s: ", preparadosParaVenta[numReceta].nombre_preparacion);
                fflush(stdin);
                scanf("%i", &(*listaVentas).items_pedido[*cantPedidosPrep].cantidad);
            }
        }

        if ((preparadosParaVenta[numReceta].cantidad >= (*listaVentas).items_pedido[*cantPedidosPrep].cantidad) && (preparadosParaVenta[numReceta].cantidad > 0)) // sólo entran en la venta los productos que tienen un stock mayor a 0
        {
            preparadosParaVenta[numReceta].cantidad = (preparadosParaVenta[numReceta].cantidad) - ((*listaVentas).items_pedido[*cantPedidosPrep].cantidad);
            (*cantPedidosPrep) = (*cantPedidosPrep) + 1;
            (*listaVentas).activo = 1;
        }
        else
        {
            printf("No hay suficiente stock del producto %s. \n", (*listaVentas).items_pedido[*cantPedidosPrep].nombre_preparacion);
        }

        printf("Desea seguir pidiendo productos? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    // con fines prácticos, para el debbugging y la correcta muestra de la información cargada, mostramos aquí la información de la venta que pasó el usuario
    for (i = 0; i < *cantPedidosPrep; i++)
    {
        printf("\tReceta a realizar: %-2s\n", (*listaVentas).items_pedido[i].nombre_preparacion);
        printf("\tCantidad a realizar: %-2i\n", (*listaVentas).items_pedido[i].cantidad);
    }
    printf("\tEstado activo (1. SI | 0. NO): %-2i\n", (*listaVentas).activo); // esto no era necesario imprimirlo en pantalla ya que si llegó hasta aquí el user, su venta debería estar activa. Lo agregamos en la última sesión de debbugging en grupo, ya que originalmente no funcionaba bien la asignación del estado de activo.
    printf("------------------------------------------------\n");
}

// PASO 3, FUNCIÓN 10: CARGA UNA LISTA DE VENTAS
void cargarListaVentas(Venta listaVentas[], int *cantVentas, PreparacionVenta preparadosParaVenta[], int cantPedidos, PrecioPreparacion listaPrecios[], int cantPrecios, int *idAux)
{
    int i = 0, cantPedidosPrep = 0;
    char continuar = 's';

    while ((continuar == 's') || (continuar == 'S'))
    {
        printf("\t\tCliente numero %i:\t\n", (*idAux));
        listaVentas[i].idVenta = (*idAux);
        cargarUnaVenta(&listaVentas[i], cantPedidos, &cantPedidosPrep, preparadosParaVenta, listaPrecios);
        listaVentas[i].cantItems = cantPedidosPrep;
        calculoTotalUnaVenta(&listaVentas[i], listaPrecios, cantPrecios);
        printf("\t\tValor a pagar: $%.2f\t\n", listaVentas[i].valor_total);
        i++;
        (*idAux)++;
        printf("Desea atender a otro cliente? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    *cantVentas = i;
}

// PASO 3, FUNCIÓN 11: CARGA LA LISTA DE VENTAS AL ARCHIVO DE VENTAS CORRESPONDIENTE (CON WB, SOBREESCRIBIENDO)
void cargarArchivoVentasSobreescribiendo(char archivoVentas[], Venta listaVentas[], int cantVentasEnArchivo)
{

    FILE *fp;
    fp = fopen(archivoVentas, "wb");
    if (fp != NULL)
    {

        for (int i = 0; i < cantVentasEnArchivo; i++)
        {
            fwrite(&listaVentas[i], sizeof(Venta), 1, fp);
        }

        fclose(fp);
    }
    else
    {
        printf("Error. No se ha podido abrir el archivo de ventas para su carga.");
    }
}

// PASO 3, FUNCIÓN 12: CARGA LA LISTA DE VENTAS AL ARCHIVO DE VENTAS CORRESPONDIENTE, SIN SOBREESCRIBIR (APPEND)
void cargarVentasEnArchivoConAppend(char archivoVentas[], Venta listaVentas[], int cantVentas)
{ // ACLARACIÓN IMPORTANTE SOBRE ESTA FUNCIÓN: La utilicé en la carga ya que me resultó más práctico por cómo estructuré la carga de las ventas, que se vayan agregando al archivo al final. De cualquier manera siempre se puede sobreescribir el archivo con la opción del menú correspondiente.

    FILE *fp;
    fp = fopen(archivoVentas, "ab");
    if (fp != NULL)
    {
        for (int i = 0; i < cantVentas; i++)
        {
            fwrite(&listaVentas[i], sizeof(Venta), 1, fp);
        }
        fclose(fp);
    }
    else
    {
        printf("Error. No se ha podido abrir el archivo de ventas para su carga con append.");
    }
}

// PASO 3, FUNCIÓN 13: LEE LA LISTA DE VENTAS DEL ARCHIVO CORRESPONDIENTE,
void lecturaArchivoVentas(char archivoVentas[], Venta listaVentas[], int idAux)
{
    int i = 0;
    FILE *fp;
    fp = fopen(archivoVentas, "rb");

    if (fp != NULL)
    {
        fseek(fp, 0, SEEK_SET);
        while ((fread(&listaVentas[i], sizeof(Venta), 1, fp) != 0))
        {
            i++;
        }

        fclose(fp);
    }
    else
    {
        printf("Error. No se ha podido abrir el archivo de ventas para su lectura.");
    }
}

// PASO 3, FUNCIÓN 14: MUESTRA UNA VENTA
void mostrarUnaVenta(Venta listaVentas)
{
    for (int i = 0; i < listaVentas.cantItems; i++)
    {
        printf("Producto pedido: %s. Cantidad: %i. \n", listaVentas.items_pedido[i].nombre_preparacion, listaVentas.items_pedido[i].cantidad);
    }
}

// PASO 3, FUNCIÓN 15: MUESTRA LA LISTA DE VENTAS.
void mostrarListaVentas(Venta listaVentas[], int cantVentas, PrecioPreparacion listaPrecios[], int cantPrecios)
{ // ACLARACION: A VECES SE UTILIZARA EN PARAMETROS LA CANTIDAD DE VENTAS CARGADAS EN LA FUNCIÓN DE VENTAS, NO LA TOTALIDAD DE LAS VENTAS, Y OTRAS VECES, SE MOSTRARAN  TODAS LAS VENTAS. Fue la forma más completa que encontré de mostrar la información requerida por el usuario.

    int cantVentasCanceladas = 0;

    printf("\n----------------------VENTAS--------------------\n");
    for (int i = 0; i < cantVentas; i++)
    {
        if (listaVentas[i].activo == 1)
        {
            if (listaVentas[i].cantItems > 0) // lógicamente sólo se imprimirán las ventas que dispongan de items, y que estén activas actualmente
            {
                printf("\n");
                printf("\t\tIDventa: %i \t\n", listaVentas[i].idVenta);
                mostrarUnaVenta(listaVentas[i]);
                printf("Cantidad de items del pedido: %i \n", listaVentas[i].cantItems);
                calculoTotalUnaVenta(&listaVentas[i], listaPrecios, cantPrecios);
                printf("Valor que abona: $%.2f", listaVentas[i].valor_total);
                printf("\n--------------------------");
                printf("\n");
            }
            printf("\n");
        }
        else
        {
            cantVentasCanceladas++;
            if (cantVentasCanceladas > 1)
            {
                printf("%d ventas han sido canceladas. \n", cantVentasCanceladas);
            }
            else
            {
                printf("wii");
                printf("La venta ha sido cancelada. \n");
            }
            mostrarUnaVenta(listaVentas[i]);
        }
    }
    printf("\n");
}

// PASO 3, FUNCIÓN 16: REALIZA EL CALCULO DE LA SUMA TOTAL A PAGAR POR UNA VENTA
void calculoTotalUnaVenta(Venta *unaVenta, PrecioPreparacion listaPrecios[], int cantPrecios)
{
    float suma = 0.0;

    for (int i = 0; i < (*unaVenta).cantItems; i++)
    {
        for (int j = 0; j < cantPrecios; j++)
        {
            if (strcmpi((*unaVenta).items_pedido[i].nombre_preparacion, listaPrecios[j].nombre_preparacion) == 0)
            {
                suma += listaPrecios[j].precio_venta * (*unaVenta).items_pedido[i].cantidad;
            }
        }
    }

    (*unaVenta).valor_total = suma;
}

// PASO 3, FUNCIÓN 17: REALIZA LA BAJA LOGICA DE UN REGISTRO VENTA DEL ARCHIVO DE VENTAS
int bajaLogica(char archivoVentas[], Venta *unaVenta)
{
    int resultado = 0;
    Venta aux;

    if ((*unaVenta).activo == 1) // antes de realizar cualquier operación, se chequea que se pueda dar de baja la venta
    {
        FILE *fp;
        fp = fopen(archivoVentas, "r+b");

        if (fp != NULL)
        {
            while (fread(&aux, sizeof(Venta), 1, fp) > 0)
            {
                if (((*unaVenta).idVenta == aux.idVenta) && (resultado == 0))
                {
                    fseek(fp, ftell(fp) - sizeof(Venta), SEEK_SET);
                    (*unaVenta).activo = 0;
                    fwrite(&unaVenta, sizeof(Venta), 1, fp);
                    resultado = 1;
                }
            }

            fclose(fp);
        }
        else
        {
            printf("Error. No se ha podido abrir el archivo de ventas para procesar la baja de su venta.\n");
        }
    }
    else
    {
        printf("ERROR. Usted esta intentando cancelar una venta que ya esta cancelada.\n");
    }

    return resultado;
}

// PASO 3, FUNCIÓN 18: REALIZA LA DEVOLUCION AL STOCK DE LAS PREPARACIONES QUE TENIA LA VENTA ANTES DE SER CANCELADA
int devolucionAlStock(PreparacionVenta listaPreparaciones[], PedidoPreparacion unPedido, int cantPreparaciones)
{
    int i = 0, rta = 0;

    while ((strcmpi(listaPreparaciones[i].nombre_preparacion, unPedido.nombre_preparacion) != 0) && (i < cantPreparaciones))
    {
        i++;
    }
    if (i < cantPreparaciones)
    {
        listaPreparaciones[i].cantidad += unPedido.cantidad;
        rta = 1;
    }
    else if (i == cantPreparaciones)
    {
        printf("No se ha podido devolver al stock.");
    }

    return rta;
}

//                                     FIN DE IMPLEMENTACION DE FUNCIONES PASO 3                                                      //

//                                      COMIENZO IMPLEMENTACION FUNCIONES PASO 4                                                         //

// PASO 4: FUNCIÓN 1 --> SIRVE PARA ASIGNARLE A UNA VARIABLE AUXILIAR EL STOCK INICIAL DE LAS PREPARACIONES, PARA LA CUENTA DEL TOTAL
void cargaPreparadosInicio(PreparacionVenta preparadosParaVenta[], int cantPedidos, int StockPrepInicio[])
{
    int i = 0;
    for (i = 0; i < cantPedidos; i++)
    {
        StockPrepInicio[i] = preparadosParaVenta[i].cantidad;
    }
}

// PASO 4: FUNCIÓN 2 ---> SIRVE PARA MOSTRAR LA CANTIDAD RESTANTE DE LOS PRODUCTOS LUEGO DE LA VENTA
void mostrarProductosRemanentes(PreparacionVenta preparadosParaVenta[], int cantPedidos)
{
    printf("\n------------------PRODUCCION REMANENTE-----------------\n\n");
    for (int j = 0; j < cantPedidos; j++) // Muestra la cantidad producida.
    {
        printf("%s: %i \n", preparadosParaVenta[j].nombre_preparacion, preparadosParaVenta[j].cantidad);
    }
}

// PASO 4: FUNCIÓN 3 ----> SIRVE PARA CALCULAR LOS INGRESOS TOTALES DEL DIA DE VENTAS. SE TIENEN EN CUENTA SOLAMENTE LAS VENTAS ACTIVAS.
void calculoYmuestraIngresosTotales(int vendido[], float *ingreso, PreparacionVenta preparadosParaVenta[], int cantPedidos, int StockPrepInicio[], PrecioPreparacion listaPrecios[], Venta listaVentas[], int idAux)
{
    (*ingreso) = 0;

    // calculo ingresosTotales
    for (int i = 0; i < idAux; i++)
    {
        if (listaVentas[i].activo == 1)
        {
            for (i = 0; i < cantPedidos; i++)
            {
                vendido[i] = (StockPrepInicio[i]) - (preparadosParaVenta[i].cantidad);
                (*ingreso) = (*ingreso) + ((vendido[i]) * (listaPrecios[i].precio_venta));
            }
        }
        else
        {
            printf("Venta cancelada. No se toma en cuenta para el calculo de ganancia.\n");
        }
    }

    // muestra de ventas al final del dia
    mostrarListaVentas(listaVentas, idAux, listaPrecios, cantPedidos);
    printf("\nEl ingreso total del dia es: $%.2f \n", *ingreso);
}

// PASO 4: FUNCIÓN 4 ---> CALCULA LA GANANCIA A LO LARGO DEL DIA
void gananciaDia(float costoPreparaciones[], float ingreso, int cantPedidos, int vendido[])
{
    int i = 0;
    float ganancia = 0;

    ganancia = ingreso;

    for (i = 0; i < cantPedidos; i++)
    {
        ganancia = ganancia - vendido[i] * costoPreparaciones[i];
    }
    printf("---------- \n");
    printf("Ganancia del dia: $%.2f \n", ganancia);
}
