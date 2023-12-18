#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 5

typedef struct
{
    int matricula;
    char nombre[30];
    char genero;

}stAlumnos;

int menuOpciones();
void menuEjecucion();
void cargaDeUnSoloAlumno(stAlumnos*,stAlumnos[],int);
int cargaAlumnos(stAlumnos[],int*);
void mostrarUnSoloAlumno(stAlumnos[],int);
void mostrarAlumnos(stAlumnos[],int);
int cargaAlumnos(stAlumnos[],int*);
int matriculaABuscar(int);
void busquedaXMat(stAlumnos[],int);
int buscarMenor(stAlumnos[],int,int);
void ordenacionSeleccion(stAlumnos[],int);
char generoAElegir(stAlumnos[],int);
void muestraXGen(stAlumnos[],int);
void cargaAlumnoOrdenado(stAlumnos*);
void insertarOrdenado(stAlumnos[],int,stAlumnos);
void mostrarAlumnosMasDato(stAlumnos[],int);
int cargaAlumnosXInsercion(stAlumnos[],int*);
void insercionOrdenada(stAlumnos[],int,stAlumnos);
int cantAlumnosXGenero(stAlumnos[],int);

int main()
{
    stAlumnos p;
    stAlumnos arregloAlumnos[TAM_MAX];
    int i = 0;
    int validos = 0;
    int mat = 0;
    char generoElegido;

    menuEjecucion();


}

//EJERCICIO 9
int menuOpciones()
{
    int opcion;
    printf("FOR EXERCISE 1 -> PRESS 1. \n");
    printf("FOR EXERCISE 2 -> PRESS 2. \n");
    printf("FOR EXERCISE 3 -> PRESS 3. \n");
    printf("FOR EXERCISE 4 -> PRESS 4. \n");
    printf("FOR EXERSICE 5 -> PRESS 5. \n");
    printf("FOR EXERCISE 6 -> PRESS 6. \n");
    printf("FOR EXERSICE 7 -> PRESS 7. \n");
    printf("FOR EXERCISE 8 -> PRESS 8. \n");
    scanf("%i",&opcion);

    return opcion;
}

void menuEjecucion()
{
    stAlumnos p, alumnoA;
    stAlumnos arregloAlumnos[TAM_MAX];
    int i;
    int validos;
    int mat;
    int sumaGen;
    char continuar;

    do
    {

        int opcion = menuOpciones();
        switch(opcion)
        {
        case 1:
            cargaAlumnos(arregloAlumnos,&validos);
            break;
        case 2:
            cargaAlumnos(arregloAlumnos,&validos);
            mostrarAlumnos(arregloAlumnos,validos);
            break;
        case 3:
            cargaAlumnos(arregloAlumnos,&validos);
            mostrarAlumnos(arregloAlumnos,validos);
            busquedaXMat(arregloAlumnos,validos);
            break;
        case 4:
            cargaAlumnos(arregloAlumnos,&validos);
            ordenacionSeleccion(arregloAlumnos,validos);
            mostrarAlumnos(arregloAlumnos,validos);
            break;
        case 5:
            cargaAlumnos(arregloAlumnos,&validos);
            muestraXGen(arregloAlumnos,validos);
            break;
        case 6:
            cargaAlumnos(arregloAlumnos,&validos);
            ordenacionSeleccion(arregloAlumnos,validos);
            mostrarAlumnos(arregloAlumnos,validos);
            cargaAlumnoOrdenado(&alumnoA);
            insertarOrdenado(arregloAlumnos,validos,alumnoA);
            mostrarAlumnosMasDato(arregloAlumnos,validos);
            break;
        case 7:
            cargaAlumnosXInsercion(arregloAlumnos,&validos);
            mostrarAlumnos(arregloAlumnos,validos);
            break;
        case 8:
            cargaAlumnos(arregloAlumnos,&validos);
            mostrarAlumnos(arregloAlumnos,validos);
            sumaGen = cantAlumnosXGenero(arregloAlumnos,validos);
            printf("La cantidad de alumnos del genero seleccionado es de: %i alumnos. \n\n",sumaGen);
            break;


        }

        printf("Desea continuar?: s/n \n");
        fflush(stdin);
        scanf("%c",&continuar);
        system("cls");

    }while(continuar == 's' || continuar == 'S');

}

//EJERCICIO 1
void cargaDeUnSoloAlumno(stAlumnos *p,stAlumnos arregloAlumnos[],int i)
{

    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(arregloAlumnos[i].nombre);
    printf("Ingrese la matricula: \n");
    scanf("%i", &arregloAlumnos[i].matricula);
    printf("Ingrese el genero: \n");
    fflush(stdin);
    scanf("%c", &arregloAlumnos[i].genero);
}

int cargaAlumnos(stAlumnos arregloAlumnos[],int* validos)
{
    char continuar;
    int i = 0;
    stAlumnos p;

    do
    {
        cargaDeUnSoloAlumno(&p,arregloAlumnos,i);
        i++;

        printf("Desea continuar?: s/n \n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    *validos = i;
    return *validos;
}

//EJERCICIO 2
void mostrarUnSoloAlumno(stAlumnos arregloAlumnos[],int i)
{
    printf("NOMBRE: %s \n", arregloAlumnos[i].nombre);
    printf("MATRICULA: %i \n", arregloAlumnos[i].matricula);
    printf("GENERO: %c \n\n", arregloAlumnos[i].genero);
}

void mostrarAlumnos(stAlumnos arregloAlumnos[],int validos)
{
    int i = 0;
    while(i < validos)
    {
        mostrarUnSoloAlumno(arregloAlumnos,i);
        i++;
    }
}

//EJERCICIO 3
int matriculaABuscar(int mat)
{
    printf("Que matricula desea buscar?: \n");
    scanf("%i", &mat);

    return mat;
}

void busquedaXMat(stAlumnos arregloAlumnos[],int validos)
{
    int mat = matriculaABuscar(mat);
    int i = 0;
    while(i < validos && arregloAlumnos[i].matricula != mat)
    {
        i++;
    }
    if(i == validos)
    {
        printf("No se ha encontrado la matricula en el arreglo. \n");
    }
    else
    {
        printf("Se ha encontrado la matricula en el arreglo en la posicion %i. \n", i);
    }
}

//EJERCICIO 4
int buscarMenor(stAlumnos arregloAlumnos[],int validos,int i)
{
    int posMenor = i;

    for(int j = i+1; j < validos; j++)
    {
         if(arregloAlumnos[posMenor].matricula > arregloAlumnos[j].matricula)
        {
            posMenor = j;
        }

    }

    return posMenor;
}

void ordenacionSeleccion(stAlumnos arregloAlumnos[],int validos)
{
    int j = 0 , posMenor = 0;
    stAlumnos aux[TAM_MAX];

    for(int i = 0; i < validos-1; i++)
    {
        posMenor = buscarMenor(arregloAlumnos,validos,i);
        aux[j] = arregloAlumnos[posMenor];
        arregloAlumnos[posMenor] = arregloAlumnos[i];
        arregloAlumnos[i] = aux[j];
    }
}

//EJERCICIO 5
char generoAElegir(stAlumnos arregloAlumnos[],int validos)
{
    char generoElegido;
    printf("De que genero desea saber los datos?: \n");
    fflush(stdin);
    scanf("%c",&generoElegido);
    return generoElegido;
}

void muestraXGen(stAlumnos arregloAlumnos[],int validos)
{
    int i = 0;
    char generoElegido = generoAElegir(arregloAlumnos,validos);

    while(i < validos)
    {
        if(arregloAlumnos[i].genero == generoElegido)
        {
            mostrarUnSoloAlumno(arregloAlumnos,i);
        }

        i++;
    }

}

//EJERCICIO 6
void cargaAlumnoOrdenado(stAlumnos* alumnoA)
{
    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets((*alumnoA).nombre);
    printf("Ingrese la matricula: \n");
    scanf("%i", &((*alumnoA).matricula));
    printf("Ingrese el genero: \n");
    fflush(stdin);
    scanf("%c", &((*alumnoA).genero));
}

void insertarOrdenado(stAlumnos arregloAlumnos[],int validos, stAlumnos alumnoA)
{

    int i = validos-1;

    while(i >= 0 && (arregloAlumnos[i].matricula > alumnoA.matricula))
    {
        arregloAlumnos[i+1] = arregloAlumnos[i];
        i--;
    }
    arregloAlumnos[i+1] = alumnoA;

}

void mostrarAlumnosMasDato(stAlumnos arregloAlumnos[],int validos)
{
    int i = 0;
    while(i < validos+1)
    {
        mostrarUnSoloAlumno(arregloAlumnos,i);
        i++;
    }
}

//EJERCICIO 7
int cargaAlumnosXInsercion(stAlumnos arregloAlumnos[],int* validos)
{
    char continuar;
    int i = 0;
    stAlumnos p;

    do
    {
        cargaAlumnoOrdenado(&p);
        insercionOrdenada(arregloAlumnos,i,p);
        i++;

        printf("Desea continuar?: s/n \n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while((continuar == 's' || continuar == 'S') && i < TAM_MAX);

    *validos = i;
    return *validos;
}

void insercionOrdenada(stAlumnos arregloAlumnos[],int validos,stAlumnos p)
{

    int i = validos-1;

    while(i >= 0 && (strcmpi(arregloAlumnos[i].nombre,p.nombre) > 0))
    {
        arregloAlumnos[i+1] = arregloAlumnos[i];
        i--;
    }
    arregloAlumnos[i+1] = p;

}

//EJERCICIO 8
int cantAlumnosXGenero(stAlumnos arregloAlumnos[],int validos)
{
    char generoElegido = generoAElegir(arregloAlumnos,validos);
    int i = 0, sumaGen = 0;

    while(i < validos)
    {
        if(arregloAlumnos[i].genero == generoElegido)
        {
            sumaGen++;
        }
       i++;
    }

    return sumaGen;
}
