#include <stdio.h>
#include <stdlib.h>

int busquedaBinaria(int arr[], int inicio, int fin, int valorBuscado) {
    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;

        if (arr[medio] == valorBuscado)
        {
            return medio;
        }
        else if (arr[medio] < valorBuscado)
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }

    return -1; // Elemento no encontrado
}

int main() {
    int arreglo[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    int valorBuscado = 5;

    int indice = busquedaBinaria(arreglo, 0, tamano - 1, valorBuscado);

    if (indice != -1) {
        printf("Elemento encontrado en el indice %d\n", indice);
    }
    else {
        printf("Elemento no encontrado\n");
    }

    return 0;
}
