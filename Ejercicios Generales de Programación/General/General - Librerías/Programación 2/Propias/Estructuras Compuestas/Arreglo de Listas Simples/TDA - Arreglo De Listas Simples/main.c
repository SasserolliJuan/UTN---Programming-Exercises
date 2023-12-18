#include "Arreglo_De_Listas_Simples.h"

int main()
{
    celda arregloDeListas[20];
    char materia[30];

    int validos = ingresar_notas_al_arreglo(arregloDeListas, 20);

    printf("Ingrese la materia que desea mostrar: \n");
    fflush(stdin);
    scanf("%s", &materia);

    int pos = buscar_pos_materia(arregloDeListas, materia, validos);

    if(pos != -1)
    {
        mostrar_lista_simple(arregloDeListas[pos].lista);
    }

    return 0;
}
