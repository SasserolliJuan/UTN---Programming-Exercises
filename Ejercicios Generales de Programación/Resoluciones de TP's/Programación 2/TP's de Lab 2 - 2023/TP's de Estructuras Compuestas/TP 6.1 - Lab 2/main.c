#include "Arreglo_De_Listas_Simples.h"

// ESTRUCTURAS
typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
    char materia[40];
    int idMateria;
} registroArchivo;

// PROTOTIPOS

// Ejercicio 1
void cargarArchivo(int cantAlumnos, char nombreArch[]);
void mostrarArchivo(char nombreArch[]);

// Ejercicio 2
int pasarDeArchivoToADL(celda ADL[], char nombreArch[]);
void mostrarADL(celda ADL[], int validos);

// Ejercicio 3
void pasarDeADLToArchivoDeAprobados(celda ADL[], char nombreArch[], int validos);
void mostrarArchivoAprobados(char nombreArch[]);

int main()
{

    char nombreArch[20];
    printf("Ingrese el nombre del archivo de alumnos: ");
    fflush(stdin);
    scanf("%s", nombreArch);

    int cantAlumnos = 0;
    printf("Ingrese la cantidad de alumnos a cargar: ");
    fflush(stdin);
    scanf("%i", &cantAlumnos);

    cargarArchivo(cantAlumnos, nombreArch);
    mostrarArchivo(nombreArch);

    celda ADL[20];
    int validos = 0;

    validos = pasarDeArchivoToADL(ADL, nombreArch);
    printf("Se han cargado %i materias. \n\n", validos);
    mostrarADL(ADL, validos);

    char nombreArchAprobados[20];
    printf("Ingrese el nombre del archivo de alumnos aprobados: ");
    fflush(stdin);
    scanf("%s", nombreArchAprobados);

    pasarDeADLToArchivoDeAprobados(ADL, nombreArchAprobados, validos);
    mostrarArchivoAprobados(nombreArchAprobados);

    system("pause");
    return 0;
}

// EJERCICIO 1
void cargarArchivo(int cantAlumnos, char nombreArch[])
{
    FILE *arch = fopen(nombreArch, "wb");

    if (arch != NULL)
    {
        for (int i = 0; i < cantAlumnos; i++)
        {
            registroArchivo datos;

            printf("Ingrese la nota: ");
            fflush(stdin);
            scanf("%i", &datos.nota);

            printf("Ingrese el legajo: ");
            fflush(stdin);
            scanf("%i", &datos.legajo);

            printf("Ingrese el nombre del alumno: ");
            fflush(stdin);
            scanf("%s", datos.nombreApe);

            printf("Ingrese la materia: ");
            fflush(stdin);
            scanf("%s", &datos.materia);

            printf("Ingrese el ID de la materia: ");
            fflush(stdin);
            scanf("%i", &datos.idMateria);

            fwrite(&datos, sizeof(registroArchivo), 1, arch);
            printf("\n");
        }

        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void mostrarArchivo(char nombreArch[])
{
    registroArchivo aux;
    FILE *arch = fopen(nombreArch, "rb");

    if (arch != NULL)
    {
        fseek(arch, 0, SEEK_SET);

        while (fread(&aux, sizeof(registroArchivo), 1, arch) > 0)
        {
            printf("NOTA: %i\n", aux.nota);
            printf("LEGAJO: %i\n", aux.legajo);
            printf("ALUMNO: %s\n", aux.nombreApe);
            printf("MATERIA: %s\n", aux.materia);
            printf("ID DE MATERIA: %i\n", aux.idMateria);
            printf("\n");
        }
        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// EJERCICIO 2
int pasarDeArchivoToADL(celda ADL[], char nombreArch[])
{
    notaAlumno aux;
    int validosAct = 0;

    FILE *arch = fopen(nombreArch, "rb");

    if (arch != NULL)
    {
        fseek(arch, 0, SEEK_SET);

        while (fread(&aux, sizeof(registroArchivo), 1, arch) > 0)
        {
            validosAct = ingresar_notas_al_arreglo(ADL, aux, validosAct);
        }

        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }

    return validosAct;
}

void mostrarADL(celda ADL[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf("Materia: %s\n", ADL[i].materia);

        nodo_lista_simple *actual = ADL[i].listaDeNotas;

        while (actual != NULL)
        {
            printf("NOTA: %i\n", actual->dato.nota);
            printf("LEGAJO: %i\n", actual->dato.legajo);
            printf("ALUMNO: %s\n", actual->dato.nombreApe);
            printf("ID DE MATERIA: %i\n", actual->dato.idMateria);
            actual = actual->siguiente;
        }
    }
}

// EJERCICIO 3
void pasarDeADLToArchivoDeAprobados(celda ADL[], char nombreArch[], int validos)
{
    FILE *arch = fopen(nombreArch, "wb");

    if (arch != NULL)
    {
        for (int i = 0; i < validos; i++)
        {
            nodo_lista_simple *actual = ADL[i].listaDeNotas;

            while (actual != NULL)
            {
                if (actual->dato.nota >= 6)
                {
                    fwrite(&actual->dato.nota, sizeof(int), 1, arch);
                }
                actual = actual->siguiente;
            }
        }

        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void mostrarArchivoAprobados(char nombreArch[])
{
    int notaAux = 0;
    FILE *arch = fopen(nombreArch, "rb");

    if (arch != NULL)
    {
        fseek(arch, 0, SEEK_SET);

        while (fread(&notaAux, sizeof(int), 1, arch) > 0)
        {
            printf("NOTA: %i\n", notaAux);
        }
        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}