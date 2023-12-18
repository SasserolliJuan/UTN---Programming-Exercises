#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, cant_alumnos=10;
    float nota=0, minimo=9999, suma=0, promedio=0;
    do
    {
        printf("ingrese nota %i (del 1 al 10) a tener en cuenta: \n", i+1);
        scanf("%f", &nota);
        if (nota<minimo)
        {
            minimo=nota;
        }
        suma+=nota;
        i++;
    }
    while (i<cant_alumnos);
    promedio=suma/cant_alumnos;
    printf("el promedio de la clase es: %.2f \n", promedio);
    printf("la nota minima es: %.2f", minimo);
    return 0;
}
