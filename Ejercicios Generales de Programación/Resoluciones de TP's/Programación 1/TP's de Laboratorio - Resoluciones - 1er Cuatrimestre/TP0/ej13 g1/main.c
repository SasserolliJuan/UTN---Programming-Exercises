#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, j=0;
    float numerox=0;
    do
    {
        printf("ingrese numero a evaluar: ");
        scanf("%f", &numerox);
        if (numerox>0)
        {
            printf("el numero ingresado %.2f es positivo \n", numerox);
            j++;
        }
        i++;
    }
    while (i<10);
    printf("Hay %i numeros positivos entre los 10", j);
    return 0;
}
