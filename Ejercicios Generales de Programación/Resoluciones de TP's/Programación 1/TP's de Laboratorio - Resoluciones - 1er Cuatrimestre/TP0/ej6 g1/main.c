#include <stdio.h>
#include <stdlib.h>

int main()
{
    int horastrabajadas=0, horasextra=0;
    float sueldo=0;
    printf("ingrese la cantidad de horas trabajadas:\n");
    scanf("%i", &horastrabajadas);
    if (horastrabajadas<=40)
        {
        sueldo= (float) horastrabajadas*300;
        } else
        {
            horasextra=horastrabajadas-40;
            sueldo= (float) 40*300+horasextra*400;
        }
    printf("el sueldo semanal del obrero sera de: %.2f", sueldo);
    return 0;
}
