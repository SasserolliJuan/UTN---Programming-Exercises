#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota1=0, promedio=0, suma=0;
    int conteo_notas=0;
    do
    {
    printf("ingrese nota a incluir en el promedio:\n");
    scanf("%f", &nota1);
    if (nota1>=0 && nota1<=10)
    {
        conteo_notas++;
        suma+=nota1;
        }
    }
    while (conteo_notas<7);
    promedio=suma/conteo_notas;
    printf("el promedio de las notas ingresadas es: %.2f\n", promedio);
    if (promedio>=7)
        {
        printf("ha aprobado la materia, es usted un pillo.\n");
    } else {
        printf("no ha aprobado la materia, mejor suerte el año proximo xD\n");
        }

    return 0;
}
