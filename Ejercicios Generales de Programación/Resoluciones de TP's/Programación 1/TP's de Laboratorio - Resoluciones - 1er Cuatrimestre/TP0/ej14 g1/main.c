#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    float numerox=0, positivo=0;
    for (i=1;i<16;i++)
    {
        printf("ingrese numero a evaluar: ");
        scanf("%f", &numerox);
        if (numerox>=0)
        {
            printf("el numero ingresado es: %.2f \n", numerox);
        } else
        {
            positivo=numerox*(-1);
            printf("el numero ingresado convertido en positivo es: %.2f \n", positivo);
        }
    }


    return 0;
}
