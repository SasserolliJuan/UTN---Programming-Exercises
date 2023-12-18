#include <stdio.h>
#include <stdlib.h>

int cargaycuenta (int[]);

int main()
{
    int arreglo[100], validos=0;
    validos=cargaycuenta(arreglo[100]);
    printf("La cantidad de datos cargados en el arreglo es: %i \n", validos);
    return 0;
}

int cargaycuenta (int arreglo[])
{
    int resultado=0, i=0, flag=0;
    while (flag==0)
    {
        printf("ingrese elemento de arreglo:\n");
        scanf("%i", &arreglo[i]);
        i++;
        printf("Cargar otro dato? 0:si - 1:no \n");
        scanf("%i", &flag);
    }
    resultado=i;
    for (i=0; i<resultado; i++)
    {
        printf("| %i |", arreglo[i]);
    }
    printf("\n");
    return resultado;
}
