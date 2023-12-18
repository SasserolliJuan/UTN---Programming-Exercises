#include "Arreglo_De_Arboles.h"

// ESTRUCTURAS
typedef struct
{
    char animal[30];
    int cant;
    int habitat;
    int idEspecie;
    char especie[20];
} registroArchivo;

// PROTOTIPOS

// Ejercicio 1
void leerArchivoAnimales(char nombreArch[]);
int pasarDeArchivoToADA(celdaEspecie ADA[], char nombreArch[]);
void mostrarADA(celdaEspecie ADA[], int validos);

// Ejercicio 2
FILE *inOrderADA2Arch(FILE *arch, nodoArbol *arbol);
void pasarDeADAToArchivosAnimales(celdaEspecie ADA[], char nombreArch[], int i);
void mostrarArchiXEspecie(char nombreArch[]);

int main()
{

    char nombreArchivo[20] = "animales.dat";

    printf("Datos del archivo: \n\n");
    leerArchivoAnimales(nombreArchivo);

    celdaEspecie ADA[4]; // Su dimension es 4 porque solo son 4 especies de animales. El arreglo se divide por especie. Ej: posicion 0 == mamiferos; posicion 1 == aves: etc.
    int validos = 0;

    validos = pasarDeArchivoToADA(ADA, nombreArchivo);
    printf("Especies cargadas: %i. \n", validos);
    printf("Arbol de animales: \n\n");
    mostrarADA(ADA, validos);

    printf("CARGANDO ARCHIVOS POR ESPECIE. \n\n");

    for (int i = 0; i < 4; i++)
    {
        char nombreArchivoXEspecieACargar[20];

        if (i == 0)
        {
            strcpy(nombreArchivoXEspecieACargar, "Aves");
        }
        else if (i == 1)
        {
            strcpy(nombreArchivoXEspecieACargar, "Peces");
        }
        else if (i == 2)
        {
            strcpy(nombreArchivoXEspecieACargar, "Reptiles");
        }
        else
        {
            strcpy(nombreArchivoXEspecieACargar, "Mamiferos");
        }

        pasarDeADAToArchivosAnimales(ADA, nombreArchivoXEspecieACargar, i);
    }

    for (int i = 0; i < 4; i++)
    {
        char nombreArchivoXEspecieAMostrar[20];

        if (i == 0)
        {
            strcpy(nombreArchivoXEspecieAMostrar, "Aves");
            printf("----ESPECIE: %s----\n", nombreArchivoXEspecieAMostrar);
        }
        else if (i == 1)
        {
            strcpy(nombreArchivoXEspecieAMostrar, "Peces");
            printf("----ESPECIE: %s----\n", nombreArchivoXEspecieAMostrar);
        }
        else if (i == 2)
        {
            strcpy(nombreArchivoXEspecieAMostrar, "Reptiles");
            printf("----ESPECIE: %s----\n", nombreArchivoXEspecieAMostrar);
        }
        else
        {
            strcpy(nombreArchivoXEspecieAMostrar, "Mamiferos");
            printf("----ESPECIE: %s----\n", nombreArchivoXEspecieAMostrar);
        }

        mostrarArchiXEspecie(nombreArchivoXEspecieAMostrar);
    }

    system("pause");
    return 0;
}

// EJERCICIO 1
void leerArchivoAnimales(char nombreArch[])
{
    registroArchivo aux;
    FILE *arch = fopen(nombreArch, "rb");

    if (arch != NULL)
    {
        fseek(arch, 0, SEEK_SET);

        while (fread(&aux, sizeof(registroArchivo), 1, arch) > 0)
        {
            printf("ANIMAL: %s\n", aux.animal);
            printf("CANTIDAD: %i\n", aux.cant);
            printf("HABITAT: %i\n", aux.habitat);
            printf("ID DE ESPECIE: %i\n", aux.idEspecie);
            printf("ESPECIE: %s\n", aux.especie);
            printf("\n");
        }
        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

int pasarDeArchivoToADA(celdaEspecie ADA[], char nombreArch[])
{
    animal datos;
    int validosAct = 0;

    FILE *arch = fopen(nombreArch, "rb");

    if (arch != NULL)
    {
        fseek(arch, 0, SEEK_SET);

        while (fread(&datos, sizeof(registroArchivo), 1, arch) > 0)
        {
            validosAct = ingresar_animales_al_arreglo(ADA, datos, validosAct);
        }
        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }

    return validosAct;
}

void inOrder(nodoArbol *arbol)
{
    if (arbol != NULL)
    {
        inOrder(arbol->izq);

        printf("ANIMAL: %s\n", arbol->dato.nombreAnimal);
        printf("HABITAT: %i\n", arbol->dato.habitat);
        printf("CANTIDAD: %i\n", arbol->dato.cantidad);
        printf("ID DE ESPECIE: %i\n", arbol->dato.idEspecie);
        printf("\n");

        inOrder(arbol->der);
    }
}

void mostrarADA(celdaEspecie ADA[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf("----ESPECIE: %s---- \n\n", ADA[i].especie);

        nodoArbol *arbol = ADA[i].arbolDeAnimales;

        inOrder(arbol);
    }
}

// EJERCICIO 2
FILE *inOrderADA2Arch(FILE *arch, nodoArbol *arbol)
{
    if (arbol != NULL)
    {
        inOrderADA2Arch(arch, arbol->izq);
        fwrite(&(arbol->dato), sizeof(animal), 1, arch);
        inOrderADA2Arch(arch, arbol->der);
    }

    return arch;
}

void pasarDeADAToArchivosAnimales(celdaEspecie ADA[], char nombreArch[], int i)
{
    FILE *arch = fopen(nombreArch, "wb");

    if (arch != NULL)
    {
        nodoArbol *arbolAux = ADA[i].arbolDeAnimales;

        arch = inOrderADA2Arch(arch, arbolAux);

        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void mostrarArchiXEspecie(char nombreArch[])
{
    animal aux;
    FILE *arch = fopen(nombreArch, "rb");

    if (arch != NULL)
    {
        fseek(arch, 0, SEEK_SET);

        while (fread(&aux, sizeof(animal), 1, arch) > 0)
        {
            printf("ANIMAL: %s\n", aux.nombreAnimal);
            printf("HABITAT: %i\n", aux.habitat);
            printf("CANTIDAD: %i\n", aux.cantidad);
            printf("ID DE ESPECIE: %i\n", aux.idEspecie);
            printf("\n");
        }
        fclose(arch);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}
