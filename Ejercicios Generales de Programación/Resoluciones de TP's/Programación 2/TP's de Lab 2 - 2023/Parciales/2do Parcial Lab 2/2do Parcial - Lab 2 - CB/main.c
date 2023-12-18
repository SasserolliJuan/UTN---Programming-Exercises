#include "libreria_listas_simples.h"

// PROTOTIPOS
int buscarPosCategoria(stBoleteria ADL[], char categoria[], int validos);
int agregarCategoria(stBoleteria ADL[], char categoria[], int validos);
int cargarArregloListas(stBoleteria ADL[], int validos, int aCargar);
void imprimir(nodoEntrada *lista);
void mostrarLista(nodoEntrada *lista);
void mostrarArregloDeListas(stBoleteria ADL[], int validos);
nodoFila *preguntarDatosAlUsuario(nodoFila *aux, char categoria[]);
int verificarDatosEntrada(nodoFila *entrada, nodoEntrada *listaEntradas);
int verificarExistenciaEntrada(nodoFila *entrada, stBoleteria ADL[], char categoriaABuscar[], int validos);
nodoFila *agregarAlFinal(nodoFila *lista, nodoFila *nuevoNodo);
void agregarFila(fila *f, nodoFila *nuevoNodo);
nodoEntrada *borrarNodoEntradaXDatos(nodoEntrada *listaEntradas, nodoFila *aBorrar);
nodoEntrada *borrarNodo(stBoleteria ADL[], nodoFila *nodoABorrar, char categoria[], int validos);
void imprimirNodoFila(nodoFila *nodo);
int mostrarFila(fila filita);
nodoFila *verPrimero(nodoFila *lista);
nodoFila *borrarPrimero(nodoFila *lista);
nodoFila *extraer(fila *fila);

int buscarPosCategoria(stBoleteria ADL[], char categoria[], int validos);
int agregarCategoria(stBoleteria ADL[], char categoria[], int validos);
int cargarArregloListas(stBoleteria ADL[], int validos, int aCargar);
void imprimir(nodoEntrada *lista);
void mostrarLista(nodoEntrada *lista);
void mostrarArregloDeListas(stBoleteria ADL[], int validos);
nodoFila *preguntarDatosAlUsuario(nodoFila *aux, char categoria[]);
int verificarDatosEntrada(nodoFila *entrada, nodoEntrada *listaEntradas);
int verificarExistenciaEntrada(nodoFila *entrada, stBoleteria ADL[], char categoriaABuscar[], int validos);
nodoFila *agregarAlFinal(nodoFila *lista, nodoFila *nuevoNodo);
void agregarFila(fila *f, nodoFila *nuevoNodo);
nodoEntrada *borrarNodoEntradaXDatos(nodoEntrada *listaEntradas, nodoFila *aBorrar);
nodoEntrada *borrarNodo(stBoleteria ADL[], nodoFila *nodoABorrar, char categoria[], int validos);
void imprimirNodoFila(nodoFila *nodo);
int mostrarFila(fila filita);
nodoFila *verPrimero(nodoFila *lista);
nodoFila *borrarPrimero(nodoFila *lista);
nodoFila *extraer(fila *fila);

int main()
{
    int upc = 0;
    char mander = 's';
    srand(time(NULL));

    stBoleteria ADL[200];
    int validos = 0;

    fila filita;
    filita.primero = NULL;
    filita.ultimo = NULL;

    printf("Elija un ejercicio...\n");

    system("pause");
    system("cls");

    while (mander == 's')
    {
        printf("1. Cargar boleteria. \n");
        printf("2. Ver boleterias. \n");
        printf("3. Cargar participiantes. \n");
        printf("4. Ver participantes. \n");
        printf("5. Dia del evento. \n");
        printf("6. Salir.");
        printf("\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%i", &upc);

        system("cls");

        switch (upc)
        {
        case 1:
        {
            int celdasACargar = 0;
            printf("Ingrese cuantas celdas desea cargar: ");
            fflush(stdin);
            scanf("%i", &celdasACargar);

            validos = cargarArregloListas(ADL, validos, celdasACargar);
            break;
        }
        case 2:
        {
            mostrarArregloDeListas(ADL, validos);
            break;
        }
        case 3:
        {
            int j = 0;
            int cantUsuarios = 0;

            printf("Cuantos usuarios desean comprar entradas?: ");
            fflush(stdin);
            scanf("%i", &cantUsuarios);

            while (j < cantUsuarios)
            {
                char categoria[20];
                nodoFila *aux = NULL; // No need to allocate memory here

                printf("Categoria: ");
                fflush(stdin);
                scanf("%s", categoria);

                aux = preguntarDatosAlUsuario(aux, categoria);

                int rta = 0;
                rta = verificarExistenciaEntrada(aux, ADL, categoria, validos);

                if (rta == 1)
                {
                    printf("Felicidades! Aqui tiene su entrada. \n");

                    agregarFila(&filita, aux);

                    ADL[validos - 1].entradas = borrarNodo(ADL, aux, categoria, validos);
                }
                else
                {
                    printf("Lo sentimos. No se ha encontrado ninguna entrada con esos requisitos. \n");
                }
                j++;
            }

            break;
        }
        case 4:
        {
            int usuarios = mostrarFila(filita);
            printf("%i usuarios han comprado una entrada. \n", usuarios);
            break;
        }
        case 5:
        {
            int k = 0;
            int cantUsuarios = 0;
            nodoFila *aux = NULL;

            cantUsuarios = mostrarFila(filita);

            while (k < cantUsuarios)
            {
                aux = extraer(&filita);
                printf("Se ha atendido al cliente %s. \n", aux->nombreParticipante);
                k++;
            }
            break;
        }
        case 6:
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
        printf("Desea volver al menu principal?: s/n");
        fflush(stdin);
        scanf("%c", &mander);
        system("cls");
    }

    return 0;
}

// EJERCICIO 1
int buscarPosCategoria(stBoleteria ADL[], char categoria[], int validos)
{
    int rta = -1;
    int i = 0;

    while (i < validos && rta == -1)
    {
        if (strcmp(ADL[i].categoria, categoria) == 0)
        {
            rta = i;
        }
        i++;
    }
    return rta;
}

int agregarCategoria(stBoleteria ADL[], char categoria[], int validos)
{
    strcpy(ADL[validos].categoria, categoria);
    ADL[validos].entradas = NULL;

    validos++;

    return validos;
}

int cargarArregloListas(stBoleteria ADL[], int validos, int aCargar)
{
    int i = 0;

    while (i < aCargar)
    {
        char categoria[20];
        stEntrada datos;

        printf("Ingrese el id del ticket: ");
        fflush(stdin);
        scanf("%i", &datos.idTicket);

        printf("Ingrese estado de vip (1 = VIP) - (0 = NO VIP): ");
        fflush(stdin);
        scanf("%i", &datos.isVIP);

        printf("Ingrese el sector (palco, pullman, campo, platea): ");
        fflush(stdin);
        scanf("%s", datos.sector);

        printf("Ingrese la categoria de la entrada (clasica, premium, deluxe, estudiante): ");
        fflush(stdin);
        scanf("%s", categoria);

        printf("\n");

        nodoEntrada *aux = crearNodoEntrada(datos);

        int pos = buscarPosCategoria(ADL, categoria, validos);

        if (pos == -1)
        {
            validos = agregarCategoria(ADL, categoria, validos);
            pos = validos - 1;
        }

        ADL[pos].entradas = agregarAlPpio(ADL[pos].entradas, aux);
        i++;
    }

    return validos;
}

void imprimir(nodoEntrada *lista)
{
    printf("idTicket: %i\n", lista->unaEntrada.idTicket);
    printf("VIP: %i\n", lista->unaEntrada.isVIP);
    printf("Sector: %s\n", lista->unaEntrada.sector);
    printf("\n");
}

void mostrarLista(nodoEntrada *lista)
{
    nodoEntrada *seg = lista;

    while (seg != NULL)
    {
        imprimir(seg);
        seg = seg->sig;
    }
}

void mostrarArregloDeListas(stBoleteria ADL[], int validos)
{
    int i = 0;

    while (i < validos)
    {
        printf("---Categoria %s (Celda %i): ---\n", ADL[i].categoria, i);
        mostrarLista(ADL[i].entradas);
        i++;
    }
}

// EJERCICIO 2
nodoFila *preguntarDatosAlUsuario(nodoFila *aux, char categoria[])
{
    if (aux == NULL)
    {
        aux = (nodoFila *)malloc(sizeof(nodoFila));
    }

    int isVIP = 0;
    int idTicket = 0;

    printf("Ingrese su nombre: ");
    fflush(stdin);
    scanf("%s", aux->nombreParticipante);

    printf("Ingrese que tipo de entrada desea: \n");
    fflush(stdin);

    printf("Sector: ");
    fflush(stdin);
    scanf("%s", aux->entradaAsignada.sector);

    printf("VIP (1 = VIP) - (0 = NO VIP): ");
    fflush(stdin);
    scanf("%i", &isVIP);

    aux->entradaAsignada.isVIP = isVIP;

    printf("idTicket: ");
    fflush(stdin);
    scanf("%i", &idTicket);

    aux->entradaAsignada.idTicket = idTicket;

    aux->sig = NULL;

    return aux;
}

int verificarDatosEntrada(nodoFila *entrada, nodoEntrada *listaEntradas)
{
    int rta = 0;
    nodoEntrada *seg = listaEntradas;

    while (seg != NULL)
    {
        if ((strcmp(seg->unaEntrada.sector, entrada->entradaAsignada.sector) == 0) && (seg->unaEntrada.isVIP == entrada->entradaAsignada.isVIP))
        {
            rta = 1;
        }
        seg = seg->sig;
    }
    return rta;
}

int verificarExistenciaEntrada(nodoFila *entrada, stBoleteria ADL[], char categoriaABuscar[], int validos)
{
    int rta;
    int pos = buscarPosCategoria(ADL, categoriaABuscar, validos);

    if (pos == -1)
    {
        rta = 0;
    }
    else
    {
        rta = verificarDatosEntrada(entrada, ADL[pos].entradas);
    }

    return rta;
}

nodoFila *agregarAlFinal(nodoFila *lista, nodoFila *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoFila *seg = lista;

        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }

        seg->sig = nuevoNodo;
    }
    return lista;
}

void agregarFila(fila *f, nodoFila *nuevoNodo)
{
    if (f->primero == NULL)
    {
        f->primero = nuevoNodo;
        f->ultimo = nuevoNodo;
    }
    else
    {
        f->ultimo->sig = nuevoNodo;
        f->ultimo = nuevoNodo;
    }
}

nodoEntrada *borrarNodoEntradaXDatos(nodoEntrada *listaEntradas, nodoFila *aBorrar)
{
    nodoEntrada *ante = NULL;
    nodoEntrada *seg = listaEntradas;
    int encontrado = 0;

    while (seg != NULL && !encontrado)
    {
        if (strcmp(seg->unaEntrada.sector, aBorrar->entradaAsignada.sector) == 0 && seg->unaEntrada.isVIP == aBorrar->entradaAsignada.isVIP)
        {
            if (ante != NULL)
            {
                ante->sig = seg->sig;
            }
            else
            {

                listaEntradas = seg->sig;
            }

            free(seg);
            encontrado = 1;
        }

        ante = seg;
        seg = seg->sig;
    }

    return listaEntradas;
}

nodoEntrada *borrarNodo(stBoleteria ADL[], nodoFila *nodoABorrar, char categoria[], int validos)
{
    int rta = 0;
    int pos = buscarPosCategoria(ADL, categoria, validos);

    if (pos != -1)
    {
        printf("Categoria encontrada. Buscando nodo a borrar...\n");
        ADL[pos].entradas = borrarNodoEntradaXDatos(ADL[pos].entradas, nodoABorrar);
        rta = 1;
    }

    return ADL[pos].entradas;
}

// EJERCICIO 3
void imprimirNodoFila(nodoFila *nodo)
{
    printf("Nombre del comprador: %s\n", nodo->nombreParticipante);
    printf("idTicket: %i\n", nodo->entradaAsignada.idTicket);
    printf("VIP: %i\n", nodo->entradaAsignada.isVIP);
    printf("Sector: %s\n", nodo->entradaAsignada.sector);
    printf("\n");
}

int mostrarFila(fila filita)
{
    int cantUsuarios = 0;

    if (filita.primero != NULL)
    {
        nodoFila *actual = filita.primero;

        while (actual != NULL)
        {
            imprimirNodoFila(actual);
            cantUsuarios++;
            actual = actual->sig;
        }
    }
    else
    {
        printf("Fila vacia. \n");
    }

    return cantUsuarios;
}

nodoFila *verPrimero(nodoFila *lista)
{
    nodoFila *aux = (nodoFila *)malloc(sizeof(nodoFila));

    if (lista != NULL)
    {
        aux = lista;
    }

    return aux;
}

nodoFila *borrarPrimero(nodoFila *lista)
{
    if (lista != NULL)
    {
        nodoFila *borrar = lista;
        lista = lista->sig;
        borrar->sig = NULL;
        free(borrar);
    }
    return lista;
}

nodoFila *extraer(fila *fila)
{
    nodoFila *resp = (nodoFila *)malloc(sizeof(nodoFila));

    if (fila->primero != NULL)
    {
        resp = verPrimero(fila->primero);

        fila->primero = borrarPrimero(fila->primero);

        if (fila->primero == NULL)
        {
            fila->ultimo = NULL;
        }
    }

    return resp;
}
