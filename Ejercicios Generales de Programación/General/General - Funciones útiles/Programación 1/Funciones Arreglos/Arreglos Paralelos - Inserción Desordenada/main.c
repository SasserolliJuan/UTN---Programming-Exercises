#include <stdio.h>
#include <stdlib.h>
#define MAX_ESTUDIANTES 100

int main() {
    int edades[MAX_ESTUDIANTES];
    int calificaciones[MAX_ESTUDIANTES];

    // Arreglos paralelos existentes
    edades[0] = 20;
    edades[1] = 22;
    edades[2] = 21;
    calificaciones[0] = 90;
    calificaciones[1] = 85;
    calificaciones[2] = 95;

    // Nuevo estudiante
    int nueva_edad = 19;
    int nueva_calificacion = 88;

    // Inserción desordenada
    int indice_insercion = 3;
    edades[indice_insercion] = nueva_edad;
    calificaciones[indice_insercion] = nueva_calificacion;

    // Mostrar los arreglos paralelos después de la inserción
    for (int i = 0; i < 4; i++) {
        printf("Edad: %d, Calificación: %d\n", edades[i], calificaciones[i]);
    }

    return 0;
}
