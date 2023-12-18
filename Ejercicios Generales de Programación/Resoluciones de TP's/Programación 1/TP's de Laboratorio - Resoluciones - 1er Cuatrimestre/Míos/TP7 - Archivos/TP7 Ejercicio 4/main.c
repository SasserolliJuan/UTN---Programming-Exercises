#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;

}stAlumnos;

int cargaDeAlumnosEnArchivo(FILE* fp,stAlumnos* p,stAlumnos arregloAlumnos[],int* validos);
void mostrarArchivo(FILE fp,stAlumnos arregloAlumnos[],int validos);

int main()
{
    stAlumnos p;
    stAlumnos arregloAlumnos[10];
    FILE* fp;


}



