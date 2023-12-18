#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
     long int inversion=0;
    int tri=0;
    float rinde=0;
    printf("ingrese cantidad de dinero a invertir:\n");
    scanf("%Id", &inversion);
    printf("ingrese valor de la tasa de retorno a la inversion:\n");
    scanf("%i", &tri);
    rinde=inversion*tri/100;
    printf("el rendimiento es de:\n");
    printf("%2f", rinde);
    return 0;
}
