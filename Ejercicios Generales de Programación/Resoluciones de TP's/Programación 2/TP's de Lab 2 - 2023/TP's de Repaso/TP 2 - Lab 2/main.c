#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
   char nombre[30];
   char genero;
   int edad;
}persona;

typedef struct {
   int matricula;
   char nombre[30];
} Alumno;

typedef struct {
   int codigo;
   char nombreMat[20];
} Materia;

typedef struct {
   int matricula;
   int codigo;
   int nota;
} Nota;

// Prototipos de funciones:

//Ejercicio 1:
int cargaArregloEstructuras(persona arregloPersonas[], int* validos);
int contarCantidadGeneroDet(persona arregloPersonas[], int validos);
persona* copiaDeRegistrosDeUnGenDet(persona arregloPersonas[], int validos);

//Ejercicio 2:

//Ejercicio 3:
void cargaPersonaAInsertar(persona* personaAInsertar);
int insercionOrdenadoEnArregloPersonas(persona arregloPersonas[], persona personaAInsertar, int*);

//Ejercicio 5:

//Ejercicio 6:

//Ejercicio 7:

//Ejercicio 8:
void cargaDeMaterias(Materia mats[]);
void agregraUnAlumno(Alumno alus[], int);
void cargarAlumnos(Alumno alus[], int*);
void agregraUnNota(Nota notas[], Materia mats[], Alumno alus[], int);
void mostrarAlumnoYSusNotas(Nota notas[], Materia mats[], Alumno alus[], int);

void main()
{
    persona arregloPersonas[30];
    persona personaAInsertar;
    Alumno alus[20]; // para almacenar los datos de los 20 alumnos.
    Materia mats[5]; // para almacenar los códigos y nombres de las 5 materias.
    Nota notas[100]; // para almacenar todas las notas de los alumnos.
    int validos = 0;

    int opcion = 0;

    printf("Elija uno de los siguientes ejercicios. \n");
    printf("1. Dada una estrutura, cargar 30 elementos del mismo tipo en un arreglo, contar la cantidad de un genero determinado, y copiar todos los datos de un solo registro a otro arreglo auxiliar usando malloc. \n");
    printf("2. Codificar el algoritmo de ordenamiento por seleccion, sobre la estructura anterior teniendo en cuenta la edadcomo criterio de ordenación. \n");
    printf("5. Funcion insertar orden en un arreglo. \n");
    printf("6. Algoritmo de ordenamiento por inserción. \n");
    printf("7. Funcion eliminar un elemento de un arreglo. (ver por desplazamiento si es ordenado). \n");
    printf("8. Sistema de notas. Se tiene que administrar un sistema para un curso con 20 alumnos que cursan 5 materias diferentes. Se deben almacenar los datos de los alumnos y las notas que obtuvieron en el examen final de cada materia dadas 3 estructuras. \n");
    scanf("%i", &opcion);

    system("cls");

    switch(opcion)
    {
        case 1:
            {
                cargaArregloEstructuras(arregloPersonas, &validos);
                mostrarArregloPersonas(arregloPersonas, validos);
                copiaDeRegistrosDeUnGenDet(arregloPersonas, validos);
                break;
            }
        case 2:
            {
                cargaArregloEstructuras(arregloPersonas, &validos);
                printf("\nArreglo de personas desordenado: \n");
                mostrarArregloPersonas(arregloPersonas, validos);
                printf("\nArreglo de personas ordenado: \n");
                ordenamientoPorSeleccionPorEdad(arregloPersonas, validos);
                break;
            }
        case 5:
            {
                cargaArregloEstructuras(arregloPersonas, &validos);
                printf("\nArreglo de personas ordenado SIN el elemento insertado: \n");
                ordenamientoPorSeleccionPorEdad(arregloPersonas, validos);
                printf("\nCarga del dato a insertar: \n");
                cargaPersonaAInsertar(&personaAInsertar);
                printf("\nArreglo de personas ordenado CON el elemento insertado: \n");
                insercionOrdenadoEnArregloPersonas(arregloPersonas, personaAInsertar, &validos);
                mostrarArregloPersonas(arregloPersonas, validos);
                break;
            }
        case 6:
            {
                cargaArregloEstructuras(arregloPersonas, &validos);
                printf("\nArreglo de personas desordenado: \n");
                mostrarArregloPersonas(arregloPersonas, validos);
                printf("\nArreglo de personas ordenado: \n");
                ordenamientoPorInsercionPorEdad(arregloPersonas, validos);
                break;
            }
        case 7:
            {
                char nombreABorrar[30];
                cargaArregloEstructuras(arregloPersonas, &validos);
                printf("\nArreglo de personas: \n");
                mostrarArregloPersonas(arregloPersonas, validos);
                printf("\nIngrese el nombre del registro a borrar: \n");
                fflush(stdin);
                gets(nombreABorrar);
                eliminarUnRegistroDelArreglo(arregloPersonas, nombreABorrar, &validos);
                printf("\nArreglo sin el elemento borrado: \n");
                mostrarArregloPersonas(arregloPersonas, validos);
                break;
            }
        case 8:
            {
                cargarAlumnos(alus, &validos);
                cargaDeMaterias(mats);
                agregraUnNota(notas, mats, alus, validos);
                mostrarAlumnoYSusNotas(notas, mats, alus, validos);
                break;
            }

    }
}

//EJERCICIO 1.
int cargaArregloEstructuras(persona arregloPersonas[], int* validos)
{
    int cant = 0;
    char genero;

    printf("Cuantas personas desea cargar?: \n");
    fflush(stdin);
    scanf("%i", &cant);

    printf("Cargar el arreglo de personas: \n");

    for(int i = 0; i < cant; i++)
    {
        printf("Nombre: ");
        fflush(stdin);
        gets(arregloPersonas[i].nombre);

        printf("Genero: ");
        fflush(stdin);
        scanf("%c", &arregloPersonas[i].genero);

        printf("Edad: ");
        fflush(stdin);
        scanf("%i", &arregloPersonas[i].edad);
        (*validos)++;
    }

    return *validos;
}

int contarCantidadGeneroDet(persona arregloPersonas[], int validos)
{
    int cont = 0;
    char genero;
    printf("De que genero desea saber la cantidad?: \n");

    do
    {
        fflush(stdin);
        scanf("%c", &genero);

    }while((genero != 'm' && genero != 'f'));

    for(int i = 0; i < validos; i++)
    {
        if(arregloPersonas[i].genero == genero)
        {
            cont++;
        }
    }

    printf("Hay %i del genero %c. \n", cont, genero);

    return cont; //Lo retorna para poder usarlo en la siguiente funcion.
}

persona* copiaDeRegistrosDeUnGenDet(persona arregloPersonas[], int validos)
{
    int i = 0, j = 0;
    char genero;
    persona * arregloPersonasAux;
    int cant = contarCantidadGeneroDet(arregloPersonas, validos);
    arregloPersonasAux = (persona*) malloc(cant * sizeof(persona));

    if(arregloPersonasAux != NULL)
    {
         printf("De que genero desea copiar los datos?: \n");

        do
        {
            fflush(stdin);
            scanf("%c", &genero);

        }while((genero != 'm' && genero != 'f'));

        for(i = 0; i < validos && j < cant; i++)
        {
            if(arregloPersonas[i].genero == genero)
            {
                arregloPersonasAux[j] = arregloPersonas[i];
                j++;
            }
        }
    }

    mostrarArregloAux(arregloPersonasAux, cant);

    return arregloPersonasAux;
}

void mostrarArregloPersonas(persona arregloPersonas[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("Nombre: %s\n", arregloPersonas[i].nombre);
        printf("Genero: %c\n", arregloPersonas[i].genero);
        printf("Edad: %i\n", arregloPersonas[i].edad);
    }
}

void mostrarArregloAux(persona arregloPersonasAux[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        printf("Nombre: %s\n", arregloPersonasAux[i].nombre);
        printf("Genero: %c\n", arregloPersonasAux[i].genero);
        printf("Edad: %i\n", arregloPersonasAux[i].edad);
    }
}

//EJERCICIO 2.
void ordenamientoPorSeleccionPorEdad(persona arregloPersonas[], int validos)
{
    int i = 0, k = 0;
    int edadMn = 0;
    int posMn = 0;

    for(i = 0; i < validos - 1; i++)
    {
        edadMn = arregloPersonas[i].edad;
        posMn = i;

        for(int j = i+1; j < validos; j++)
        {
            if(arregloPersonas[j].edad < edadMn)
            {
                edadMn = arregloPersonas[j].edad;
                posMn = j;

            }

            if(posMn != i)
            {

                persona temp = arregloPersonas[i];
                arregloPersonas[i] = arregloPersonas[posMn];
                arregloPersonas[posMn] = temp;
            }
        }
    }

    mostrarArregloPersonas(arregloPersonas, validos);
}

//EJERCICIO 5.
void cargaPersonaAInsertar(persona* personaAInsertar)
{
    printf("Nombre: ");
    fflush(stdin);
    gets(personaAInsertar -> nombre);
    printf("Genero: ");
    fflush(stdin);
    scanf("%c", &personaAInsertar -> genero);
    printf("Edad: ");
    fflush(stdin);
    scanf("%i", &personaAInsertar -> edad);

}

int insercionOrdenadoEnArregloPersonas(persona arregloPersonas[], persona personaAInsertar, int* validos)
{
    int i = 0;

    while(i < *validos && arregloPersonas[i].edad < personaAInsertar.edad) //Busco el hueco.
    {
        i++;
    }

    for(int j = *validos - 1; j >= i; j--)  //Desplazo todo hacia la derecha una vez encontrado el hueco.
    {
        arregloPersonas[j+1] = arregloPersonas[j];
    }

    arregloPersonas[i] = personaAInsertar;
    (*validos)++; //Se modifican los validos porque se suma un elemento más de tipo persona al arreglo de personas.

    return *validos;
}

//EJERCICIO 6.
void ordenamientoPorInsercionPorEdad(persona arregloPersonas[], int validos)
{
    for(int i = 1; i < validos; i++)
    {
        persona temp = arregloPersonas[i];
        int j = i - 1;

        while(j >= 0 && arregloPersonas[j].edad > temp.edad)
        {
            arregloPersonas[j+1] = arregloPersonas[j];
            j--;
        }

        arregloPersonas[j+1] = temp;
    }

    mostrarArregloPersonas(arregloPersonas, validos);
}

//EJERCICIO 7.
int eliminarUnRegistroDelArreglo(persona arregloPersonas[], char nombreABorrar[], int* validos)
{
    int i = 0;

    while(i < *validos)
    {
        if(strcmp(arregloPersonas[i].nombre, nombreABorrar) == 0)
        {
            printf("Nombre encontrado. \n");

            for(int j = i; j < *validos - 1; j++)
            arregloPersonas[i] = arregloPersonas[i+1];
            (*validos)--;
        }
        else
        {
            i++;
        }
    }

    return *validos;
}

//EJERCICIO 8.
void cargaDeMaterias(Materia mats[])
{
    for(int i = 0; i < 5; i++)
    {
        printf("Nombre de la materia: ");
        fflush(stdin);
        gets(mats[i].nombreMat);
        mats[i].codigo = i+1;
        printf("Codigo de la materia: %i\n", mats[i].codigo);
    }
}

void agregarUnAlumno(Alumno alus[], int indice)
{
    int i = indice;
    printf("Nombre: ");
    fflush(stdin);
    gets(alus[i].nombre);
    alus[i].matricula = i+1;
    printf("Matricula: %i\n", alus[i].matricula);
}

void cargarAlumnos(Alumno alus[], int* validos)
{
    int i = 0, cantAl = 0;

    printf("Cuantos datos desea ingresar?: \n");
    fflush(stdin);
    scanf("%i", &cantAl);

    for(i = 0; i < cantAl; i++)
    {
        agregarUnAlumno(alus, i);
        (*validos)++;
    }
}

void agregraUnNota(Nota notas[], Materia mats[], Alumno alus[], int validos)
{
    int i = 0, j = 0;
    int val = 0;

    printf("\nIngrese las notas respectivas: \n");

    for(i = 0; i < validos; i++)
    {
        printf("\nNotas del alumno %s: \n", alus[i].nombre);
        notas[j].matricula = alus[i].matricula;
        j = 0;

        while(j < 5)
        {
            printf("Nota final de %s: ", mats[j].nombreMat);
            fflush(stdin);
            scanf("%i", &notas[j].nota);
            notas[j].codigo = mats[j].codigo;
            j++;
        }

    }
}

void mostrarAlumnoYSusNotas(Nota notas[], Materia mats[], Alumno alus[], int validos)
{
    int i = 0, j = 0;
    char nombreABuscar[10];
    char continuar = 's';

    while(continuar == 's')
    {
        printf("\nIngrese el nombre a buscar: \n");
        fflush(stdin);
        gets(nombreABuscar);
        i = 0;

        bool nombreEncontrado = false;

         while(i < validos) //Para recorrer el arreglo de alumnos.
        {
            if(strcmp(alus[i].nombre, nombreABuscar) == 0)
            {
                printf("Nombre encontrado: %s\n", alus[i].nombre);
                nombreEncontrado = true;

                for(int j = 0; j < 5; j++) //Para recorrer los arreglos de materias y notas.
                {
                    printf("Materia: %s - ", mats[j].nombreMat);
                    printf("Nota final: %i\n", notas[j].nota);
                }
            }
              i++;
        }

        if(!nombreEncontrado)
        {
             printf("Nombre no encontrado. \n");
        }

        printf("Desea continuar?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
}
