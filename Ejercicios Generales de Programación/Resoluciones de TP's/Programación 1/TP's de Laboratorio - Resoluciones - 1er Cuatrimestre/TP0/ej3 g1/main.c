#include <stdio.h>
#include <stdlib.h>

int main()
{
    int totalH=0, totalM=0, total=0;
    float porcentajeH=0, porcentajeM=0;
    printf("ingrese total de hombres:\n");
    scanf("%i", &totalH);
    printf("ingrese total de mujeres:\n");
    scanf("%i", &totalM);
    total=totalH+totalM;
    porcentajeH=(float) totalH*100/total;
    porcentajeM=(float) totalM*100/total;
    printf("el porcentaje de hombres en el curso es: %2f %\n", porcentajeH);
    printf("el porcentaje de mujeres en el curso es: %2f %", porcentajeM);

    return 0;
}
