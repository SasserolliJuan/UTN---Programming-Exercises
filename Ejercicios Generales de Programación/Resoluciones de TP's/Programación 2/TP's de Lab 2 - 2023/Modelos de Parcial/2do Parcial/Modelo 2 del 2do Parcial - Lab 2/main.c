#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ESTRUCTURAS
typedef struct
{
    char categoria[20];
    float peso;
} Cajon;

typedef struct
{
    float pesoIngresado;
} vagon;

typedef struct nodo
{
    vagon v;
    struct nodo *sig;
} nodo;

typedef struct
{
    int nroTren; // id
    char categoria[20];
    nodo *listaVagones;
} tren;

// PROTOTIPOS

float pesoTotalXCategoria(tren ADL[], char cat[], int validos);
int main()
{
    FILE *materiales;
    cargarArchivo(materiales);
    mostrarArchivo(materiales);

    tren ADL[5]; // Su dimension es 5 porque solo son 5 categorias de materiales.
    int validos = archivo2ArregloDeListas(ADL, materiales);
    mostrarADL(ADL, validos);

    char cat[20];
    printf("Ingrese la categoria a calcular: ");
    fflush(stdin);
    scanf("%s", cat);

    float peso = pesoTotalXCategoria(ADL, cat, validos);
    printf("El peso total de la categoria %s es de %.2f\n", cat, peso);

    system("pause");
    return 0;
}

// EJERCICIO 1
void cargarArchivo(FILE *materiales)
{
    materiales = fopen("cajones.bin", "wb");

    if (materiales != NULL)
    {
        char continuar = 's';

        while (continuar == 's')
        {
            Cajon datos;

            printf("Ingrese la categoria de los materiales: ");
            fflush(stdin);
            scanf("%s", datos.categoria);

            printf("Ingrese el peso: ");
            fflush(stdin);
            scanf("%f", &datos.peso);

            fwrite(&datos, sizeof(Cajon), 1, materiales);

            printf("Desea continuar?: s/n\n");
            fflush(stdin);
            scanf("%c", &continuar);
        }
        fclose(materiales);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. ");
    }
}

void mostrarArchivo(FILE *materiales)
{
    materiales = fopen("cajones.bin", "rb");

    if (materiales != NULL)
    {
        Cajon verDatos;
        fseek(materiales, 0, SEEK_SET);

        while (fread(&verDatos, sizeof(Cajon), 1, materiales) != 0)
        {
            printf("Categoria: %s\n", verDatos.categoria);
            printf("Peso: %.2f\n", verDatos.peso);
        }
        fclose(materiales);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo.");
    }
}

// EJERCICIO 2
int archivo2ArregloDeListas(tren ADL[], FILE *materiales)
{
    int validosAct = 0;
    materiales = fopen("cajones.bin", "rb");

    if (materiales != NULL)
    {
        Cajon verDatos;
        fseek(materiales, 0, SEEK_SET);

        while (fread(&verDatos, sizeof(Cajon), 1, materiales) != 0)
        {
            validosAct = cargarTrenes(ADL, verDatos, validosAct);
        }
        fclose(materiales);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo.\n");
    }

    return validosAct;
}

int cargarTrenes(tren ADL[], Cajon datos, int validosAct)
{
    int validos = validosAct;

    validos = cargarVagones(ADL, datos, validos);

    printf("Tren cargado.\n");
    return validos;
}

nodo *crearNodoVagon(float peso)
{
    nodo *aux = (nodo *)malloc(sizeof(nodo));

    aux->v.pesoIngresado = peso;
    aux->sig = NULL;

    return aux;
}

int buscarPosVagon(tren ADL[], Cajon datos, int validos)
{
    int rta = -1;
    int i = 0;

    while ((i < validos) && (rta == -1))
    {
        if (strcmp(ADL[i].categoria, datos.categoria) == 0)
        {
            rta = i;
        }
        i++;
    }
    return rta;
}

int agregarTren(tren ADL[], Cajon datos, int validos)
{
    strcpy(ADL[validos].categoria, datos.categoria);

    ADL[validos].listaVagones = NULL;

    validos++;

    return validos;
}

nodo *insertarEnVagonXPeso(nodo *lista, nodo *nuevo)
{
    if (lista == NULL)
    {
        nuevo->sig = lista;
        lista = nuevo;
    }
    else
    {
        nodo *seg = lista;

        while (seg != NULL && seg->v.pesoIngresado > nuevo->v.pesoIngresado)
        {
            seg = seg->sig;
        }
        nuevo->sig = seg->sig;
        seg->sig = nuevo;
    }

    return lista;
}

int cargarVagones(tren ADL[], Cajon datos, int validos)
{
    nodo *aux = crearNodoVagon(datos.peso);
    int pos = buscarPosVagon(ADL, datos, validos);

    if (pos == -1)
    {
        validos = agregarTren(ADL, datos, validos);
        pos = validos - 1;
    }
    ADL[pos].listaVagones = insertarEnVagonXPeso(ADL[pos].listaVagones, aux);

    return validos;
}

void mostrarADL(tren ADL[], int validos)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < validos)
    {
        printf("---Tren %i(Material: %s): ---\n", i + 1, ADL[i].categoria);
        printf("Vagon %i: \n", j + 1);
        nodo *seg = ADL[i].listaVagones;

        while (seg != NULL)
        {
            printf("Cajon %i: ", k + 1);
            printf("Peso: %.2f\n", seg->v.pesoIngresado);
            seg = seg->sig;
        }

        i++;
        j++;
        k++;

        printf("\n");
    }
}

// EJERCICIO 3:
float pesoTotalXCategoria(tren ADL[], char cat[], int validos)
{
    int i = 0;
    float pesoTotal = 0;

    while (i < validos)
    {
        if (strcmp(ADL[i].categoria, cat) == 0)
        {
            nodo *seg = ADL[i].listaVagones;

            if (seg != NULL)
            {
                while (seg != NULL)
                {
                    pesoTotal += seg->v.pesoIngresado;
                    seg = seg->sig;
                }
            }
            else
            {
                printf("Error: la lista de vagones esta vacia. \n");
            }
        }
        i++;
    }

    return pesoTotal;
}
